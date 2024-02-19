#include <stdio.h>

struct point{
    int x;
    int y;
};

int main()
{
    //array initializers

    int num[100] = {[5 ... 9] = 10, [10] = 20, [11 ... 16] = -3};
    for(int i = 0; i < 20; i++){
        printf("%d\n", num[i]);
    }

    //structure initializes

    struct point p = { .y = 2, .x =3};
    struct point p2 = { y: 2, x: 3};
    struct point p3 = {2, 3}; //if done without specifying the
    return 0;
}
