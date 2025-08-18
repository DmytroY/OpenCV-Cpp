#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("resourses/Suitcase-Xray.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("input", img);

    cv::Mat result;

    cv::applyColorMap(img, result, cv::COLORMAP_JET);
    cv::imshow("result", result);
    
    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}