cmake_minimum_required (VERSION 3.0)

set (CMAKE_CXX_STANDARD 14)

set (Python_ADDITIONAL_VERSIONS 3)
find_package (PythonLibs REQUIRED)
find_package (PythonInterp REQUIRED)

include_directories ("${PYTHON_INCLUDE_DIRS}")

add_library (core SHARED
  "${CMAKE_SOURCE_DIR}/src/core.cpp"
  )

set_target_properties (core PROPERTIES PREFIX "")
set_target_properties (core PROPERTIES OUTPUT_NAME "_core")

if (WIN32)
  set_target_properties (core PROPERTIES SUFFIX ".pyd")
else()
  set_target_properties (core PROPERTIES SUFFIX ".so")
endif()

target_link_libraries (core "${PYTHON_LIBRARIES}")
