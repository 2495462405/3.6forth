//
//  main.cpp
//  test
//
//  Created by 徐亦燊 on 2020/2/28.
//  Copyright © 2020 徐亦燊. All rights reserved.
//

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
int main(int argc, const char * argv[]) {
    
    float histgram[256] = {};
    int all=0;
    cv:: Mat dispMat(256,256,CV_8UC3);
    cv::Point pt1;
    cv::Point pt2;
    cv::Mat srcMat= cv::imread("/Users/xuyishen/Desktop/sa jiganyouhaximeiyouga/2020.3.6/RGBFour/RGB.png");
        int height = srcMat.rows;
        int width = srcMat.cols;
        for (int j=0; j<height; j++){
        for (int i = 0; i<width; i++) {
            uchar average =  0.2989*srcMat.at<Vec3b>(j, i)[0] + 0.5870*srcMat.at<Vec3b>(j, i)[1] + 0.1140*srcMat.at<Vec3b>(j, i)[2];
            histgram [average] = histgram [average]+1;
            all=all+1;
        }
            
        }
    for (int b=0;b<256;b++)
        {
            histgram[b]=histgram[b]/all*3000;
            pt1.x=b;
            pt1.y=256;
            pt2.x=b;
            pt2.y=256-histgram[b];
          line(dispMat,pt1,pt2,CV_RGB(0,255,0),1,8,0);
        }
        cv::imshow("srcMat", srcMat);
        cv::imshow("dispMat", dispMat);
        waitKey(0);
        return 0;

    }
