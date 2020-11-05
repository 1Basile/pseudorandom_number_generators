#ifndef FIBONACCI_NUMBER_GENERATOR_IMPORTED
# define FIBONACCI_NUMBER_GENERATOR_IMPORTED

// #define fib_next_num(...) fib_next_num_predef((inner_func_params_t){__VA_ARGS__})

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

double fib_next_num_base(unsigned char to_normalize) {
  static unsigned long int m = 5323;
  static unsigned long int prev_step = 0;
  static unsigned long int curr_step = 1;
  static unsigned long int next_step;
  next_step = (curr_step + prev_step) % m;
  prev_step = curr_step;
  curr_step = next_step;
  return to_normalize == 1 ? (double)next_step / (double)m : (double)next_step;
}
double fib_next_num_norm(void) {
  static unsigned long int m = 5323;
  static unsigned long int prev_step = 0;
  static unsigned long int curr_step = 1;
  static unsigned long int next_step;
  next_step = (curr_step + prev_step) % m;
  prev_step = curr_step;
  curr_step = next_step;
  return (double)next_step / (double)m;
}

double fib_next_num(void) {
  static unsigned long int m = 5323;
  static unsigned long int prev_step = 0;
  static unsigned long int curr_step = 1;
  static unsigned long int next_step;
  next_step = (curr_step + prev_step) % m;
  prev_step = curr_step;
  curr_step = next_step;
  return  (double)next_step;
}
// Function wallper
double fib_next_num_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return fib_next_num_base(normalize);
}

#endif
