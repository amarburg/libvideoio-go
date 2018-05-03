

fips_begin_module( videoio_go )

  fips_files(
    GoSource.cpp
    FrameSet.cpp
  )

  fips_deps( videoio )

  fips_libs( ${OpenCV_LIBS} lazyquicktime )

  fips_include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

fips_end_module()

add_dependencies(videoio_go liblazyquicktime)
