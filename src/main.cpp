#include <opencv2/opencv.hpp>
#include <iostream>
#include "cam_record.py"

int main(int argc, char** argv) {
    // Assume "path" points to a valid video file
    const char* path = "path/to/your/video.mp4";
    const int fps = 15;
    record(path, fps);

    // Open the video file
    cv::VideoCapture cap(path);
    if (!cap.isOpened()) {
        std::cout << "Error opening video stream or file" << std::endl;
        return -1;
    }

    // Read the first frame
    cv::Mat frame;
    cap >> frame;

    // Define an initial bounding box (x, y, width, height)
    cv::Rect2d bbox(287, 23, 86, 320);

    // Create a tracker instance
    // For example, using the MIL algorithm:
    cv::Ptr<cv::TrackerMIL> tracker = cv::TrackerMIL::create();

    // Initialize the tracker with the first frame and the initial bounding box
    tracker->init(frame, bbox);

    while (true) {
        // Read a new frame
        cap >> frame;
        if (frame.empty())
            break;

        // Update the tracking result
        bool ok = tracker->update(frame, bbox);

        // Draw the tracked object
        if (ok)
            cv::rectangle(frame, bbox, cv::Scalar(255, 0, 0), 2, 1);
        else
            cv::putText(frame, "Tracking failure detected", cv::Point(100, 80), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 255), 2);

        // Display result
        cv::imshow("Tracking", frame);

        // Exit on ESC key
        if (cv::waitKey(30) == 27) {
            break;
        }
    }
    return 0;
}