#include <opencv2/opencv.hpp>
#include <iostream>

int main(){
    cv::Mat src = (cv::Mat_<uchar>(3, 3) << 1,    0,    0,
                                            0,    2,    0,
                                            0,    3,    0);
    std::cout << "== Source ==\n";                                    
    std::cout << src << "\n";
    
    cv::Mat intgr, intgr2, intgrt;

    cv::integral(src, intgr, intgr2, intgrt);

    std::cout << "== Integral ==\n";                                    
    std::cout << intgr << "\n\n";

    std::cout << "== Integral of squares ==\n";                                    
    std::cout << intgr2 << "\n\n";

    std::cout << "== Integral tilt 45 degree ==\n";                                    
    std::cout << intgrt << "\n\n";

    return 0;
}