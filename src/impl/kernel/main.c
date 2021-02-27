# include "print.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
	print_clear(); // sets the whole screen to the colors described above.
	print_str("64-bit Kernel Base\n\nCoding Made Fun, 2021\nBy: Geetansh G.");
}