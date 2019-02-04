
## Load the test data in Go
add_custom_target(videoio-go-testdata
  COMMAND go get -d github.com/amarburg/go-lazyfs-testfiles
)

fips_include_directories( . )
add_definitions( -DLIBVIDEOIO_GO_TEST_DATA_DIR="${GOPATH}/src/github.com/amarburg/go-lazyfs-testfiles/")

fips_add_subdirectory( unit/ )
