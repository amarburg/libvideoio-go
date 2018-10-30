
#pragma once

#include <opencv2/core.hpp>

#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include "libvideoio/ImageSource.h"
#include "libmovieset.h"

namespace libvideoio {

class GoSource : public ImageSource {
public:

  GoSource( );
  GoSource( const std::string &path );

  ~GoSource();

  bool open( const std::string &path );

  virtual int numFrames( void ) const;

  virtual int frameNum( void ) const;

  void setSkip( int skip ) { _skip = skip; }

  virtual bool grab( void );

  virtual int getRawImage( int i, cv::Mat &mat );

  virtual ImageSize imageSize( void ) const;

  bool isOpened() const;

  virtual int cvtToRGB() { return cv::COLOR_BGRA2RGB; }
  virtual int cvtToGray() { return cv::COLOR_BGRA2GRAY; }

protected:

  int _id;

  ImageBuffer _buffer;
  cv::Mat _latest;

  int _latestFrameNum;
  int _skip;

};



}
