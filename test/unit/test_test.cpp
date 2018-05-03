
#include <iostream>
#include <gtest/gtest.h>

#include "test_data.h"

using namespace std;

TEST(test_case_name, test_name) {
  ASSERT_TRUE( true );

  cout << "Test data at " << LIBVIDEOIO_GO_TEST_DATA_DIR << endl;
}
