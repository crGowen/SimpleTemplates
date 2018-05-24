
// FIRST THINGS FIRST (Visual Studio):
// Add include directory to properties path for the include folder (in NVIDIA GPU Compute)
// Add 'OpenCL.lib' to the linker>Input>libraries
// Add the path to lib/x64 to the linker>general additional directories

// OpenCLtesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CL\cl.hpp"


int main()
{
	// first part to find all platforms.
	std::vector<cl::Platform> all_platforms;
	cl::Platform::get(&all_platforms);
	if (all_platforms.size() == 0) {
		std::cout << " No platforms found. Check OpenCL installation!\n";
		exit(1);
	}
	cl::Platform default_platform = all_platforms[0];
	//we have at least one platform, let's work with it
	std::cout << "Using platform: " << default_platform.getInfo<CL_PLATFORM_NAME>() << "\n";
	// in my case, the device is NVIDIA CUDA.
	std::cout << all_platforms.size() << " devices found.\n";
	// pause and keep the window open... there's a way more elegant way to do this but CBA :p
	char c;
	std::cin >> c;
    return 0;
}

