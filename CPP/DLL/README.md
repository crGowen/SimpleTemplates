Simple implicit and explicit linking:

Implicit (AKA static lib) requires also giving out a .lib and .h files with the DLL file

Explicit linking is harder to code for on both ends, but doesn't require distributing the .h and .lib files

In most projects, it's much easier just to use a managed DLL system like in C#.


INCLUDING STATIC LIBS in a solution (for visual studio):

On Property Pages, go to C/C++->General->Additional Include Directories and provide the path, where the header file of the library that you want to use is located.

Then go to Linker->General->Additional Library Directories and specify the path, where your .lib file is located.

Finally, go to Linker->Input->Additional Dependencies and add the name of the file containing your library together with its extension (e.g. example_library.lib).


DYNAMIC LINKING: 

No including, load using LoadLibrary function with a relative filepath to the .dll file, and use the (slightly more unwieldy) explicit linking method.
