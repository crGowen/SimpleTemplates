﻿// FIRST THINGS FIRST (Visual Studio):
// Add include directory to properties path for the include folder (in NVIDIA GPU Compute, which includes all the OpenCL stuff needed!)
// Add 'OpenCL.lib' to the linker>Input>libraries
// Add the path to lib/x64 to the linker>general additional directories

// OpenCLtesting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "CL\cl.hpp"
#include <fstream>

const int AR_SIZE = 150;


int main()
{
	// first part to find all platforms.
	std::vector<cl::Platform> all_platforms;
	cl::Platform::get(&all_platforms);
	if (all_platforms.size() == 0)
	{
		std::cout << " No platforms found.\n";
		exit(1);
	}
	std::cout << all_platforms.size() << " platforms found.\n";
	cl::Platform default_platform = all_platforms[0];
	// we have at least one platform, let's work with it
	std::cout << "Using platform: " << default_platform.getInfo<CL_PLATFORM_NAME>() << "\n";
	// in my case, the platform is NVIDIA CUDA.

	std::vector<cl::Device> all_devices;
	default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);
	if (all_devices.size() == 0)
	{
		std::cout << "No devices found.\n";
		exit(1);
	}
	std::cout << all_devices.size() << " devices found.\n";
	cl::Device default_device = all_devices[0];
	std::cout<< "Using device: " << default_device.getInfo<CL_DEVICE_NAME>() << "\n";
	// in my case, the device is a NVIDIA GTX card.

	// create context and prepare source code link
	cl::Context context({ default_device });
	cl::Program::Sources sources;

	// get source (openCL C) code
	std::ifstream CLfile("kernelcode.cl");
	std::string line;
	std::string inputCode = "";
	if (CLfile.is_open())
	{
		std::cout << "File opened.\n";
		while (std::getline(CLfile, line))
		{
			inputCode = inputCode + line + "\n";
		}
		CLfile.close();
		std::cout << "File read successful.\n";
	}
	else
	{
		std::cout << "File not opened.\n";
		exit(1);
	}

	// push the source code to sources object
	sources.push_back({ inputCode.c_str(),inputCode.length() });
	std::cout << "Source generated.\n";

	// build the program, here we go!
	cl::Program program(context, sources);
	if (program.build({ default_device }) != CL_SUCCESS)
	{
		std::cout << "Program build unsuccessful: " << program.getBuildInfo<CL_PROGRAM_BUILD_LOG>(default_device) << "\n";
		exit(1);
	}
	std::cout << "Program built.\n";

	// create queue to push commands to device
	cl::CommandQueue queue(context, default_device);

	// prepare memory - This isn't actually needed for the test function, at least
	cl::Buffer buffer_A(context, CL_MEM_READ_WRITE, sizeof(int) * AR_SIZE); //prepare a buffer of size int Arr[10]
	cl::Buffer buffer_B(context, CL_MEM_READ_WRITE, sizeof(int) * AR_SIZE); //prepare a buffer of size int Arr[10]
	cl::Buffer buffer_C(context, CL_MEM_READ_WRITE, sizeof(int) * AR_SIZE); //prepare a buffer of size int Arr[10]
	cl::Kernel test_func(program, "test_func");
	test_func.setArg(0, buffer_A);
	test_func.setArg(1, buffer_B);
	
	// Set up NDrange for number of calls!
	cl::NDRange global(AR_SIZE);
	cl::NDRange local(10);
	queue.enqueueNDRangeKernel(test_func, cl::NullRange, global, local);

	int *A = new int[AR_SIZE];
	queue.enqueueReadBuffer(buffer_A, CL_TRUE, 0, AR_SIZE * sizeof(int), A);
	int *B = new int[AR_SIZE];
	queue.enqueueReadBuffer(buffer_B, CL_TRUE, 0, AR_SIZE * sizeof(int), B);

	
	// should execution structure
	std::cout << "\n";
	for (int i = 0; i < AR_SIZE; i++)
	{
		std::cout << "GlobalID: " << i << "\tGroupID: " << A[i] << "\tLocalID: " << B[i] << "\n";
	}

	// pause and keep the window open... there's a way more elegant way to do this but CBA :p
	char c;
	std::cin >> c;
	return 0;
}

