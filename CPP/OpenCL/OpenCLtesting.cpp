// OpenCLtesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CL\cl.hpp"


int main()
{
	std::vector<cl::Platform> all_platforms;
	cl::Platform::get(&all_platforms);
	if (all_platforms.size() == 0) {
		std::cout << " No platforms found. Check OpenCL installation!\n";
		exit(1);
	}
	cl::Platform default_platform = all_platforms[0];
	std::cout << "Using platform: " << default_platform.getInfo<CL_PLATFORM_NAME>() << "\n";
	std::cout << all_platforms.size() << " devices found.\n";
	char c;
	std::cin >> c;
    return 0;
}

