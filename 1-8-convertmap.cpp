#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    // original image
    cv::Mat src = (cv::Mat_<uchar>(2, 2) << 0, 125,
                                          125, 255 );

    // destination image can be any size
    cv::Mat dst;

    // here we will map from 2x2 to 2x1

    // mapping matrices X and Y
    cv::Mat mapX(2, 1, CV_32FC1);
    cv::Mat mapY(2, 1, CV_32FC1);
    // mapX.at<float>(0, 0) = 0.5; mapY.at<float>(0,0) = 0;
    // mapX.at<float>(1, 0) = 0.5; mapY.at<float>(1,0) = 1;
    // cv::remap(src, dst, mapX, mapY, cv::INTER_LINEAR);

    // consolidated mapping matrice
    cv::Mat map(2, 1, CV_32FC2);
    map.at<cv::Vec2f>(0, 0) = cv::Vec2f(0.5, 0.0);
    map.at<cv::Vec2f>(1, 0) = cv::Vec2f(0.5, 1.0);

    // without convertMaps
    // cv::remap(src, dst, map, cv::Mat(), cv::INTER_LINEAR);

    // but after convertMaps will be faster
    cv::convertMaps(map, cv::Mat(), mapX, mapY, CV_16SC2);
    cv::remap(src, dst, mapX, mapY, cv::INTER_LINEAR);

    std::cout << src << "\n";
    std::cout << "---------" << "\n";
    std::cout << dst << "\n\n";

    return 0;
}