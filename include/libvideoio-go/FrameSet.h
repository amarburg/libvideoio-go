
#pragma once

#include <opencv2/core.hpp>
#include <g3log/g3log.hpp>

#include "libvideoio-go/GoSource.h"
#include "libmovieset.h"

namespace libvideoio {

class FrameSet : public GoSource {
public:

  FrameSet( );
  FrameSet( const std::string &path );

  ~FrameSet();
  bool openFrameSet( const std::string &path );

  bool openChunk(const std::string &name);

protected:

  int _setId;

};



}
