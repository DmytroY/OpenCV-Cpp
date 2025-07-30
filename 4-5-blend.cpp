#include <opencv2/opencv.hpp>

int main(){
    cv::Mat krot = cv::imread("resourses/krotek.jpeg");
    cv::Mat back = cv::imread("resourses/grass.webp");

    // to blend images should be same size
    cv::Mat back_resized;
    cv::resize(back, back_resized, krot.size());

    // weights define how pixels blended.
    // give background image weights 1 and object image significantly higer.
    // then itterate in object image and reset to  0  weight for every too bright pixel
    // so surrounding pixels became transparent.
    cv::Mat weights_back = cv::Mat::ones(krot.size(), CV_32F);
    cv::Mat weights_krot(krot.size(),CV_32F, cv::Scalar(1000));

    for(int x = 0; x < krot.cols; x++){
        for(int y = 0; y < krot.rows; y++){
            if((int)krot.at<cv::Vec3b>(cv::Point(x, y))[0] > 240 &&
                (int)krot.at<cv::Vec3b>(cv::Point(x, y))[1] > 240 &&
                (int)krot.at<cv::Vec3b>(cv::Point(x, y))[2] > 240 ) {
                    weights_krot.at<float>(cv::Point(x, y)) = 0;
                }
        }
    }

    // blend images
    cv::Mat result;
    cv::blendLinear(back_resized, krot, weights_back, weights_krot, result);

    cv::imshow("blend", result);
    cv::waitKey();

    return 0;
}