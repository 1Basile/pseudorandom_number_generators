#ifndef LOG_METHOD_FOR_EXPONENTIAL_DISTRIBUTION_GENERATOR_IMPORTED

#define LOG_METHOD_FOR_EXPONENTIAL_DISTRIBUTION_GENERATOR_IMPORTED
#include "linear_congruential_generator.h"
#include <math.h>

// #define log_exp_rand(...) log_exp_rand_predef((inner_func_params_t){__VA_ARGS__})

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

double log_exp_rand_base(unsigned char to_normalize) {
  double u = lcg_rand_norm();
  double mu = 9; // Random constant
  return -mu*log(u);
}

double log_exp_rand(void) {
  double u =  lcg_rand_norm();
  double mu = 9; // Random constant
  return -mu*log(u);
}


// Function wallper
double log_exp_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return log_exp_rand_base(normalize);
}

#endif
