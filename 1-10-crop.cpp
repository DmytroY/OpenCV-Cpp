#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    cv::Mat src = cv::imread("resourses/ticket.jpg");
    std::cout << "Image size is " << src.cols << "x" << src.rows << "\n";
    cv::imshow("input", src);

    // crop based on top left corner
    cv::Mat out1 = src(cv::Rect(100, 100, 300, 200));
    cv::imshow("out1", out1);

    // crop based on center
    cv::Mat out2;
    cv::getRectSubPix(src, cv::Size(300, 200), cv::Point(250, 200), out2);
    cv::imshow("out2", out2);

    // crop based on selection
    cv::Rect region = cv::selectROI("Select region and press Enter", src, true, false);
    cv::Mat out3 = src(region);
    cv::imshow("out3", out3);

    cv::waitKey();
    return 0;
}