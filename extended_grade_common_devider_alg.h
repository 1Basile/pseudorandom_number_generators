#ifndef EXTENDED_GRADE_COMMON_DEVIDER_ALG_IMMPORTED

#define EXTENDED_GRADE_COMMON_DEVIDER_ALG_IMMPORTED
// C function for extended Euclidean Algorithm 
int ext_gcd(int a, int b, int* x, int* y) 
{ 
    // Base Case 
    if (a == 0) { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = ext_gcd(b % a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b / a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
// Driver Program
/* int main() */
/* { */
    /* int x, y; */
    /* int a = 35, b = 15; */
    /* int g = ext_gcd(a, b, &x, &y); */
    /* printf("gcd(%d, %d) = %d\n", a, b, g); */
    /* printf("%d*%d + %d*%d = %d\n", a, x, b, y, g); */
    /* return 0; */
/* } */

#endif
