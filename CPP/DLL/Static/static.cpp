﻿// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TemplateLibrary.h"
#include <iostream>


int main()
{
	double a = 12.3;
	double b = 14.2;
	
	std::cout << "a + b = " <<
		TemplateLibrary::Functions::Add(a, b) << std::endl;
		return 0;
}
