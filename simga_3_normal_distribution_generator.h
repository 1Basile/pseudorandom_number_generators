#ifndef SIGMA_3_NORMAL_DISTRIBUTION_GENERATOR_IMPORTED

#define SIGMA_3_NORMAL_DISTRIBUTION_GENERATOR_IMPORTED
#include "linear_congruential_generator.h"
#include "./quadratic_congruential_generator.h"

/* #define sig_3_n_rand(...) sig_3_n_rand_predef((inner_func_params_t){__VA_ARGS__}) */

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

double sig_3_n_rand_base(unsigned char to_normalize) {
  double menian = 0;
  double variance = 1;
  
  double sum = 0;
  unsigned char i; 
  for (i=1;i<13;i++) { sum += lcg_rand_norm(); } // Get sum of 12 random normalized values

  return menian + (sum - (double)6)*variance;
}

// Function wallper
double sig_3_n_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return sig_3_n_rand_base(normalize);
}

double sig_3_n_rand(void) {
  double menian = 0;
  double variance = 1;
  double sum = 0;
  unsigned char i; 
  for (i=1;i<13;i++) { sum += lcg_rand_norm(); } // Get sum of 12 random normalized values

  return menian + (sum - (double)6)*variance;
}
#endif
