#include "stdio.h"
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GRAY 7
#define DARK_GRAY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define YELLOW 14
#define WHITE 15

#define VIDEO_MEMORY_ADDRESS 0xB8000

int main()
{
  clear_screen();
  put_string("Hello World",0,0,WHITE);
  for (int i = 0; i < 3999999; i++)
  {
    volatile;
    //THE AI DID NOT CREATE THIS FOR LOOP, I DONT KNOW HOW TO MAKE A DELAY YET
  }
  
    clear_screen();
    put_string("Welcome to Cool OS", 0, 0, LIGHT_CYAN);
    put_string("Press any key to do absolutley nothing!",0,1,WHITE);
    return 0;
}