# 测试程序
add_executable(test_strutils
  test_string_utils.c
)
target_link_libraries(test_strutils
  strutils
  cmocka
)

add_test(NAME test_strutils COMMAND test_strutils)

# 代码覆盖率
if(CMAKE_BUILD_TYPE MATCHES Coverage)
  include(CodeCoverage)
  append_coverage_compiler_flags()
  setup_target_for_coverage_lcov(
    NAME coverage
    EXECUTABLE ctest -j ${PROCESSOR_COUNT}
    DEPENDENCIES test_strutils
  )
endif()  