// compile manually with:
// g++ -o 1_imshow.exe 1_imshow.cpp -IC:\DY\Programs\OpenCV-MinGW-Build\include -IC:\DY\Programs\OpenCV-MinGW-Build\include\opencv4 -LC:\DY\Programs\OpenCV-MinGW-Build\x64\mingw\lib -lopencv_core455 -lopencv_imgcodecs455 -lopencv_highgui455
// or press Ctl+Shift+b for build(compile) with parameters from task.json

#include <iostream>
#include <opencv2/opencv.hpp>

int main(){
    std::cout << "OpenCV version:" << CV_VERSION << "\n";
    return 0;
}