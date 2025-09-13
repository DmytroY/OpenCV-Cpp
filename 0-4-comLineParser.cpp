// compile manually with:
// g++ -o 1_imshow.exe 1_imshow.cpp -IC:\DY\Programs\OpenCV-MinGW-Build\include -IC:\DY\Programs\OpenCV-MinGW-Build\include\opencv4 -LC:\DY\Programs\OpenCV-MinGW-Build\x64\mingw\lib -lopencv_core455 -lopencv_imgcodecs455 -lopencv_highgui455
// or press Ctl+Shift+b for build(compile) with parameters from task.json

#include <opencv2/opencv.hpp>
#include <iostream>



int main( int argc, char** argv ) {
    const std::string keys =
        "{ help h usage ? | | \nUsage in shell:  ./0-4-comLineParser --path <path to image>\n Usage in PowerShell:  ./0-4-comLineParser --path=<path to image>}"
        "{path p | | Path to image file}";

    cv::CommandLineParser parser(argc, argv, keys);
    if(parser.has("help")){
        parser.printMessage();
        return 0;
    }

    std::string path = parser.get<std::string>("path");
    std::cout << "Provided next path to image:" << path <<"\n";
    if(path.empty()){
        std::cerr << "==== provide path to image. Use -p or --path argument";
        return 1;
    }


    cv::Mat image = cv::imread(path);
    if (image.empty()) {
        std::cerr << "==== Could not open or find the image! ====" << std::endl;
        return -1;
    }

    cv::imshow("Display window", image);
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}