#ifndef DISPLAY_H
#define DISPLAY_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "Config.h"

class Display{
public:
    Display();
    Display(int width , int height , std::string windowName);

    void show();

    void refreshImgFrame(std::vector<char> img_buffer);

private:
    int width;
    int height;
    std::string windowName;

    cv::Mat img_frame;
};

#endif //DISPLAY_H