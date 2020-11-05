#ifndef REVERSE_CONGRUENTIAL_GENERATOR_IMPORTED

#define REVERSE_CONGRUENTIAL_GENERATOR_IMPORTED
#include "mod_inverse_alg.h"

double rcg_rand_base(unsigned char to_normalize) {
  static unsigned int a = 69;
  static unsigned int c = 4358;
  static unsigned int p = 91193; 
  static unsigned int step = 1; 
  step = mod_inverse(step, p);
  step = (a*step + c) % p;
  return to_normalize == 1 ? (double)step / (double)p : (double)step;
}

/* #define rcg_rand(...) rcg_rand_predef((inner_func_params_t){__VA_ARGS__}) */

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

// Function wallper
double rcg_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return rcg_rand_base(normalize);
}


double rcg_rand(void) {
  static unsigned int a = 69;
  static unsigned int c = 4358;
  static unsigned int p = 91193; 
  static unsigned int step = 1; 
  step = mod_inverse(step, p);
  step = (a*step + c) % p;
  return  (double)step;
}

double rcg_rand_norm(void) {
  static unsigned int a = 69;
  static unsigned int c = 4358;
  static unsigned int p = 91193; 
  static unsigned int step = 1; 
  step = mod_inverse(step, p);
  step = (a*step + c) % p;
  return (double)step / (double)p;
}
#endif
