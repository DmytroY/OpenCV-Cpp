#include <opencv2/opencv.hpp>
#include <vector>

int main() {
    cv::Mat img = cv::imread("resourses/mushroom.jpg", cv::IMREAD_COLOR);
    cv::imshow("input", img);

    std::vector<cv::Mat> channels(3);
    cv::split(img, channels);

    const int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = range;
    std::vector<cv::Mat> histOut(3);

    for(int ch = 0; ch < 3; ch++){
        cv::calcHist(&channels[ch], 1, 0, cv::Mat(), histOut[ch], 1, &histSize, &histRange);
    }

    // Print histogram values for every channel
    for(int ch = 0; ch < 3; ch++){
        std::cout << "=== CHANNEL " << ch << ":\n";
        for(int i = 0; i < 256; i++){
            std::cout << histOut[ch].at<float>(i) << " ";
        }
        std::cout << "\n";
    }


    // find max value
    double min, max, maxVal = 0;
    for(int ch = 0; ch < 3; ch++){
        cv::minMaxLoc(histOut[ch], &min, &max);
        if(maxVal < max) maxVal = max;
    }

    // draw histogrames
    double ratio = maxVal / 256;
    cv::Mat graph = cv::Mat::zeros(cv::Size(256, 256), CV_8UC3);
    cv::Scalar colors[3] = {
        cv::Scalar(255, 0, 0),
        cv::Scalar(0, 255, 0),
        cv::Scalar(0, 0, 255)};

    for(int ch = 0; ch < 3; ch++){
        for(int i = 0; i < 255; i++){
            cv::line(graph, cv::Point(i,255 - (int)histOut[ch].at<float>(i)/ratio), cv::Point(i+1, 255 - (int)histOut[ch].at<float>(i+1)/ratio), colors[ch]);
        }
    }

    cv::imshow("Histogram", graph);

    cv::waitKey();
    cv::destroyAllWindows();

    return 0;
}