#include "Display.h"
#include <opencv2/opencv.hpp>

Display::Display() : width(DISPLAY_WINDOW_W), height(DISPLAY_WINDOW_H), windowName(DISPLAY_WINDOW_NAME) {}

void Display::show() {
    cv::imshow("Turret vision", this->img_frame);
    cv::waitKey(16);
}

void Display::refreshImgFrame(std::vector<char> jpeg_img_buffer) {

    this->img_frame = cv::imdecode(jpeg_img_buffer, cv::IMREAD_COLOR); // Assuming color image

    if (!this->img_frame.empty()) {

        show();
    } else {
        //std::cerr << "Failed to decode image" << std::endl;
    }
}

Display::~Display() {
    cv::destroyAllWindows();
}
