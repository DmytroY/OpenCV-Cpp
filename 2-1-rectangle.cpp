#include <opencv2/opencv.hpp>

int main(){
    cv::Mat mask = cv::Mat::zeros(cv::Size(800, 800), CV_8UC3);
    cv::namedWindow("mask", cv::WINDOW_AUTOSIZE);

    // cv::rectangle(mask, cv::Rect(cv::Point(10 , 10 ), cv::Point(20, 40)), cv::Scalar(0, 255, 0), 3, cv::LINE_4);
    // cv::rectangle(mask, cv::Point(50, 50), cv::Point2i(70, 70), cv::Scalar(255, 0, 0), 3, cv::LINE_AA);

    // cv::Rect r(30, 30, 30, 30);
    // cv::rectangle(mask, r, cv::Scalar(0, 0, 255), 2);

    int point1 = 50;
    int point2 = 70;
    cv::createTrackbar("Point1", "mask", &point1, 700);
    cv::createTrackbar("Point2", "mask", &point2, 700);

    while(true){
        cv::rectangle(mask, cv::Point(point1, point1), cv::Point(point2, point2), cv::Scalar(255, 0, 0), 3);
        cv::imshow("mask", mask);

        int c = cv::waitKey(1);
        if(c == 'q') return 0;
        
        mask = cv::Mat::zeros(cv::Size(800, 800), CV_8UC3);
    }

    return 0;
}