# wxMathPlot library

This is a fork of the original `wxMathPlot` library, a framework for mathematical graph plotting in wxWidgets.

# Compilation

## Linux

```shell
cmake -B build -DCMAKE_BUILD_TYPE=[Debug|Release]
cmake --build build
```

# Examples

After compilation, the examples can be run simply doing:

```shell
./build/main_<example>
```

The source code is located in the `main/` folder.

# Integration with other code

## CMake

When using CMake, locate the library in an internal directory of your project like `lib/wxMathPlot/` and then on your `CMakeLists.txt` add:

```cmake
add_subdirectory(lib/wxMathPlot)

target_link_libraries(application
   wxWidgets::wxWidgets
   wxmathplot
   ... # other libraries
)
```

This will link your application against `wxMathPlot`.

# Contact

- gagiuntoli@gmail.com
