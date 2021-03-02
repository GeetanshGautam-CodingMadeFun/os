#include "print.h"

# define True 1
# define False 0

char* BasicKernelText = "Base 64 Kernel Test\n\nBy: Geetansh G,\nCoding Made Fun, 2021";
uint8_t BasicKernelColor = PRINT_COLOR_BLACK + (PRINT_COLOR_LIGHT_GRAY << 4);

char* BasicKernelText_build = "Build ";
uint8_t BasicKernel_build_Color = PRINT_COLOR_WHITE + (PRINT_COLOR_BLACK << 4);

uint8_t WarningColor = PRINT_COLOR_WHITE + (PRINT_COLOR_RED << 4);

uint8_t buildRow = NUM_ROWS-3;
