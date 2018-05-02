
#include <string>

#include <opencv2/imgproc.hpp>

#include "libvideoio-go/GoSource.h"

namespace libvideoio {

using std::string;


GoSource::GoSource( void )
: _id(-1)
{
}

GoSource::GoSource( const std::string &path )
: _id(-1)
{
  open(path);
}

GoSource::~GoSource()
{
  if( _id >= 0 ) {
    CloseFrameSource(_id);
  }

}

bool GoSource::open( const std::string &path )
{
  // Well isn't this ugly..
  std::vector<char> chars(path.c_str(), path.c_str() + path.size() + 1u);
  _id = OpenFrameSource( &chars[0] );

  return (_id >= 0);
}


int GoSource::numFrames( void ) const {

  return -1;

  // if( isOpened() )
  //   return GoSourceNumFrames(_id);
  // else
  //   return -1;

}

int GoSource::frameNum( void ) const {
  return -1; //GoSourceFrameNum(_id);
}

bool GoSource::grab( void ) {
   if( FrameSourceNext( _id, &_buffer ) > 0 ) {
    cv::Mat mat( _buffer.height, _buffer.width, CV_MAKETYPE(_buffer.depth, _buffer.channels), _buffer.data );

    // Doing this a priori now ... need to make it configurable (?)_
    cv::cvtColor( mat, _latest, cv::COLOR_BGR2RGB );
    return true;
  }

  return false;
}

int GoSource::getImage( int i, cv::Mat &mat ) {
    // Only left
    if( i == 0 ) {
      //
      mat = _latest;
      return 0;
    }

    return -1;
}

ImageSize GoSource::imageSize( void ) const {
  return ImageSize();
}

bool GoSource::isOpened() const {
  return _id >= 0;
}

}
