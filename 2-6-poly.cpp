#include <opencv2/opencv.hpp>
#include <vector>

int main(){

    cv::Mat canva = cv::Mat::zeros(cv::Size(600, 400), CV_8UC3);
    cv::namedWindow("canva", 0);
    
    std::vector<std::vector<cv::Point>> pts{{cv::Point(50,50), cv::Point(150,30), cv::Point(50, 150) , cv::Point(160, 160)},
                                            {cv::Point(300, 70), cv::Point(200, 300), cv::Point(550, 350)}};
    //cv::polylines(canva,  pts, 1, cv::Scalar(255, 0, 0), 2);
    //cv::fillPoly(canva, pts, cv::Scalar(125,125,0));
    
    for (int i = 0; i < pts.size(); i++){
        cv::drawContours(canva, pts, i, cv::Scalar(255,0,125), 2);
    }
    

    // std::vector<cv::Point> vertices{cv::Point(50,50), cv::Point(150,30), cv::Point(50, 150) , cv::Point(160, 160)};
    // cv::fillConvexPoly(canva, vertices, cv::Scalar(0,125,255));


    cv::imshow("canva", canva);
    cv::waitKey(0);

    return 0;
}