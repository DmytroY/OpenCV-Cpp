#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    //cv::Mat src(cv::Size(3, 3), CV_8UC1);
    cv::Mat src = (cv::Mat_<uchar>(3, 3) << 125,    125,    125,
                                            125,    100,    125,
                                            125,    125,    125);
    cv::Mat out1;

    // cv::Mat src = cv::imread("resourses/apple.jpeg", cv::IMREAD_GRAYSCALE);

    cv::adaptiveThreshold(src, out1, 200, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 3, 0);

    auto wflags = cv::WINDOW_NORMAL;
    cv::namedWindow("source", wflags);
    cv::namedWindow("out1", wflags); 

    cv::imshow("source", src);
    cv::imshow("out1", out1);

    cv::waitKey();
    return 0;
}