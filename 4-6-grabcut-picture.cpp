#include <opencv2/opencv.hpp>

int main(){

    cv::Mat img = cv::imread("resourses/mushroom.jpg");
    cv::Mat result = img.clone();
    cv::Mat bg, fg, mask;

    cv::Rect rect = cv::selectROI(img);

    cv::grabCut(img, mask, rect, bg,fg, 2, cv::GC_INIT_WITH_RECT);

    for(int x = 0; x < img.cols; x++){
        for(int y = 0; y < img.rows; y++){
            // color initial backgrounf area white
            if( mask.at<uchar>(cv::Point(x,y)) == 0){
                result.at<cv::Vec3b>(cv::Point(x,y)) = {255, 255, 255};
            }
            // color calculated backgrounf area gray
            if( mask.at<uchar>(cv::Point(x,y)) == 2){
                result.at<cv::Vec3b>(cv::Point(x,y)) = {125, 125, 125};
            }
        }
    }

    cv::imshow("result", result);
    cv::waitKey();

    return 0;
}