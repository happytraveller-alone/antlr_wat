#include "WatFuzz.h"

// extern "C" {
// my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed);
// }
// extern "C" {
// size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf, size_t buf_size,
//                        u8 **out_buf, uint8_t *add_buf, size_t add_buf_size,
//                        size_t max_size);
// }
// extern "C" {
// size_t afl_custom_post_process(my_mutator_t *data, uint8_t *buf,
//                                size_t buf_size, uint8_t **out_buf);
// }
// extern "C" {
// void afl_custom_deinit(my_mutator_t *data);
// }

/**
 * Initialize this custom mutator
 *
 * @param[in] afl a pointer to the internal state object. Can be ignored for
 * now.
 * @param[in] seed A seed for this mutator - the same seed should always mutate
 * in the same way.
 * @return Pointer to the data object this custom mutator instance should use.
 *         There may be multiple instances of this mutator in one afl-fuzz run!
 *         Return NULL on error.
 */
extern "C" my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed) {

  srand(seed); // needed also by surgical_havoc_mutate()

  my_mutator_t *data =
      static_cast<my_mutator_t *>(calloc(1, sizeof(my_mutator_t)));
  if (!data) {
    perror("afl_custom_init alloc");
    return NULL;
  }

  if ((data->mutated_out = (u8 *)malloc(MAX_FILE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  if ((data->post_process_buf = (u8 *)malloc(MAX_FILE)) == NULL) {
    perror("afl_custom_init malloc");
    return NULL;
  }

  data->afl = afl;

  return data;
}

/**
 * Perform custom mutations on a given input
 *
 * (Optional for now. Required in the future)
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param[in] buf Pointer to input data to be mutated
 * @param[in] buf_size Size of input data
 * @param[out] out_buf the buffer we will work on. we can reuse *buf. NULL on
 * error.
 * @param[in] add_buf Buffer containing the additional test case
 * @param[in] add_buf_size Size of the additional test case
 * @param[in] max_size Maximum size of the mutated output. The mutation must not
 *     produce data larger than max_size.
 * @return Size of the mutated output.
 */
extern "C" size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf,
                                  size_t buf_size, u8 **out_buf,
                                  uint8_t *add_buf,
                                  size_t add_buf_size, // add_buf can be NULL
                                  size_t max_size) {
  // Make sure that the packet size does not exceed the maximum size expected by
  // the fuzzer
  size_t mutated_size = DATA_SIZE <= max_size ? DATA_SIZE : max_size;
  if (buf_size != 19) {
    return 0;
  }

  // fprintf(stdout, "\n buf %s | buf_size: %zu \n", buf, buf_size);
  u8 *temp_store = (u8 *)malloc((buf_size + 1) * sizeof(u8));
  memset(temp_store, 0, buf_size + 1);
  for (int i = 0; i < buf_size; ++i) {
    temp_store[i] = buf[i];
  }
  try {

    // std::this_thread::sleep_for(std::chrono::milliseconds(50));
    CustomStrVisitor *visitor = new CustomStrVisitor(temp_store, buf_size);
    if (visitor->get_parser()->getNumberOfSyntaxErrors() > 0) {
      free(temp_store);
      temp_store = nullptr;
      delete visitor;
      visitor = nullptr;
      *out_buf = nullptr;
      return 0;
    } else {
      try {
        visitor->visit(visitor->get_module());
        int rewriter_size = visitor->get_rewriter()->getText().size() + 1;
        memset(data->mutated_out, 0, rewriter_size);
        u8 uchr[rewriter_size];
        strncpy((char *)uchr, visitor->get_rewriter()->getText().c_str(),
                rewriter_size);
        uchr[rewriter_size - 1] = '\0';
        for (int i = 0; i < rewriter_size; ++i) {
          data->mutated_out[i] = uchr[i];
        }
        // data->mutated_out = uchr;
        if (mutated_size > max_size) {
          mutated_size = max_size;
        }
        // afl_realloc((void **)out_buf, mutated_size + 1);
        *out_buf = data->mutated_out;
        delete visitor;
        visitor = nullptr;
        // fprintf(stdout, "data->mutated_out : %s | rewriter_size : %d\n",
        //         data->mutated_out, rewriter_size);
      } catch (std::exception &e) {
        fprintf(stdout, "exception: %s\n", e.what());
        return 0;
      }
    }
  } catch (std::exception &e) {
    fprintf(stdout, "exception: %s\n", e.what());
    return 0;
  }
  return mutated_size;
}

/**
 * A post-processing function to use right before AFL writes the test case to
 * disk in order to execute the target.
 *
 * (Optional) If this functionality is not needed, simply don't define this
 * function.
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param[in] buf Buffer containing the test case to be executed
 * @param[in] buf_size Size of the test case
 * @param[out] out_buf Pointer to the buffer containing the test case after
 *     processing. External library should allocate memory for out_buf.
 *     The buf pointer may be reused (up to the given buf_size);
 * @return Size of the output buffer after processing or the needed amount.
 *     A return of 0 indicates an error.
 */
extern "C" size_t afl_custom_post_process(my_mutator_t *data, uint8_t *buf,
                                          size_t buf_size, uint8_t **out_buf) {

  if (buf_size > MAX_FILE) {
    buf_size = MAX_FILE;
  }
  // fprintf
  memcpy(data->post_process_buf, buf, buf_size);

  // data->post_process_buf[0] = 'A';
  // data->post_process_buf[1] = 'F';
  // data->post_process_buf[2] = 'L';
  // data->post_process_buf[3] = '+';
  // data->post_process_buf[4] = '+';
  afl_realloc((void **)out_buf, buf_size + 1);
  *out_buf = data->post_process_buf;

  return buf_size;
}

/**
 * Deinitialize everything
 *
 * @param data The data ptr from afl_custom_init
 */
extern "C" void afl_custom_deinit(my_mutator_t *data) {

  free(data->post_process_buf);
  free(data->mutated_out);
  // free(data->trim_buf);
  free(data);
}

/**
 * Determine whether the fuzzer should fuzz the queue entry or not.
 *
 * (Optional)
 *
 * @param[in] data pointer returned in afl_custom_init for this fuzz case
 * @param filename File name of the test case in the queue entry
 * @return Return True(1) if the fuzzer will fuzz the queue entry, and
 *     False(0) otherwise.
 */
extern "C" uint8_t afl_custom_queue_get(my_mutator_t *data,
                                        const uint8_t *filename) {

  return 1;
}

int main() {
  // visit
  // StrOverrideVisitor visitor;
  // CustomStrVisitor *visitor =
  //     new CustomStrVisitor("/home/xyf/antlr_wat/AFLplusplus_v4.09c/"
  //                          "custom_mutators/antlr4_test/input/seed1.txt");
  // visitor->visit(visitor->get_module());
  unsigned char *buf = (unsigned char *)malloc(20);
  memcpy(buf, "(12345)visit{efdgg}", 19);
  CustomStrVisitor *visitor2 = new CustomStrVisitor(buf, 19);
  // output tree
  // std::cout << visitor2->get_module()->toStringTree(visitor2->get_parser())
  //           << std::endl;
  visitor2->visit(visitor2->get_module());
  std::cout << visitor2->get_rewriter()->getText() << std::endl;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, 25);
  std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
  const std::string new_str = std::string(1, alphabet[dis(gen)]);
  fprintf(stdout, "random: %s\n", new_str.c_str());
  return 0;
}