#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    cv::Mat src = (cv::Mat_<uchar>(3, 3) << 10,    0,    0,
                                            0,    255,    0,
                                            0,    255,    0);
    std::cout << "== Source ==\n";                                    
    std::cout << src << "\n";
    
    cv::Mat dst;
    cv::integral(src, dst);

    std::cout << "== Result ==\n";                                    
    std::cout << dst << "\n";

    return 0;
}