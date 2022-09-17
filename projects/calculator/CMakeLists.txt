cmake_minimum_required(VERSION 3.14)

project(Calculator VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# should we use our own math functions
option(USE_CALCULATOR "Use Calculator provided math implementation" ON)

configure_file(CalculatorConfig.h.in CalculatorConfig.h)

# add the MathFunctions library
if(USE_CALCULATOR)
  add_subdirectory(CalculatorFunctions)
  list(APPEND EXTRA_LIBS CalculatorFunctions)
endif()

add_executable(Calculator main.cxx)

target_link_libraries(Calculator PUBLIC ${EXTRA_LIBS})

target_include_directories(Calculator PUBLIC "${PROJECT_BINARY_DIR}")

install(TARGETS Calculator DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/CalculatorConfig.h"
  DESTINATION include
  )

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Calculator_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Calculator_VERSION_MINOR}")
set(CPACK_SOURCE_GENERATOR "TGZ")
include(CPack)
