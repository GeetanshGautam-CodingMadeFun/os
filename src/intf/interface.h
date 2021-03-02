# include "vars.h"
# include "print.h"

int setup = false;

void BasicInfoInterface(char* buildID)
{
	if (setup == true) { return; }

	setup = true;

	//set color
	print_set_raw_color(BasicKernelColor);
	print_clear();

	// bar
	print_set_coords(0, buildRow);
	print_set_raw_color(BasicKernel_build_Color);
	for (uint8_t i = 0; i <= NUM_COLS*2; i++) {
		print_str(" ");
	}

	// kernel info
	print_set_coords(0, 0);
	print_set_raw_color(BasicKernelColor);
	print_str(BasicKernelText);

	// build info
	print_set_coords(0, buildRow);
	print_set_raw_color(BasicKernel_build_Color);
	print_str(BasicKernelText_build);
	
	print_set_coords(0, buildRow + 1);
	print_str(buildID);

	// msg
	print_set_raw_color(WarningColor);
	print_set_coords(0, NUM_ROWS-1);
	for (uint8_t i = 0; i <= NUM_COLS; i++) {
		print_str(" ");
	}
	print_set_coords(0, NUM_ROWS - 1);
	print_str("Fatal: This screen does not have an input.");

}