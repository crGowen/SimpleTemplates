// ExplicitLinking.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "windows.h"
#include <string>
#include <iostream>

typedef double (*funcAdd)(double, double);

HINSTANCE SimpleLoadLib(std::wstring target);
void SimpleFreeLib(HINSTANCE& hDLL);
bool CheckLibLoaded(HINSTANCE& hDLL);
double CallTempLibAdd(HINSTANCE& hDLL, double a, double b);

int main()
{
	std::wstring tempDLL = L"TemplateLibrary";
	HINSTANCE MyDLL = SimpleLoadLib(tempDLL);
	if (CheckLibLoaded(MyDLL))
	{
		std::cout << "Library was successfully loaded! Continuing!\n";
		double res = CallTempLibAdd(MyDLL, 5.1, 5.2);
		std::cout << res << "\n";
		SimpleFreeLib(MyDLL);
	}
	else
	{
		std::cout << "Library failed to load. Nothing done.\n";
	}
    return 0;
}

double CallTempLibAdd(HINSTANCE& hDLL, double a, double b)
{  
	double dReturnVal;
	if (CheckLibLoaded(hDLL))
	{
		funcAdd Add = (funcAdd)GetProcAddress(hDLL, "Add");
		/*
		Without Typedef:
			double (*Add)(double, double) = (double (*)(double, double))GetProcAddress(hDLL, "Add"); ??
		*/
		if (NULL != Add)
		{
			// call the function  
			dReturnVal = Add(a, b);
		}
		else
		{
			// report the error 
			// ERROR_DELAY_LOAD_FAILED
			dReturnVal = 0.1;
		}
	}
	else
	{
		//ERROR_DELAY_LOAD_FAILED
		dReturnVal = 0.2;
	}
	return dReturnVal;
}

HINSTANCE SimpleLoadLib(std::wstring target)
{
	HINSTANCE hDLL;               // Handle to DLL  	
	hDLL = LoadLibrary(target.c_str());
	return hDLL;
}

void SimpleFreeLib(HINSTANCE& hDLL)
{	
	if (CheckLibLoaded(hDLL))
	{
		FreeLibrary(hDLL);
		std::cout << "Library freed!\n";
	}
	else
	{
		std::cout << "Library is not loaded, cannot free it!\n";
		return;
	}
}

bool CheckLibLoaded(HINSTANCE& hDLL)
{
	if (NULL == hDLL) return false;
	else return true;
}

