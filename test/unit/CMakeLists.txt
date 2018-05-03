
file( GLOB UNIT_TEST_SRCS *_test.cpp )

gtest_begin(videoio_go NO_TEMPLATE)
  fips_files(
    ${UNIT_TEST_SRCS}
    main.cpp
  )

  fips_deps(videoio_go)

  fips_libs( ${Boost_LIBRARIES} )

gtest_end()

add_dependencies(videoio_go videoio_go_testdata)
