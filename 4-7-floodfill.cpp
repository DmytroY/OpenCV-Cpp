#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::imread("resourses/apple.jpeg");
    cv::Mat result = img.clone();
    cv::Mat mask;
    cv::Rect rect;
    // this will flood only neibor pixels with the same value as starting pixel
    // cv::floodFill(result, cv::Point(1,1), cv::Scalar(0, 255, 0));

    // this will flod color range (startColor−loDiff)≤c≤(startColor+upDiff)
    cv::floodFill(result, cv::Point(1,1), cv::Scalar(0, 255, 0), &rect, cv::Scalar(130, 130, 130), cv::Scalar(0, 0, 0), cv::FLOODFILL_FIXED_RANGE);

    cv::imshow("original", img);
    cv::imshow("result", result);
    cv::waitKey();

    return 0;
}
