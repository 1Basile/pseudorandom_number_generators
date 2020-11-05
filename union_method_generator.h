#ifndef UNINON_METHOD_GENERATOR_IMPORTED
#define UNINON_METHOD_GENERATOR_IMPORTED
#include "linear_congruential_generator.h"
#include "quadratic_congruential_generator.h"

/* #define un_rand(...) un_rand_predef((inner_func_params_t){__VA_ARGS__}) */

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

double un_rand_base(unsigned char to_normalize) {
  unsigned int m = 217728;  // Module from lcg_rand
  unsigned int x_n = lcg_rand();
  unsigned int y_n = qcg_rand();

  return to_normalize == 1 ? (double)((x_n - y_n) % m) / (double)m : (double)((x_n - y_n) % m);
}

// Function wallper
double un_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return un_rand_base(normalize);
}

double un_rand(void) {
  unsigned int m = 217728;  // Module from lcg_rand
  unsigned int x_n = rcg_rand();
  unsigned int y_n = qcg_rand();

  return  (double)((x_n - y_n) % m);
}

double un_rand_norm(void) {
  unsigned int m = 217728;  // Module from lcg_rand
  unsigned int x_n = lcg_rand();
  unsigned int y_n = qcg_rand();

  return  (double)((x_n - y_n) % m) / (double)m;
}
#endif
