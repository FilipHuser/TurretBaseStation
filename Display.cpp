#include "Display.h"

Display::Display(int width , int height , std::string windowName) : width(width) , height(height) , windowName(windowName)
{
    this->img_frame = cv::Mat(this->height, this->width, CV_8UC3, cv::Scalar(0, 0, 0));
}

void Display::show()
{

    cv::imshow("Turret vision", this->img_frame);
    cv::waitKey(1);
}

void Display::refreshImgFrame(std::vector<char> img_buffer)
{
    this->img_frame = cv::Mat(this->height, this->width, CV_8UC3, img_buffer.data());

    show();
}
