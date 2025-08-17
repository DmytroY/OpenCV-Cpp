#include <opencv2/opencv.hpp>

int main(){
    cv::Mat img = cv::imread("resourses/apple.jpeg");

    // 1. Convert from BGR for YUV format
    cv::Mat yuv;
    cv::cvtColor(img, yuv, cv::COLOR_BGR2YUV_I420);
    cv::imshow("yuv", yuv);
    

    // 2. Split YUV
    cv::Mat vChannel = cv::Mat::zeros(cv::Size(img.cols/2, img.rows/2), CV_8UC1);
    cv::Mat uChannel = cv::Mat::zeros(cv::Size(img.cols/2, img.rows/2), CV_8UC1);

    for(int y = img.rows; y < img.rows + img.rows/4; y++){
        for(int x = 0; x < img.cols; x++){
            if(x < img.cols / 2) {
                vChannel.at<uchar>(cv::Point(x, (y - img.rows)*2 )) = yuv.at<uchar>(cv::Point(x,y));
            } else {
                vChannel.at<uchar>(cv::Point(x - img.cols/2, (y - img.rows)*2 +1 )) = yuv.at<uchar>(cv::Point(x,y));
            }
        }
    }

    for(int y = img.rows + img.rows/4; y < img.rows + img.rows/2; y++){
        for(int x = 0; x < img.cols; x++){
            if(x < img.cols / 2) {
                uChannel.at<uchar>(cv::Point(x, (y - img.rows - img.rows/4)*2 )) = yuv.at<uchar>(cv::Point(x,y));
            } else {
                uChannel.at<uchar>(cv::Point(x - img.cols/2, (y - img.rows - img.rows/4)*2 +1 )) = yuv.at<uchar>(cv::Point(x,y));
            }
        }
    }

    cv::Rect r(0, 0, img.cols, img.rows);

    cv::Mat yChannel = yuv(r);

    cv::imshow("vChannel", vChannel);
    cv::imshow("uChannel", uChannel);
    cv::imshow("yChannel", yChannel);

    //3. convert separate channels back to RGB
    cv::Mat uvChannel;
    std::vector<cv::Mat> uvVector;
    uvVector.push_back(vChannel);
    uvVector.push_back(uChannel);

    // next will produce merged uv channel which is 2-channel "image".
    // unfortunately we can't see it with cv::imshow() because imshow can display
    // either 3 channel color image of 1 channel grayscale image.
    cv::merge(uvVector, uvChannel);

    // combine yChannel and uvChannel to create 3 channel image we can display
    cv::Mat result;
    cv::cvtColorTwoPlane(yChannel, uvChannel, result, cv::COLOR_YUV2BGR_NV12);
    cv::imshow("result", result);

    cv::waitKey();
    return 0;
}