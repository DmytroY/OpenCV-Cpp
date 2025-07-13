#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat mask = cv::Mat::zeros(cv::Size(600, 600), CV_8UC3);
    cv::namedWindow("mask", cv::WINDOW_AUTOSIZE);
    int shift;
    std::string text;
    cv::createTrackbar("shift", "mask", &shift, 550);
    cv::Rect rectangle(cv::Point(200, 50), cv::Point(300, 300));

    while(true){
        cv::rectangle(mask, rectangle, cv::Scalar(125, 125, 0));
        cv::Point p1(shift, 100);
        cv::Point p2(shift + 50, 200);
        cv::line(mask, p1, p2, cv::Scalar(0, 0, 255));
        if(cv::clipLine(rectangle, p1, p2)){
            text = "The line intersects rectangle. Move slider or press 'q' for exit";
        }else{
            text = "The line is out of rectangle. Move slider or press 'q' for exit";
        }
        cv::putText(mask, text, cv::Point(10, 400), cv::FONT_HERSHEY_COMPLEX, 0.5, cv::Scalar(255,255,255));

        cv::imshow("mask", mask);
        int c = cv::waitKey(1);
        if(c =='q') return 0;
        mask = cv::Mat::zeros(cv::Size(600, 600), CV_8SC3);
    }

    return 0;
}