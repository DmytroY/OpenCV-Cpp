#include <opencv2/opencv.hpp>

int main() {
    cv::Mat input = cv::Mat::ones(cv::Size(5, 5), CV_8UC1);

    input.at<uchar>(cv::Point(0, 0)) = 0;
    input.at<uchar>(cv::Point(4, 0)) = 0;
    input.at<uchar>(cv::Point(4, 4)) = 0;
    std::cout << "== Input ==\n";
    std::cout << input << "\n\n";

    cv::Mat dst, label;
    cv::distanceTransform(input, dst, label, cv::DIST_L1, cv::DIST_MASK_PRECISE, CV_8UC1);

    std::cout << "== Distance ==\n";
    std::cout << dst << "\n";

    std::cout << "== Label ==\n";
    std::cout << label << "\n";
    return 0;
}