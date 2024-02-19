/*
    Challenge:
    Write a program that contains thef ollowing bit fields in a structure
   (onscreen box) -The box can be opaque or transparent -A fill color is
   selceted from the following pallets of colors: black, red, geren, yellow,
   blue, magenta, cyan, or white -Border can be shown or hidden -A border color
   is selected from the same pallet used for the fill color -A border can use
   one of three line styles - solid, dotted, or dashed

    Only need a single bit for:
        -box opacity
        -show border
    The eight possible color values can be represented by the eight possible
   values of a 3-bit unit. Eg: BLACK = 3 which is 0011 in binary, ergo 03 in
   octal could be assinged to this value for 011 -fill is 3-bit -border is 3-bit
    A two-bit unit is more than enough to represent the three possible border
   styles. -0 ia solid, 1 is dotted, 2 is dashed styled

    Total 10 bits
    Padding is required to bring it up to 16 bits


    Create struct and initialize bitfields with default values
        -> display default values

    Modify the stctures by accessig each bitfield and changing the default value
   to another value -display the new value

*/

#include <stdio.h>
#include <stdbool.h>

const char *style[3] = {"solid", "dotted", "dashed"};
const char *color[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

enum Color {
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE,
};

enum Style { SOLID, DOTTED, DASHED };

typedef struct{

  bool opaque : 1;
  unsigned short fill_color : 3;
  unsigned short :4;
  bool show_border : 1;
  unsigned short border_color : 3;
  unsigned short border_style : 2;
} OnscreenBox;


int printBox(const OnscreenBox *ob);

int main() {

    OnscreenBox ob1 = {.opaque=true, .fill_color=YELLOW, .show_border=true, .border_color=GREEN, .border_style = DASHED};

    printBox(&ob1);

    ob1.opaque = false;
    ob1.fill_color = WHITE;
    ob1.show_border = 0;
    ob1.border_color = MAGENTA;
    ob1.border_style = SOLID;

    printf("\n");
    printBox(&ob1);

  return 0;
}


int printBox(const OnscreenBox *ob){
    printf("Original box settings:\n"
           "Box is %s.\n"
           "The fill color is %s.\n"
           "Border %s.\n"
           "The border color is %s.\n"
           "The border style is %s.\n",
           ob->opaque ? "opaque" : "transparent",
           color[ob->fill_color],
           ob->show_border ? "shown" : "not shown",
           color[ob->border_color],
           style[ob->border_style]);

    return 0;
}
