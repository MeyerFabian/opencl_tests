#include "../lib/subfolder/lib.h"
int main(void)
{
	Lib* opencl = new Lib();
	opencl->run();
	delete opencl;
	return 0;
}
