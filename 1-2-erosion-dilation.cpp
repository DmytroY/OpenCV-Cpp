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
    cv::imshow("Original Image", image);

    cv::Mat erodedImg, dilatedImg;

    for(int r = 1; r < 11 ; r += 2){
        std::cout << "kernel size is " << r << "\n";
        cv::Mat elementKernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(r, r), cv::Point(-1, -1));
        cv::erode(image, erodedImg, elementKernel, cv::Point(-1, -1), 1);
        cv::dilate(image, dilatedImg, elementKernel, cv::Point(-1, -1), 1);
        cv::imshow("eroded image", erodedImg);
        cv::imshow("dilated image", dilatedImg);
        cv::waitKey(0);
    }


    // for (int d = 5; d < 26; d += 6){
    //     std::cout << "kernel is " << d << "\n";
    //     cv::bilateralFilter(image, bilateralImg, d, 50, 30);
    //     cv::GaussianBlur(image, gaussImg, cv::Size(d, d), 0);
    //     cv::medianBlur(image, medianImg, d);
        
    //     cv::imshow("bilateral filtered Image", bilateralImg);
    //     cv::imshow("Gauss fblur Image", gaussImg);
    //     cv::imshow("Median fblur Image", medianImg);
    //     cv::waitKey(0);
    // }
   
    cv::waitKey(0);
    // cv::destroyAllWindows(); 
    return 0;
}