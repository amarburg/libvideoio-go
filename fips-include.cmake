set( GOPATH $ENV{GOPATH} )
set( GOLIB_PATH ${GOPATH}/src/github.com/amarburg/cgo-movieset )

link_directories(
	$ENV{GOPATH}/src/github.com/amarburg/cgo-movieset
)
