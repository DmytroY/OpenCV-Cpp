#include <opencv2/opencv.hpp>
#include <iostream>

int main(){

    //cv::Mat data = cv::Mat::zeros(cv::Size(3, 2), CV_8SC1);
    //data.at<schar>(cv::Point(1, 1)) = 125;
    // data.at<schar>(1, 1) = 125;

    // std::cout << "data:\n " << data << "\n";
 
    cv::Mat data = cv::imread("resourses/krotek.jpeg");
    
    std::cout << "depth: " << data.depth() << "\n";
    std::cout << "type: " << data.type() << "\n";
    std::cout << "size: " << data.size() << "\n";
    //std::cout << "width: " << data.size().width << "\n";
    std::cout << "width: " << data.cols << "\n";
    //std::cout << "height: " << data.size().height << "\n";
    std::cout << "height: " << data.rows << "\n";
    std::cout << "channels: " << data.channels() << "\n";
    return 0;
}