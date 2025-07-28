#include <opencv2/opencv.hpp>

int main(){
    // cv::Mat src(cv::Size(255, 100), CV_8UC1);
    // for(int x = 0; x < src.cols; x++){
    //     for(int y = 0; y < src.rows; y++){
    //         src.at<uchar>(cv::Point(x, y)) = x;
    //     }
    // }
    cv::Mat out1;
    // cv::threshold(src, out1, 100, 200, cv::THRESH_TRUNC);

    cv::Mat src = cv::imread("resourses/apple.jpeg");
    cv::threshold(src, out1, 240, 255, cv::THRESH_BINARY);

    cv::imshow("source", src);
    cv::imshow("out1", out1);

    cv::waitKey();
    return 0;
}