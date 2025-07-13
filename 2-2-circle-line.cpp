#include <opencv2/opencv.hpp>
#include <cmath>


int main(){
    cv::Mat mask = cv::Mat::zeros(cv::Size(800, 800), CV_8UC3);
    cv::namedWindow("mask", cv::WINDOW_AUTOSIZE);
    int angle{0};
    const int center_x = 400;
    const int center_y = 400;
    const int radius = 200;
    int x, y;
    cv::createTrackbar("Angle", "mask", &angle, 360);

    while(true){
        cv::circle(mask, cv::Point(center_x, center_y), radius, cv::Scalar( 255, 0 , 0), 2);
        cv::line(mask, cv::Point(center_x, center_y - radius -50), cv::Point(400, center_y + radius + 50),cv::Scalar(0,255,0));
        cv::line(mask, cv::Point(center_x - radius - 50, center_y), cv::Point(center_x + radius + 50, center_y),cv::Scalar(0,255,0));

        int x = center_x + radius*cos(0.01745 * angle);
        int y = center_y - radius*sin(0.01745 * angle);
        cv::arrowedLine(mask, cv::Point(center_x, center_y), cv::Point(x, y), cv::Scalar(0,0,255), 1, 8 , 0, 0.05);
        cv::putText(mask, " Move slider or press 'q' for exit", cv::Point(100, 700), cv::FONT_HERSHEY_COMPLEX, 0.8, cv::Scalar(255,255,255), 1);
        cv::imshow("mask", mask);     

        int c = cv::waitKey(1);
        if(c == 'q') return 0;
        mask = cv::Mat::zeros(cv::Size(800, 800), CV_8UC3);
    }
    

    return 0;
}