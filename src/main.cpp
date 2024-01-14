#include <iostream>
#include "cam_record.py"

#include <opencv2/core.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/videoio.hpp>

int main(int argc, char **argv) {
    const char* path = "holder/hi";
    const int fps = 15;
    record(path,fps);
    // create video file
    VideoCapture recording = cv::VideoCapture::open(path);
    cv::DISOpticalFlow optflow = cv::DISOpticalFlow::create(DISOpticalFlow::0)
}