#ifndef QUADRATIC_CONGRUENTIAL_GENERATOR_IMPORTED

#define QUADRATIC_CONGRUENTIAL_GENERATOR_IMPORTED

double qcg_rand(void) {
  static unsigned long int step = 11;
  static const unsigned int a = 85;
  static const unsigned int c = 139;
  static const unsigned int m = 3539;
  static const unsigned int d = 252; /* 0, 84, 252, 336, 504, 588, 756, 840 */
  step = ((d*step*step) * (a*step) + c) % m;
  return (double)step;
}

double qcg_rand_norm(void) {
  static unsigned long int step = 11;
  static const unsigned int a = 85;
  static const unsigned int c = 139;
  static const unsigned int m = 3539;
  static const unsigned int d = 252; /* 0, 84, 252, 336, 504, 588, 756, 840 */
  step = ((d*step*step) * (a*step) + c) % m;
  return (double)step / (double)m;
}

double qcg_rand_base(unsigned char to_normalize) {
  static unsigned long int step = 7;
  static const unsigned int a = 84589;
  static const unsigned int c = 45989;
  static const unsigned int m = 217728;
  static const unsigned int d = 84; /* 0, 84, 252, 336, 504, 588, 756, 840 */
  step = ((d*step*step) * (a*step) + c) % m;
  return to_normalize == 1 ? (double)step / (double)m : (double)step;
}
// #define qcg_rand(...) qcg_rand_predef((inner_func_params_t){__VA_ARGS__})

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

// Function wallper
double qcg_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return qcg_rand_base(normalize);
}



#endif
