#include "WatFuzz.h"



extern "C" {my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed);}
extern "C" {size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf,
                                  size_t buf_size, u8 **out_buf,
                                  uint8_t *add_buf, size_t add_buf_size,
                                  size_t max_size);}
extern "C" {size_t afl_custom_post_process(my_mutator_t *data, uint8_t *buf,
                                          size_t buf_size, uint8_t **out_buf);}
extern "C" {void afl_custom_deinit(my_mutator_t *data);}




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
my_mutator_t *afl_custom_init(afl_state_t *afl, unsigned int seed) {

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
size_t afl_custom_fuzz(my_mutator_t *data, uint8_t *buf, size_t buf_size,
                       u8 **out_buf, uint8_t *add_buf,
                       size_t add_buf_size,  // add_buf can be NULL
                       size_t max_size) {
  // Make sure that the packet size does not exceed the maximum size expected by
  // the fuzzer
  size_t mutated_size = DATA_SIZE <= max_size ? DATA_SIZE : max_size;
  int    mutated_out_size = buf_size <= add_buf_size ? buf_size : add_buf_size;
  memset(data->mutated_out, 0, mutated_out_size);
  // memcpy(data->mutated_out, buf, mutated_out_size);
  // fprintf(stdout, "buffer size: %zu \t buffer size: %zu \t add buffer size:
  // %zu \t buffer: %s \t add_buffer: %s \t mutated_size: %d\n", \
  //           buf_size, buf_size, add_buf_size, buf, add_buf,
  //           mutated_out_size);
  // fprintf(stdout, "data->mutated_out: %s\n", reinterpret_cast<const
  // char*>(buf)); count buf size
  int buf_count = 0;
  for (int i = 0; i < buf_size; i++) {
    if (buf[i] == '\n' || buf[i] == '\0') { break; }
    buf_count++;
  }
  try {
    if (buf_count != 19) { return 0; }
    // fprintf(stdout, "\n buf %s\n", buf);
    // std::this_thread::sleep_for(std::chrono::milliseconds(50));
    CustomStrVisitor *visitor = new CustomStrVisitor(buf, mutated_out_size);
    if (visitor->get_parser()->getNumberOfSyntaxErrors() > 0) {
      delete visitor;
      visitor = nullptr;
      return 0;
    } else {
      try {
        visitor->visit(visitor->get_module());
        u8 uchr[visitor->get_rewriter()->getText().size() + 1];
        std::strcpy((char *)uchr, visitor->get_rewriter()->getText().c_str());
        uchr[visitor->get_rewriter()->getText().size()] = '\0';

        data->mutated_out = uchr;

        delete visitor;
        visitor = nullptr;
        fprintf(stdout, "rewriter mutate: %s length: %zu\n", uchr,strlen((char *)uchr));
        if (mutated_size > max_size) { mutated_size = max_size; }
        afl_realloc((void **)out_buf, mutated_size + 1);
        *out_buf = data->mutated_out;
      } catch (std::exception &e) {
        fprintf(stdout, "exception: %s\n", e.what());
        return 0;
      }
      // visitor->visit(visitor->get_module());
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
// size_t afl_custom_post_process(my_mutator_t *data, uint8_t *buf,
//                                size_t buf_size, uint8_t **out_buf) {

//   if (buf_size > MAX_FILE) {
//     buf_size = MAX_FILE;
//   }
//   // fprintf
//   memcpy(data->post_process_buf, buf, buf_size);

//   // data->post_process_buf[0] = 'A';
//   // data->post_process_buf[1] = 'F';
//   // data->post_process_buf[2] = 'L';
//   // data->post_process_buf[3] = '+';
//   // data->post_process_buf[4] = '+';

//   *out_buf = data->post_process_buf;

//   return buf_size;
// }

/**
 * Deinitialize everything
 *
 * @param data The data ptr from afl_custom_init
 */
void afl_custom_deinit(my_mutator_t *data) {

  free(data->post_process_buf);
  free(data->mutated_out);
  // free(data->trim_buf);
  free(data);

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
  std::random_device              rd;
  std::mt19937                    gen(rd());
  std::uniform_int_distribution<> dis(0, 25);
  std::string                     alphabet = "abcdefghijklmnopqrstuvwxyz";
  const std::string               new_str = std::string(1, alphabet[dis(gen)]);
  fprintf(stdout, "random: %s\n", new_str.c_str());
  return 0;
}