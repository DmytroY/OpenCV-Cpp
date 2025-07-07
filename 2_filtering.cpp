// compile manually with:
// g++ -o 2_filtering.exe 2_filtering.cpp -IC:\DY\Programs\OpenCV-MinGW-Build\include -IC:\DY\Programs\OpenCV-MinGW-Build\include\opencv4 -LC:\DY\Programs\OpenCV-MinGW-Build\x64\mingw\lib -lopencv_core455 -lopencv_imgcodecs455 -lopencv_highgui455 -lopencv_imgproc455
// or press Ctl+Shift+b for build(compile) with parameters from task.json

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("resourses/apple.jpeg");
        if (image.empty()) {
        std::cerr << "==== Could not open or find the image! ====" << std::endl;
        return -1;
    }

    cv::Mat bilateralImg, gaussImg, medianImg;
    
    cv::bilateralFilter(image, bilateralImg, 15, 50, 30);
    cv::GaussianBlur(image, gaussImg, cv::Size(15, 15), 0);
    cv::medianBlur(image, medianImg, 15);

    cv::imshow("Original Image", image);
    cv::imshow("bilateral filtered Image", bilateralImg);
    cv::imshow("Gauss fblur Image", gaussImg);
    cv::imshow("Median fblur Image", medianImg);

    cv::waitKey(0);
    // cv::destroyAllWindows(); 
    return 0;
}