#pragma once

//Template Library2 HAS NO CLASSES OR NAMESPACES TO MAKE EXPLICIT LINKING EASIER!

#ifdef TEMPLATE_EXPORTS
#define TEMPLATE_API __declspec(dllexport)
#else
#define TEMPLATE_API __declspec(dllimport)
#endif

extern "C"
{
	double TEMPLATE_API Add(double a, double b);
}

