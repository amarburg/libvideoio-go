
#include <string>

#include "libvideoio-go/FrameSet.h"

namespace libvideoio {

using std::string;

FrameSet::FrameSet( void )
  : _id(-1)
{
}

FrameSet::FrameSet( const std::string &path )
  : _id(-1)
{
  open(path);
}

FrameSet::~FrameSet()
{
  if( _id >= 0 ) CloseFrameSet(_id);
}

bool FrameSet::open( const std::string &path )
{
  // Well isn't this ugly...
  auto chars = strdup( path.c_str() );
  _id = OpenFrameSet( chars );
  free(chars);

  return (_id >= 0);
}


}
