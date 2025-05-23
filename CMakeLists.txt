cmake_minimum_required(VERSION 3.30)
project(wxMathPlot)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
option(WXMATHPLOT_COMPILE_EXECUTABLES "Compile executables" ON)

if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /RTC1")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
  add_compile_options(
    /W2  # /W[1-4] enables level 1-4 warnings,
    #/WX  # /WX treats warnings as errors
    # /permissive- # stricter standard compliance (more portable)
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  #-Wfloat-equal -Wundef -Wnon-virtual-dtor
  add_compile_options(
	  -Wall -Wpedantic -Wextra -Wconversion
	  -Werror
	  )
endif(MSVC)

find_package(wxWidgets REQUIRED COMPONENTS core base)

add_library(wxmathplot STATIC mathplot.cpp mathplot.h)

target_link_libraries(wxmathplot PUBLIC wxWidgets::wxWidgets)
target_include_directories(wxmathplot PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (WXMATHPLOT_COMPILE_EXECUTABLES)
  file(GLOB EXECUTABLES "main/*.cpp")
  foreach(exe_src IN LISTS EXECUTABLES)
    get_filename_component(exe_name ${exe_src} NAME_WE)
  
    add_executable(${exe_name}
      WIN32 # important in Windows GUI-based applications
      ${exe_src})
  
    target_link_libraries(${exe_name} wxmathplot)
    target_include_directories(${exe_name} PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}
      ${CMAKE_CURRENT_SOURCE_DIR}/lib
      )
  endforeach()
endif()
