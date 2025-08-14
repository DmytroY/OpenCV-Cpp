#include <opencv2/opencv.hpp>

int main(){
    cv::Mat bgr = cv::Mat(cv::Size(3, 3), CV_8UC3, cv::Scalar(50, 200, 100));
    std::cout << "Original BGR. size is" << bgr.size() << "\n";
    std::cout << bgr << "\n";

    cv::Mat rgb;
    cv::cvtColor(bgr, rgb, cv::COLOR_RGB2BGR);
    std::cout << "\n Converted to RGB "<< "\n";
    std::cout << rgb << "\n";

    cv::Mat bgra;
    cv::cvtColor(bgr, bgra, cv::COLOR_RGB2BGRA);
    std::cout << "\n Converted to BGRA "<< "\n";
    std::cout << bgra << "\n";

    return 0;
}