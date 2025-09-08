#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("resourses/grass.webp", cv::IMREAD_GRAYSCALE);
    cv::imshow("input", img);

    float range[] = {0, 256};
    const float* histRange = {range};

    cv::Mat histOut;
    const int histSize = 256;
    const int chNum = 0;

    cv::calcHist(&img, 1, &chNum, cv::Mat(), histOut, 1, &histSize, &histRange);
    // histOut.type() is CV_32F

    // demonstrate histogram property
    int sum{0};
    std::cout << "Histogram values:  ";
    for(int i = 0; i < 256; i++){
        sum += (int)histOut.at<float>(i);
        std::cout << (int)histOut.at<float>(i) << ", ";
    }
    std::cout << "\n\n";
    std::cout << "image size is " << img.size() << "\n";
    std::cout << "Histogram sum is " << sum << ". Which is image with*height." "\n\n";

    // find max value
    double min, max;
    cv::Point minLoc, maxLoc;
    cv::minMaxLoc(histOut, &min, &max, &minLoc, &maxLoc);
    std::cout << "max value of histogram is " << max << ", situated at index " << maxLoc << "\n\n";

    double ratio = max / 256;
    cv::Mat graph = cv::Mat::zeros(cv::Size(256, 256), CV_8UC1);
    for(int i = 0; i < 256; i++){
        cv::line(graph, cv::Point(i,255), cv::Point(i, 255 - (int)histOut.at<float>(i)/ratio), cv::Scalar(125,255,125));
    }
    cv::imshow("Histogram", graph);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}