
#pragma once

#include <opencv2/core/core.hpp>

#include <vector>

#include <g3log/g3log.hpp>

#define BOOST_FILESYSTEM_NO_DEPRECATED
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;

#include "libvideoio/DataSource.h"

#include "liblazyquicktime.h"

namespace libvideoio {

class GoSource : public DataSource {
public:

  GoSource( );
  GoSource( const std::string &path );

  ~GoSource();

  bool open( const std::string &path );

  virtual int numFrames( void ) const;

  virtual int frameNum( void ) const;

  virtual bool grab( void );

  virtual int getImage( int i, cv::Mat &mat );

  virtual ImageSize imageSize( void ) const;

  bool isOpened() const;

protected:

  int _id;

  ImageBuffer _buffer;
  cv::Mat _latest;

  int _latestFrameNum;

};



}
