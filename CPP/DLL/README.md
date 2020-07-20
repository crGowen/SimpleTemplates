Two types of linking: Static and dynamic (dynamic is broken up into implicit and explicit linking).

Static is not fit for distribution and is put into the .exe at compile-time. (Also not technically DLL so it shouldn't be in this folder, but whatever). 

Implicit dynamic is very similar to static, but isn't inserted in at compile time - instead at load-time. It is very slightly harder to use but is better for large projects since fixing a bug in the library simply requires redistributing .dll and .lib files, whereas static requires redistributing the .exe.

Explicit dynamic is the next step up and is inserted at run-time. This is best one resource-wise because you can load and unload what is needed whereever you want them. It also allows you to load .dll's that you might not know the name until run-time (i.e. their names are stored in data files or specified by the user).

For packaging the installation: in static libs everything is compiled into the .exe file and that is all you distribute (.lib and .h are used to bake the code into the .exe). For dynamic libs you only need to distribute the .dll file (in the case of implicit linking, .lib and .h are used to bake .dll calls into the .exe file).


# INCLUDING STATIC LIBS in a solution (for visual studio):

On Property Pages, go to C/C++->General->Additional Include Directories and provide the path, where the header file of the library that you want to use is located.

Then go to Linker->General->Additional Library Directories and specify the path, where your .lib file is located.

Finally, go to Linker->Input->Additional Dependencies and add the name of the file containing your library together with its extension (e.g. example_library.lib).

# IMPLICIT DYNAMIC LINKING

Exactly the same as for static libraries but with ONE EXTRA STEP:

Add a resource/reference to the .dll file (also tick 'make local copy' if appropriate).

Also be sure to use dllexport/dllimport declarations for functions that need to be exposed, otherwise it will not work.

# DYNAMIC LINKING: 

No including, load using LoadLibrary function with a relative filepath to the .dll file, and use the (slightly more unwieldy) explicit linking method. Remember to use interop-boundary safe variables if needed, and load functions with GetProcAddress.
