# include "vars.h"
# include "print.h"

int setup = false;

void BasicROInterface () 
{
	if (setup == true) { return; }

	setup = true;

	// set color
	print_set_raw_color(BasicKernelColor);
	print_clear();

	// print
	print_str(BasicKernelText);
	
	// print build info
	print_set_raw_color(BasicKernel_build_Color);
	print_str("\n\n");
	print_str(BasicKernelText_build);

}