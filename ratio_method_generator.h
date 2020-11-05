#ifndef RATIO_METHOD_GENERATOR_IMPORTED

#define RATIO_METHOD_GENERATOR_IMPORTED
#include "linear_congruential_generator.h"
#include <math.h>

// #define rat_rand(...) rat_rand_predef((inner_func_params_t){__VA_ARGS__})

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

double rat_rand_base(unsigned char to_normalize) {
  double u, v, x;
  do {
      do {
        u = lcg_rand_norm();
      } while ( u == 0 );
      
       v = lcg_rand_norm();
      
       x = sqrt(((double)8 / exp(1))) * ((v - 0.5) / u);

      if (x*x <= 5 - 4*exp(0.25)*u) { return x; }
  } while ( x*x >= (4*exp(-1.35) / u) + 1.4 || x*x > -4*log(u));

  return x;
}
double rat_rand(void) {
  double u, v, x;
  do {
      do {
        u = lcg_rand_norm();
      } while ( u == 0 );
      
       v = lcg_rand_norm();
      
       x = sqrt(((double)8 / exp(1))) * ((v - 0.5) / u);

      if (x*x <= 5 - 4*exp(0.25)*u) { return x; }
  } while ( x*x >= (4*exp(-1.35) / u) + 1.4 || x*x > -4*log(u));

  return x;
}

// Function wallper
double rat_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return rat_rand_base(normalize);
}

#endif
