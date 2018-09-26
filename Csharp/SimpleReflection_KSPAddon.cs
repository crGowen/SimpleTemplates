using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Reflection;

namespace Test
{
    class Program
    {
        static void Main(string[] args)
        {
            Assembly assembly = Assembly.LoadFrom("UnifiedRealism_WIP.dll");
            Type[] types = assembly.GetTypes();

            foreach (Type type in types)
            {
                Console.WriteLine(type.Name);
                foreach (object attr in type.GetCustomAttributes(true))
                {
                    Console.WriteLine("\tCustom Attribute: " + attr.ToString());
                }
                MethodBase[] methods = type.GetMethods();
                foreach (MethodBase method in methods)
                {
                    Console.WriteLine("\tMethod: " + method.Name);
                    foreach (object attr in method.GetCustomAttributes(true))
                    {
                        Console.WriteLine("\t\tCustom Attribute: " + attr.ToString());
                    }
                    
                }
                Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}
