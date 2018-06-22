#ifndef LIB_H
#define LIB_H

#define __CL_ENABLE_EXCEPTIONS

#include <CL/cl.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class Lib {
public:
	Lib() = default;
	~Lib() = default;
	int run();
};

#endif
