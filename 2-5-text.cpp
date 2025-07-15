#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main(){
    int w{600}, h{400};
    cv::Mat mask = cv::Mat::zeros(cv::Size(w, h), CV_8UC3);
    cv::namedWindow("mask", cv::WINDOW_AUTOSIZE);

    std::string text = "Put it in center";
    int baseline=0;
    cv::Size size = cv::getTextSize(text, cv::FONT_HERSHEY_COMPLEX, 1, 1, &baseline);

    int x = w/2 - size.width/2;
    int y = h/2 - size.height/2;
    cv::putText(mask, text, cv::Point(x, y), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar( 255, 255, 255));


    cv::imshow("mask", mask);
    cv::waitKey(0);
    return 0;
}