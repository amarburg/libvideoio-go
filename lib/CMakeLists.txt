

fips_begin_module( videoio_go )
  file(GLOB VIDEOIO_GO_SRCS *.cpp )

  fips_files(
    ${VIDEOIO_GO_SRCS}
  )

  fips_deps( videoio )

  fips_libs( ${OpenCV_LIBS} lazyquicktime )

  fips_include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
  )
fips_end_module()

add_dependencies(videoio_go liblazyquicktime)
