Static/Implicit is not fit for distribution and is compiled into a project at load-time. (Also not technically DLL so it shouldn't be in this folder, but whatever)

Explicit linking is harder to code for on both ends, but allows being distributed as a DLL file.

In most projects, it's much easier just to use a managed DLL system like in C#.


# INCLUDING STATIC LIBS in a solution (for visual studio):

On Property Pages, go to C/C++->General->Additional Include Directories and provide the path, where the header file of the library that you want to use is located.

Then go to Linker->General->Additional Library Directories and specify the path, where your .lib file is located.

Finally, go to Linker->Input->Additional Dependencies and add the name of the file containing your library together with its extension (e.g. example_library.lib).


# DYNAMIC LINKING: 

No including, load using LoadLibrary function with a relative filepath to the .dll file, and use the (slightly more unwieldy) explicit linking method. There is implicit dynamic linking too, where a .lib file is used to show declarations for a .dll, enabling it to be used more like a static library, however this will load all functions at runtime.

For performance it's better to just use explicit linking, it really isn't that much harder just to use interop-boundary safe variables and load functions with GetProcAddress.
