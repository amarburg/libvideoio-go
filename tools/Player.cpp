
#include <iostream>

#include <stdlib.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <CLI11.hpp>

using namespace std;

#include "libvideoio-go/GoSource.h"
using namespace libvideoio;



using cv::Mat;

int main( int argc, char **argv )
{
  // // Declare the supported options.
  // po::options_description desc("Allowed options");
  // desc.add_options()
  //     ("help", "produce help message")
  //     ("input-file", po::value<string>(), "Name of input file");
  //
  // po::positional_options_description p;
  // p.add("input-file", -1);
  //
  // po::variables_map vm;
  // po::store(po::command_line_parser(argc, argv).
  //         options(desc).positional(p).run(), vm);
  // po::notify(vm);

  CLI::App app{"Sample Mov player"};

  std::string inputFile = "default";
  app.add_option("input-file", inputFile, "Movie file to open");

  CLI11_PARSE(app, argc, argv);

  //
  // if (vm.count("help")) {
  //     cout << desc << endl;
  //     return 1;
  // }
  //
  // if (vm.count("input-file") != 1 ) {
  //     cout << "Program takes exactly one input file" << endl;
  //     return 1;
  // }

  cout << "Opening input file: " << inputFile << endl;

  GoSource src( inputFile );

  Mat img;
  int count = 0;
  while( src.grab() && count < 200 ) {
    if( src.getImage( 0, img ) == 0 ) {
      cv::imshow("Window", img);
      cv::waitKey(1);
    }

      count++;
  }

  return 0;
}
