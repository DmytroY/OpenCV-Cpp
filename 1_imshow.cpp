// compile manually with:
// g++ -o 1_imshow.exe 1_imshow.cpp -IC:\DY\Programs\OpenCV-MinGW-Build\include -IC:\DY\Programs\OpenCV-MinGW-Build\include\opencv4 -LC:\DY\Programs\OpenCV-MinGW-Build\x64\mingw\lib -lopencv_core455 -lopencv_imgcodecs455 -lopencv_highgui455
// or press Ctl+Shift+b for build(compile) with parameters from task.json

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    cv::Mat image = cv::imread("resourses/apple.jpeg");
        if (image.empty()) {
        std::cerr << "==== Could not open or find the image! ====" << std::endl;
        return -1;
    }
    cv::imshow("Display window", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}