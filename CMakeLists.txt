cmake_minimum_required(VERSION 3.23)
project(wxMathPlot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(WXMATHPLOT_COMPILE_EXECUTABLES "Compile executables" ON)

find_package(wxWidgets REQUIRED COMPONENTS core base)

include(${wxWidgets_USE_FILE})

add_library(wxmathplot STATIC mathplot.cpp mathplot.h)

target_link_libraries(wxmathplot PUBLIC ${wxWidgets_LIBRARIES})

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    #-Wconversion -Wfloat-equal -Wundef -Wnon-virtual-dtor
    target_compile_options(wxmathplot PRIVATE -Wall -Wpedantic -Wextra -Werror)
endif()

target_include_directories(wxmathplot PUBLIC ${wxWidgets_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})

set(EXECUTABLE_SOURCES 
    samples/sample1/mp1.cpp
    samples/sample2/mp2.cpp
    samples/sample3/mp3.cpp
)

if (WXMATHPLOT_COMPILE_EXECUTABLES)
    foreach(exe_src IN LISTS EXECUTABLE_SOURCES)
        get_filename_component(exe_name ${exe_src} NAME_WE)
        add_executable(${exe_name} ${exe_src})
        target_link_libraries(${exe_name} wxmathplot)
    endforeach()
endif()
