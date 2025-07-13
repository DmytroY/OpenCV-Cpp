#include <opencv2/opencv.hpp>

int main() {
    int dx{0}, dy{0}, kernel{3};
    double scale{1.0}, delta{0};
    cv::Mat in_image, sobel_img, lapl_img;
    in_image = cv::imread("resourses/apple.jpeg");
    cv::namedWindow("Original image", cv::WINDOW_NORMAL);
    cv::namedWindow("Sobel operator", cv::WINDOW_NORMAL);
    cv::namedWindow("Laplacian", cv::WINDOW_NORMAL);

    cv::imshow("Original image", in_image);

    while(true) {
        int c = cv::waitKey(0);
        switch (c)
        {
        case 'c': // clear to default paramenters
            dx = 1;
            dy = 1;
            kernel = 1;
            scale = 1;
            delta = 0;
            break;
        case 'd': // delta parameter increment
            delta += 0.5;
            break;
        case 's': //scale parameter increment 
            scale += 0.5;
            break;
        case 'x': // dx only
            dx = 1;
            dy = 0;
            break;
        case 'y': // dy only
            dy = 1;
            dx = 0;
            break;
        case 'b': // both dx and dy
            dx = 1;
            dy = 1;
            break;
         case 'k': // kernel parameter increment 
            kernel += 2;
            break;           
        case 'q':  // quit
            cv::destroyAllWindows();
            return 0;        
        default:
            break;
        }
    cv::Sobel(in_image, sobel_img, -1, dx, dy, kernel, scale, delta );
    cv::imshow("Sobel operator", sobel_img);

    cv::Laplacian(in_image, lapl_img, -1, 1, 1, 0);
    cv::imshow("Laplacian", lapl_img);
    }

    return 0;
}