#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    // original image
    // cv::Mat src = cv::Mat::zeros(cv::Size(3, 2), CV_8UC1);
    // src.at<uchar>(cv::Point(0, 0)) = 201;
    // src.at<uchar>(cv::Point(0, 1)) = 101;
    // ....
    cv::Mat src = (cv::Mat_<uchar>(2, 3) << 0, 1, 9,
                                          33, 66, 99 );

    // destination image can be any size
    cv::Mat dst;

    // here we will map from 2x3 to 3x2
    // mapping matrices
    cv::Mat mapX(3, 2, CV_32FC1);
    cv::Mat mapY(3, 2, CV_32FC1);
    mapX.at<float>(0, 0) = 2; mapY.at<float>(0,0) = 0;
    mapX.at<float>(1, 0) = 1; mapY.at<float>(0,0) = 0;
    mapX.at<float>(2, 0) = 0; mapY.at<float>(0,0) = 0;

    // NB! next string maps place between two pixels of original src image, and
    // because we will use cv::INTER_LINEAR in mapping operation,
    // resulting pixel will be average of nearest mapped pixels of src
    mapX.at<float>(0, 1) = 1.5; mapY.at<float>(0,1) = 1;
    mapX.at<float>(1, 1) = 1; mapY.at<float>(1,1) = 1;
    mapX.at<float>(2, 1) = 0; mapY.at<float>(2,1) = 1;



    
    cv::remap(src, dst, mapX, mapY, cv::INTER_LINEAR);

    std::cout << src << "\n";
    std::cout << "---------" << "\n";
    std::cout << dst << "\n\n";

    return 0;
}