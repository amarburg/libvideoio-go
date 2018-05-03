
#include <string>
#include <iostream>

#include "libvideoio-go/FrameSet.h"

namespace libvideoio {

using std::string;
using namespace std;

FrameSet::FrameSet( void )
  : GoSource(), _setId(-1)
{
}

FrameSet::FrameSet( const std::string &path )
  : GoSource(), _setId(-1)
{
  openFrameSet(path);
}

FrameSet::~FrameSet()
{
  if( _setId >= 0 ) CloseFrameSet(_id);
}

bool FrameSet::openFrameSet( const std::string &path )
{
  // Well isn't this ugly...
  auto chars = strdup( path.c_str() );
  _setId = OpenFrameSet( chars );
  free(chars);

  if (_setId < 0) {
    return false;
  }

  // Also open it as a FrameSource
  _id = FrameSourceFromFrameSet( _setId );

  if( _id < 0) {
    return false;
  }

  return true;
}


}
