#include <complex.h>
#include <stdio.h>

#define __STDC_WANT_LIB_EXT1__                                                 \
  1 // tells the compiler that we want specific extensions to the C library

int main() {
#ifdef __STDC_NO_COMPLEX__
  printf("Complex arithmetic not supported\n");
#else
  printf("Complex numbers supported!\n");

  double complex cx = 1.0 + 4.0 * I;
  double complex cy = 1.0 - 5.0 * I;

  double complex cxy = cy + cy;

  printf("Working with complex numbers:\n");
  printf("Starting values: cx= %.2f%+.2fi  cy = %.2f%+.2fi\n", creal(cx),
         cimag(cx), creal(cy), cimag(cy));
  printf("Sum of the cx + cy = %.2f%+.2fi\n", creal(cxy), cimag(cxy));

#endif

  return 0;
}
