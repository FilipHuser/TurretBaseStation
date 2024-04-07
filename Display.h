#ifndef DISPLAY_H
#define DISPLAY_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

#include "Config.h"

class Display {
public:
//CONSTRUCTOR
    Display();

//METHODS
    void show();
    void refreshImgFrame(std::vector<char> img_buffer);

//DECONSTRUCTOR
    ~Display();

private:
    int width;
    int height;
    std::string windowName;
    cv::Mat img_frame;
};

#endif //DISPLAY_H