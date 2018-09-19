
fips_begin_module( videoio_go )

  fips_files(
    GoSource.cpp
    FrameSet.cpp
  )

  fips_deps( videoio )

  fips_libs( ${OpenCV_LIBS} movieset )
  fips_include_directories( ${CMAKE_CURRENT_SOURCE_DIR} )

fips_end_module()


## Custom targets to build Golang extension
add_custom_command(
	TARGET videoio_go
	#OUTPUT ${GO_LIBRARY}
  PRE_BUILD
	COMMAND go get github.com/amarburg/cgo-movieset
	COMMAND cd ${GOPATH}/src/github.com/amarburg/cgo-movieset/ && make
)

# add_dependencies(videoio_go libmovieset)
