#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21

//headband typedef

typedef enum{
    BLUE,
    RED,
    PURPLE,
    ORANGE,
} HeadbandColor;

//create a typedef for a new Turtle struct
typedef struct{
    char name[MAX_LENGTH + 1];
    char weapon[MAX_LENGTH + 1];
    HeadbandColor headbandColor;
} Turtle;


Turtle *createTurtle(const char *name, const char *weapon, const HeadbandColor hbColor){
    Turtle *t = malloc(sizeof(Turtle));

    if(t == NULL){
        printf("failed to allocate memory for Turtle\n");
        exit(EXIT_FAILURE);
    }

    t->headbandColor = hbColor;
    //strncpy(t->name, name, MAX_LENGTH);
    //strncpy(t->weapon, weapon, MAX_LENGTH);

    strlcpy(t->name, name, MAX_LENGTH);
    strlcpy(t->weapon, weapon, MAX_LENGTH);

    return t;
}

int main()
{

    Turtle *michaelangelo = createTurtle("Michaelangelo", "nunchucks", ORANGE);

    printf("Hello %s!\n", michaelangelo->name);

    free(michaelangelo);
    return 0;
}
