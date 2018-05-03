
#pragma once

#include <opencv2/core.hpp>
#include <g3log/g3log.hpp>

#include "liblazyquicktime.h"

namespace libvideoio {

class FrameSet {
public:

  FrameSet( );
  FrameSet( const std::string &path );

  ~FrameSet();
  bool open( const std::string &path );

protected:

  int _id;

};



}
