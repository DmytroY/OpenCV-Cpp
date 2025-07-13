#include <opencv2/opencv.hpp>

int main(){
    // cv::Mat_<float> image(5, 5);
    // image << 255, 255, 255, 000, 000,
    //          255, 255, 255, 000, 000,
    //          255, 255, 255, 000, 000,
    //          000, 000, 000, 000, 000,
    //          000, 000, 000, 000, 000;

    cv::Mat image = cv::imread("resourses/apple.jpeg");
    cv::Mat im8, fil2D, filter2D8;

    cv::Mat_<float> kernel(3,3);
    // detecting edges
    kernel << -1,  1, -1,
               1,  0,  1,
              -1,  1, -1;

    // laplacian - more sharp edge detection
    // kernel << 0,  1,  0, 
    //           1, -4,  1,
    //           0,  1,  0;

    // enhance sharpness
    // kernel << -1,  1, -1,
    //            1,  1,  1,
    //           -1,  1, -1;
    
    // blur
    // kernel << 0.11,  0.11, 0.11,
    //            0.11,  0.11,  0.11,
    //           0.11,  0.11, 0.11;

    // gauss blur
    // kernel << 0.0625,  0.125, 0.0625,
    //            0.125,  0.25,  0.125,
    //           0.0625,  0.125, 0.0625;

    // emboss
    // kernel << -1,  -1,  0,
    //           -1,   0,  1,
    //            0,   1,  1;



    // motion blur
    // kernel << 0.33,    0,    0, 
    //           0,    0.33,    0,
    //           0,    0,    0.33;


    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::namedWindow("filter2D", cv::WINDOW_NORMAL);

    cv::filter2D(image, fil2D, -1, kernel);

    image.convertTo(im8, CV_8U);
    fil2D.convertTo(filter2D8, CV_8U);

    cv::imshow("image", im8);
    cv::imshow("filter2D", filter2D8);

    cv::waitKey(0);
    return 0;
}