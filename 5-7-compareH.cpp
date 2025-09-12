#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img1 = cv::imread("resourses/mushroom_cropped.jpg", cv::IMREAD_GRAYSCALE);
    cv::Mat img2 = cv::imread("resourses/mushroom.jpg", cv::IMREAD_GRAYSCALE);
    cv::imshow("input1", img1);
    cv::imshow("input2", img2);

    float range[] = {0, 256};
    const float* histRange = {range};

    cv::Mat histOut1, histOut2;
    const int histSize = 256;
    const int chNum = 0;

    cv::calcHist(&img1, 1, &chNum, cv::Mat(), histOut1, 1, &histSize, &histRange);
    cv::calcHist(&img2, 1, &chNum, cv::Mat(), histOut2, 1, &histSize, &histRange);
    // histOut.type() is CV_32F

    double correl = cv::compareHist(histOut1, histOut2, 0);
    double chi_sq = cv::compareHist(histOut1, histOut2, 1);
    double intersec = cv::compareHist(histOut1, histOut2, 2);
    double bhat_dis = cv::compareHist(histOut1, histOut2, 3);

    std::cout << "Correlation : " << correl << "\n";
    std::cout << "Chi-Square : " << chi_sq << "\n";
    std::cout << "Intersection : " << intersec << "\n";
    std::cout << "Bhattacharyya distance : " << bhat_dis << "\n";

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}