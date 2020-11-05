#ifndef MOD_INVERSE_ALG_IMPORTED

#include "extended_grade_common_devider_alg.h"
#define MOD_INVERSE_ALG_IMPORTED
// Function to find modulo inverse of a 
int mod_inverse(int a, int m) 
{ 
    int x, y; 
    int g = ext_gcd(a, m, &x, &y); 
    if (g != 1) 
       return -1; //  Error: it`s impossible to find inverse value, -1 not in [0, m-1] so impossible value
    else
    { 
        // m is added to handle negative x 
        int res = (x%m + m) % m; 
        return res;
    } 
} 

// Driver Program

/* int main(void) { */
  /* int a = 3; */
  /* int b = 7; */
  /* printf("Mod invers of %d by %d is %d", a, b, mod_inverse(a, b)); */
  /* return 0; */
/* } */

#endif
