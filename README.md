# BasicOpenGLProject with CMake
## Understanding CMake
First take a look at the directory structure and where the CMakeLists.txt's are.
```
project_root
├───freeglut
│   ├───bin
│   │   └───x64
│   ├───include
│   │   └───GL
│   └───lib
│       └───x64
├───CMakeLists.txt [project root CMakeLists]
├───inc
├───src
│   ├───CMakeLists.txt [actual CMakeLists]

```

All that the project root `CMakeLists.txt` does is initialize the project name,
some environment variables, and find out weather it's 64 bit or not. The real 
magic happens in the `CMakeLists.txt` under `src`, it's where the project gets
built. In src, we add all of our source files `*.cpp`, and give them to the
compiler. We also need to add the libraries and the include path. That's what
this one does. If you're curious read them and the comments say what each line
does. 

## What you need to know.
If you need to make another source file, `*.cpp`, dont `#include` it in main.
Include a header that has all of the function definitions in a `*.h` file in the
`inc` directory, then add the `*.cpp` file in the sources list at the top of
`src/CMakeLists.txt`
