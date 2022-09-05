add_library(CalculatorFunctions functions.cxx)

target_include_directories(CalculatorFunctions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          )

install(TARGETS CalculatorFunctions DESTINATION lib)
install(FILES CalculatorFunctions.h DESTINATION include)
