cmake_minimum_required(VERSION 3.5)
if( NOT FIPS_IMPORT )
	get_filename_component(FIPS_ROOT_DIR "../fips" ABSOLUTE)
	include("${FIPS_ROOT_DIR}/cmake/fips.cmake")

	fips_setup(PROJECT libvideoio-go)
endif()


find_package( Boost COMPONENTS system REQUIRED)

# C++ flags applied to all builds
# squelch int-in-bool-context warnings from eigen
set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wno-int-in-bool-context")

## Configure OpenCV ##
set( OPENCV_COMPONENTS core imgproc )
find_package(OpenCV COMPONENTS ${OPENCV_COMPONENTS} REQUIRED)


# Find the Go library
set( GOPATH $ENV{GOPATH} )
set( GOLIB_PATH ${GOPATH}/src/github.com/amarburg/cgo-movieset )

# ## Set global include paths
fips_include_directories(
 	${CMAKE_CURRENT_SOURCE_DIR}/include
	${CMAKE_CURRENT_SOURCE_DIR}/thirdparty
	$ENV{GOPATH}/src/github.com/amarburg/cgo-movieset
)

link_directories(
	$ENV{GOPATH}/src/github.com/amarburg/cgo-movieset
)

set( GO_HEADER  ${GOLIB_PATH}/libmovieset.h )
set( GO_LIBRARY ${GOLIB_PATH}/libmovieset.so )
message( ${GO_HEADER} )


## Custom targets to build Golang extension
add_custom_command(
	OUTPUT ${GO_LIBRARY}
  PRE_BUILD
	COMMAND go get github.com/amarburg/cgo-movieset
	COMMAND cd ${GOPATH}/src/github.com/amarburg/cgo-movieset/ && make
)

add_custom_target(libmovieset
  DEPENDS ${GO_LIBRARY}
)


# 	${CMAKE_CURRENT_SOURCE_DIR}/third_party
#   ${OpenCV_INCLUDE_DIRS}
# 	${TINYXML2_INCLUDE_DIR}
# 	${EIGEN3_INCLUDE_DIR} )
# include_directories( ${VIDEOIO_INCLUDE_DIRS}

fips_add_subdirectory("lib/")

if( NOT FIPS_IMPORT )
	set( TEST_DATA_DIR "${CMAKE_CURRENT_SOURCE_DIR}/test/data" )
	add_definitions( -DTEST_DATA_DIR="${TEST_DATA_DIR}" )

	fips_add_subdirectory("tools/")

	if( FIPS_UNITTESTS )
		message("** Will run unit tests")
	  fips_add_subdirectory( test/ )
	endif()

	fips_finish()
endif()
