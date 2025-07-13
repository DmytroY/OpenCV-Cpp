#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>

int main() {

    cv::Mat mask = cv::Mat::zeros(cv::Size(600, 600), CV_8UC3);
    cv::namedWindow("mask", cv::WINDOW_AUTOSIZE);

    cv::ellipse(mask, cv::Point(300, 200), cv::Size2i(200, 100), 20, 0, 360, cv::Scalar(0,0,255));
    std::vector<cv::Point2d> output;
    cv::ellipse2Poly(cv::Point(300,300), cv::Size2i(200, 100), 10, 0, 360, 20, output);
    for(auto point : output){
        std::cout << point.x << ", " << point.y << "\n";
        mask.at<cv::Vec3b>(point) = cv::Vec3b(0,0,255);
    }

    cv::imshow("mask", mask);
    cv::waitKey(0);


    return 0;
}