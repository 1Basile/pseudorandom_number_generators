#ifndef LINEAR_CONGRUENTIAL_GENERATOR_IMPORTED
#define LINEAR_CONGRUENTIAL_GENERATOR_IMPORTED

double lcg_rand_base(unsigned char to_normalize) {
  static unsigned long int step = 1;
  static const unsigned int a = 84589;
  static const unsigned int c = 45989;
  static const unsigned int m = 217728;
  step = (a * step + c) % m;
  return to_normalize == 1 ? (double)step / (double)m : (double)step;
}

double lcg_rand(void) {
  static unsigned long int step = 1;
  static const unsigned int a = 84589;
  static const unsigned int c = 45989;
  static const unsigned int m = 217728;
  step = (a * step + c) % m;
  return (double)step;
}
 
double lcg_rand_norm(void) {
  static unsigned long int step = 1;
  static const unsigned int a = 84589;
  static const unsigned int c = 45989;
  static const unsigned int m = 217728;
  step = (a * step + c) % m;
  return (double)step / (double)m; 
}

// #define lcg_rand(...) lcg_rand_predef((inner_func_params_t){__VA_ARGS__})

#ifndef inner_func_params_t_defined
#define inner_func_params_t_defined
typedef struct {
  unsigned char normalize;
} inner_func_params_t;
#endif

// Function wallper
double lcg_rand_predef(inner_func_params_t in){
  unsigned char normalize = in.normalize ? in.normalize : 0;
  return lcg_rand_base(normalize);
}


#endif
