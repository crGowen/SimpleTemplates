#pragma once

#ifdef TEMPLATE_EXPORTS
#define TEMPLATE_API __declspec(dllexport)
#else
#define TEMPLATE_API __declspec(dllimport)
#endif

namespace TemplateLibrary
{
	class Functions
	{
	public:
		static TEMPLATE_API double Add(double a, double b);
	};
}
