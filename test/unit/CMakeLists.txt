
file( GLOB UNIT_TEST_SRCS *_test.cpp )

gtest_begin(videoio-go)
  fips_files(
    ${UNIT_TEST_SRCS}
  )

  fips_deps(videoio-go fips-googletest)

  fips_libs( ${Boost_LIBRARIES} )

gtest_end()

add_dependencies(videoio-go videoio-go-testdata)
