#include "WatFuzz.h"

typedef struct my_mutator {

  afl_state_t *afl;

  // any additional data here!
  //   size_t trim_size_current;
  //   int trimmming_steps;
  //   int cur_step;

  u8 *mutated_out;
  u8 *post_process_buf;
  // u8 *trim_buf;

} my_mutator_t;

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
                       size_t add_buf_size, // add_buf can be NULL
                       size_t max_size) {

  // Make sure that the packet size does not exceed the maximum size expected by
  // the fuzzer
  size_t mutated_size = DATA_SIZE <= max_size ? DATA_SIZE : max_size;

  memcpy(data->mutated_out, buf, buf_size);

  // Perform the mutation
  ANTLRInputStream stream((char *)data->mutated_out);
  StrLexer lexer(&stream);
  CommonTokenStream tokens(&lexer);
  StrParser parser(&tokens);
  StrParser::ModuleContext *tree;
  // tree = parser.module();

  if (mutated_size > max_size) {
    mutated_size = max_size;
  }

  *out_buf = data->mutated_out;
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
size_t afl_custom_post_process(my_mutator_t *data, uint8_t *buf,
                               size_t buf_size, uint8_t **out_buf) {

  if (buf_size + 5 > MAX_FILE) {
    buf_size = MAX_FILE - 5;
  }

  memcpy(data->post_process_buf + 5, buf, buf_size);
  data->post_process_buf[0] = 'A';
  data->post_process_buf[1] = 'F';
  data->post_process_buf[2] = 'L';
  data->post_process_buf[3] = '+';
  data->post_process_buf[4] = '+';

  *out_buf = data->post_process_buf;

  return buf_size + 5;
}

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
  CustomStrVisitor *visitor =
      new CustomStrVisitor("/home/xyf/antlr_wat/AFLplusplus_v4.09c/"
                           "custom_mutators/antlr4_test/input/seed1.txt");
  // visitor->visit(visitor->get_module());

  // output tree
  std::cout << visitor->get_module()->toStringTree(visitor->get_parser())
            << std::endl;
  visitor->visit(visitor->get_module());
  std::cout << visitor->get_rewriter()->getText() << std::endl;
  return 0;
}