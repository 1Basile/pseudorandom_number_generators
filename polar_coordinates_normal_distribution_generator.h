#ifndef POLAR_COORDINATES_NORMAL_DISTRIBUTION_GENERATOR_IMPORTED

#define POLAR_COORDINATES_NORMAL_DISTRIBUTION_GENERATOR_IMPORTED
#include "linear_congruential_generator.h"
#include <math.h>
#include <stdio.h>

// #define pol_coord_n_rand(...) pol_coord_n_rand_predef((inner_func_params_with_pointers_t){__VA_ARGS__})

#ifndef inner_func_params_with_pointers_t_defined
#define inner_func_params_with_pointers_t_defined
typedef struct {
  unsigned char normalize;
  double *x_1_p;
  double *x_2_p;
} inner_func_params_with_pointers_t;
#endif

void pol_coord_n_rand_base(unsigned char to_normalize, double *x_1_p, double *x_2_p) {
  double u_1, u_2, v_1, v_2, s;

  do {
   u_1 = lcg_rand_norm();
   u_2 = lcg_rand_norm();
   v_1 = 2*u_1 - 1;
   v_2 = 2*u_2 - 1;
   s = (v_1 * v_1) + (v_2 * v_2);
  } while( s >= 1 );

  *x_1_p = v_1 * sqrt((-2*log(s) / s));
  *x_2_p = v_2 * sqrt((-2*log(s) / s));
}

void pol_coord_n_rand(double *x_1_p, double *x_2_p) {
  double u_1, u_2, v_1, v_2, s;

  do {
   u_1 = lcg_rand_norm();
   u_2 = lcg_rand_norm();
   v_1 = 2*u_1 - 1;
   v_2 = 2*u_2 - 1;
   s = (v_1 * v_1) + (v_2 * v_2);
  } while( s >= 1 );

  *x_1_p = v_1 * sqrt(((-2*log(s)) / s));
  *x_2_p = v_2 * sqrt(((-2*log(s)) / s));
}
// Function wallper
void pol_coord_n_rand_predef(inner_func_params_with_pointers_t in){
  double x_ext;
  unsigned char normalize = in.normalize ? in.normalize : 0;
  double * x_2_p = in.x_2_p ? in.x_2_p : &x_ext;
  double * x_1_p = in.x_1_p ? in.x_1_p : &x_ext;
  pol_coord_n_rand_base(normalize, x_1_p, x_2_p);
}

#endif

