
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

FrameSet::FrameSet( const string &path )
  : GoSource(), _setId(-1)
{
  openFrameSet(path);
}

FrameSet::~FrameSet()
{
  if( _setId >= 0 ) CloseFrameSet(_id);
}

bool FrameSet::openFrameSet( const string &path )
{
  // Well isn't this ugly...
  auto chars = strdup( path.c_str() );
  _setId = OpenFrameSet( chars );
  free(chars);

  if (_setId < 0) {
    return false;
  }

  // Also open it as a CGO FrameSource
  _id = FrameSetToSequential( _setId );
  
  if( _id < 0) return false;

  return true;
}


bool FrameSet::openChunk( const string &name )
{
  auto chars = strdup( name.c_str() );
  auto newId = OpenFrameSetChunk( _setId, chars );
  free(chars);

  if( newId < 0 ) {
    return false;
  }

  CloseSequential(_id);

  _id = newId;
  return true;
}




}
