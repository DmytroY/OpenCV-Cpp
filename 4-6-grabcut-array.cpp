#include <opencv2/opencv.hpp>

int main(){

    cv::Mat img_gray = (cv::Mat_<uchar>(7, 7) << 
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 9, 9 ,0, 0, 0,
        0, 0, 9, 0 ,0, 0, 0,
        0, 0, 0, 0 ,0, 0, 0,
        0, 0, 0, 0 ,0, 0, 0,
        0, 0, 0, 0 ,0, 0, 0 );
    cv::Mat img;
    cv::cvtColor(img_gray, img, cv::COLOR_GRAY2BGR);
    cv::Mat bg, fg, mask;
    cv::Rect rect(1, 1, 4, 4);

    cv::grabCut(img, mask, rect, bg,fg, 2, cv::GC_INIT_WITH_RECT);
    // rect is initial selection of foreground obj
    // bg and fg are temporary arrays used by grabcut for itterations
    std::cout << "mask: \n";
    std::cout << mask << "\n";

    return 0;
}

// mask: 
// [  0,   0,   0,   0,   0,   0,   0;
//    0,   2,   2,   2,   2,   0,   0;
//    0,   2,   3,   3,   2,   0,   0;
//    0,   2,   3,   2,   2,   0,   0;
//    0,   2,   2,   2,   2,   0,   0;
//    0,   0,   0,   0,   0,   0,   0;
//    0,   0,   0,   0,   0,   0,   0]

// 0 is initial background
// 2 is calculated backgroud
// 3 is foreground