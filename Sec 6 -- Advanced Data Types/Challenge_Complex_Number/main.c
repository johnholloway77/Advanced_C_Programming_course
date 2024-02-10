/* Challenge 3
 *
 *  Create a double complex number with the imaginary number squared using the
 * multiplication Operator ( I * I ) and display the output of the real and
 * imaginary numbers
 *
 *  Create a double complex number with the imaginary number squared using the
 * pow function from the math library and display the output of the real and
 * imaginary numbers
 *
 *  Create a double that performs Euler's formula
 *  PI = acos(-1)
 *  the complex number is the exponent of I * PI
 *  display the output of the real number and the imaginary number
 *
 *  create a double complex number that performs as a conjugate
 *      a complex number that is 1+2*I
 *      a complex number that is 1-2*I
 *      Display the output of the real and imaginary number
 */

#include <complex.h>
#include <math.h>
#include <stdio.h>

// tell the compiler to include library extension
#define __STDC_WANT_LIB_EXT1__ 1

int main() {

  /*
   *  Create a double complex number with the imaginary number squared using the
   * multiplication Operator ( I * I ) and display the output of the real and
   * imaginary numbers
   */

  double complex c1 = 15.34 + 4.3I;
  // double complex c1sq = c1 * c1;
  printf("1. c1 = %.2f%+.2fi and c1 * c1 = %.2f%+.2fi\n", creal(c1), cimag(c1),
         creal(c1 * c1), cimag(c1 * c1));

  /*  Create a double complex number with the imaginary number squared using the
   * pow function from the math library and display the output of the real and
   * imaginary numbers
   */

  double complex c1sq = pow(c1, 2);
  printf("2. c1 = %.2f%+.2fi and clsq = %.2f%+.2fi\n", creal(c1), cimag(c1),
         creal(c1sq), cimag(c1sq));

  /*
   *  Create a double that performs Euler's formula
   *  PI = acos(-1)
   *  the complex number is the exponent of I * PI
   *  display the output of the real number and the imaginary number
   */

  double PI = acos(-1);
  double complex eul = exp(I * PI);
  printf("3. Euler's forumal is %.1f%+.1fi\n", creal(eul), cimag(eul));

  /*  create a double complex number that performs as a conjugate
      a complex    number that is 1 + 2 * I
      a complex number that is 1 - 2 * I
      Display the output of the real and imaginary number
  */

  double complex c2 = 1 + 2 * I;
  double complex c3 = 1 - 2 * I;
  double complex cconj2 = conj(c2);
  double complex cconj3 = conj(c3);
  printf("4. The conjugate of c2 = %.2f%+.2fi\n", creal(c2 * c3),
         cimag(c2 * c3));

  return 0;
}
