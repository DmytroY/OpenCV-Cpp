#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
int main() {
    //  === cosinus ===
    Mat img = Mat::zeros(cv::Size(200, 360), CV_8UC3);
    for(int i = 0; i < img.rows; i++){
        int j =img.cols / 2 + cos(i * 2.0 * 3.14159/360) * 0.9 * img.cols / 2;
        img.at<cv::Vec3b>(cv::Point(j, i)) = {125, 255, 125};
    }
    imshow("input", img);

    // === Cardioida from cosinus===
    cv::Mat dst;
    // int flags = cv::INTER_LINEAR + cv::WARP_FILL_OUTLIERS + cv::WARP_INVERSE_MAP;
    int flags = cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS | cv::WARP_POLAR_LINEAR | cv::WARP_INVERSE_MAP  ;
    int maxRadius = 250;
    cv::Point2f center{250,250};
    cv::warpPolar(img, dst, cv::Size(500,500), center, maxRadius, flags);
    imshow("output1", dst);

    // === back to cos from cardioida ===
    flags = cv::INTER_LINEAR | cv::WARP_FILL_OUTLIERS | cv::WARP_POLAR_LINEAR;
    Mat dst2;
    cv::warpPolar(dst, dst2, cv::Size (200, 360), center, maxRadius, flags);
    imshow("output2", dst2);

    waitKey(0);
    return 0;
}