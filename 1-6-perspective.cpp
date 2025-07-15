#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::imread("resourses/ticket.jpg", 1);
    cv::Mat out;

// 354 x 196
    cv::Point2f srcPoints[] = {
        cv::Point(141,224),
        cv::Point(448, 77),
        cv::Point(207,353),
        cv::Point(516,202)
    };

        cv::Point2f destPoints[] = {
        cv::Point(0,0),
        cv::Point(340, 0),
        cv::Point(0,145),
        cv::Point(340,145)
    };

    cv::Mat matrix = cv::getPerspectiveTransform(srcPoints, destPoints);

    cv::warpPerspective(img, out, matrix, cv::Size(340,145));
    
    cv::imshow("image", img);
    cv::imshow("transformed", out);
    cv::waitKey(0);

    return 0;
}