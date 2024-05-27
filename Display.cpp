#include "Display.h"
#include <opencv2/opencv.hpp>

Display::Display() : width(DISPLAY_WINDOW_W), height(DISPLAY_WINDOW_H), windowName(DISPLAY_WINDOW_NAME) {}

void Display::show() {

    cv::Point center(this->img_frame.cols / 2, this->img_frame.rows / 2);
    cv::line(this->img_frame, cv::Point(center.x - 10, center.y), cv::Point(center.x + 10, center.y), cv::Scalar(51, 255, 153), 2);
    cv::line(this->img_frame, cv::Point(center.x, center.y - 10), cv::Point(center.x, center.y + 10), cv::Scalar(51, 255, 153), 2);

    cv::imshow("Turret vision", this->img_frame);
    cv::waitKey(1);
}

void Display::refreshImgFrame(std::vector<char> jpeg_img_buffer) {

    std::cout << jpeg_img_buffer.size() << std::endl;

    if(jpeg_img_buffer.empty())
    {
        std::cerr << "EMPTY" << std::endl;
        notify();
    } else {
        
        this->img_frame = cv::imdecode(jpeg_img_buffer, cv::IMREAD_COLOR); // Assuming color image

        if (!this->img_frame.empty()) {
            cv::namedWindow("Turret vision", cv::WINDOW_NORMAL); // Create window if not already created
            cv::setWindowProperty("Turret vision", cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN); // Set fullscreen property
            show();

        } else {
            std::cerr << "Failed to decode image" << std::endl;
        }
    }
}

Display::~Display() {
    cv::destroyAllWindows();
}
