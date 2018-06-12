
#include <iostream>

#include <stdlib.h>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <libg3logger/g3logger.h>

#include <CLI/CLI.hpp>

using namespace std;

#include "libvideoio/Undistorter.h"

#include "libvideoio-go/GoSource.h"
using namespace libvideoio;


using cv::Mat;

int main( int argc, char **argv )
{
  libg3log::G3Logger logWorker( argv[0] );
  logWorker.logBanner();

  CLI::App app{"GoSource player"};

  bool verbose;
  app.add_flag("-v,--verbose", verbose, "Print DEBUG output to console");

  fs::path inputFile;
  app.add_option("input,--input", inputFile, "Movie file to open")->required()->check(CLI::ExistingFile);

  fs::path calibFile;
  auto flag_calib = app.add_option("-c,--calib", calibFile, "Calibration file" )->expected(1)->check(CLI::ExistingFile);

  app.set_config("--config");

  CLI11_PARSE(app, argc, argv);

  std::shared_ptr<Undistorter> undistorter;

  if( *flag_calib) {
    // Make undistorter
    undistorter.reset( UndistorterFactory::getUndistorterFromFile( calibFile.string() ) );
    if( !undistorter or !undistorter->isValid() ) {
      LOG(FATAL) << "Unable to load calibration file \"" << calibFile << "\"";
    }
  }

  cout << "Opening input file: " << inputFile << endl;

  shared_ptr<GoSource> src( new GoSource(inputFile.string()) );
  src->setOutputType( CV_8UC3 );

  Mat img;
  int count = 0;
  while( src->grab() && count < 200 ) {
    if( src->getImage( img ) >= 0 ) {

      cv::imshow("Window", img);

      if( undistorter ) {
        Mat undistorted;
        undistorter->undistort( img, undistorted );

        cv::imshow("Undistorted", undistorted );
      }
      cv::waitKey(100);
    }

    count++;
  }

  return 0;
}
