#include "Display.h"

Display::Display(int width , int height , std::string windowName) : width(width) , height(height) , windowName(windowName)
{
    this->img_frame = cv::Mat(this->width, this->height, CV_8UC3, cv::Scalar(0, 0, 0));
    cv::namedWindow("Turret vision", cv::WINDOW_NORMAL);
}

void Display::show()
{
    cv::imshow("Turret vision", this->img_frame);
}

void Display::refreshImgFrame(std::vector<char> img_buffer)
{
    this->img_frame = cv::Mat(height, width, CV_8UC3, img_buffer.data());
}