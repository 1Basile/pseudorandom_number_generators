#ifndef ARENSA_METHOD_FOR_GAMMA_DISTRIBUTION_GENERATOR_IMPORTED

#define ARENSA_METHOD_FOR_GAMMA_DISTRIBUTION_GENERATOR_IMPORTED
#include "linear_congruential_generator.h"
#include <math.h>

// #define arensa_gamma_rand(...) arensa_gamma_rand_predef((inner_func_params_t){__VA_ARGS__})

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

double arensa_gamma_rand(void) {
  double u, y, x, v;
  static double a = 3;

StartOfTheLoop:do {
    u = lcg_rand_norm();
    y = tan(M_PI*u);
    x = sqrt(2*a - 1)*y + a - 1;
    if ( x <= 0 ) { goto StartOfTheLoop; }
    v = lcg_rand_norm();
  } while ( v > (1 + y*y)*exp( (a - 1)*log(x/(a - 1)) - sqrt(2*a - 1)*y ));
  return  x;
}

double arensa_gamma_rand_base(unsigned char to_normalize) {
  double u, y, x, v;
  static double a = 3;

  do {
    u = lcg_rand_norm();
    y = tan(M_PI*u);
    x = sqrt(2*a - 1)*y + a - 1;
    if ( x <= 0 ) { continue; }
    v = lcg_rand_norm();
  } while ( v > (1 + y*y)*exp( (a - 1)*log(x/(a - 1)) - sqrt(2*a - 1)*y ));
  return  x;
}

// Function wallper
double arensa_gamma_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return arensa_gamma_rand_base(normalize);
}

#endif
