#ifndef CLContext_H
#define CLContext_H

#define __CL_ENABLE_EXCEPTIONS

#include <CL/cl.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class CLContext {
public:
	CLContext() = default;
	~CLContext() = default;
	int run();
};

#endif
