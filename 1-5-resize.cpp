#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::imread("resourses/apple.jpeg", 1);
    cv::Mat out;
    cv::namedWindow("image", 1);
    // by exact size
    //cv::resize(img, out, cv::Size(200,50));

    // by proportion
    cv::resize(img, out, cv::Size(), 4, 1);
    
    cv::imshow("image", out);
    cv::waitKey(0);

    return 0;
}