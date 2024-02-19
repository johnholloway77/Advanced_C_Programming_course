/*
Example:
An unsigned integer is being used to store five data values.
    1,2, & 3 are y/n flags (1 bit each),
    4 is a type value between 0 & 255 (8 bit)
    5 is an index value between 0 & 100000 (28 bit)

Total required bits is 29, meaning the integer will have 3 bits padding at the
beginning.

    | 000 | 000 | 00000000 | 000000000000000000 |
      pad  flags   type            index

*/

#include <stdio.h>

struct packed_struct {

    unsigned int : 3; // padding of three bits
    unsigned int f1 : 1;
    unsigned int f2 : 1; // three ints for the three flags
    unsigned int f3 : 1;
    unsigned int type : 8; //8 bits for type value
    unsigned int index : 18; //18 bits for index value;

};

int main() {

    struct packed_struct packed_data;
    packed_data.type = 7;
    packed_data.index = 29000;

    //get the

  printf("Hello World!\n");
  return 0;
}
