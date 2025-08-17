#include <opencv2/opencv.hpp>

int main() {

    // cv::Mat mask = cv::Mat::zeros(cv::Size(6, 6), CV_8UC1);
    cv::Mat_<uchar> mask(6, 6);

    // Bayer color filter pattern:
    // B  G
    // G  R
    mask << 
    0,   0,  0,   0, 255,   0,
    0, 255,  0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,
    0,   0,  0,   0,   0,   0,
    255,125, 0,   0,   0, 255,
    125,255, 0,   0, 255,   0;

    cv::Mat result;
    cv::demosaicing(mask, result, cv::COLOR_BayerRG2BGR);

    // std::cout << mask << "\n";
    cv::namedWindow("input", 0);
    cv::imshow("input", mask);

    cv::namedWindow("result", 0);
    cv::imshow("result", result);

    cv::waitKey();

    return 0;
} 