#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    cv::Mat img = cv::imread("resourses/low_contrast_bad_w_ballance.webp");
    cv::imshow("source", img);

    // equalizeHist works for one channel only. So we can easy equalize histogram for grayskale image.
    // If we want equalize histogram for color image we need to split it to color channels, equalize
    // each channel that assemble color image.
    // this will enhance contrast and fix white balance
    // unfortenatuly it will enhance noise too
    std::vector<cv::Mat> channels;
    cv::split(img, channels);

    cv::equalizeHist(channels[0], channels[0]);
    cv::equalizeHist(channels[1], channels[1]);
    cv::equalizeHist(channels[2], channels[2]);

    cv::Mat dst;
    cv::merge(channels, dst);
    cv::imshow("result", dst);

    cv::waitKey();
    return 0;
}