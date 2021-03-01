# include "print.h"
# include "vars.h"

void kernel_main()
{
	
	print_set_raw_color(BasicKernelColor);
	print_clear(); // sets the whole screen to the colors described above.
	print_str(BasicKernelText);

}
