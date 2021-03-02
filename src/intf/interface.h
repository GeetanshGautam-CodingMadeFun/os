# include "vars.h"
# include "print.h"
# include <stdbool.h>

int setup = False;

void BasicInfoInterface(char* buildID)
{
	if (setup == True) { return; }

	setup = True;

	// Set BG Color
	print_set_raw_color(BasicKernelColor);
	print_clear();

	// Build Info - Bars
	for (uint8_t i = buildRow; i < NUM_ROWS; i++) {
		print_highlight_row(i, false, true, BasicKernel_build_Color);
	}

	// Kernel Info - Text
	print_set_coords(0, 0);
	print_set_raw_color(BasicKernelColor);
	print_str(BasicKernelText);

	// Build Info - Text
	print_set_coords(0, buildRow);
	print_set_raw_color(BasicKernel_build_Color);
	print_str(BasicKernelText_build);
	
	print_set_coords(0, buildRow + 1);
	print_str(buildID);

	// "Error" bar
	print_set_raw_color(WarningColor);

	print_highlight_row(NUM_ROWS - 1, false, true, WarningColor);

	print_set_coords(0, NUM_ROWS - 1);

	print_str("Fatal: This screen does not have an input.");

}