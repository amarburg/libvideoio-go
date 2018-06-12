
fips_begin_app( player cmdline )
  fips_files(
    Player.cpp
  )

  fips_deps( videoio_go videoio )

  fips_include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
  )

  fips_libs( ${Boost_LIBRARIES} )

fips_end_app()
