
#include <iostream>

#include <gtest/gtest.h>

#include "test_data.h"
#include "libvideoio-go/GoSource.h"

using namespace libvideoio;
using namespace std;

namespace {

TEST( MultiMovGoSource, LoadFrameSet ) {

  GoSource src( TEST_MULTIMOV_PATH );

  ASSERT_TRUE( src.isOpened() );

  // Expected values before reading a frame
  ASSERT_EQ( src.numFrames(), -1 );
  ASSERT_EQ( src.frameNum(), -1 );

  // Grab one frame
  ASSERT_TRUE(src.grab());

  cv::Mat img;
  ASSERT_EQ( src.getImage(0, img), 1 );

  ASSERT_EQ( img.size().width, 1920 );
  ASSERT_EQ( img.size().height, 1080 );
  ASSERT_EQ( img.channels(), 3 );

  ASSERT_EQ( src.getImage(-1, img), -1 );

}

}
