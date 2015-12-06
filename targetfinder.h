#ifndef TARGETFINDER_H
#define TARGETFINDER_H

#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <string>
#include <cstring>
#include <sstream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

using namespace cv;
using namespace std;

class TargetFinder
{
private:
    double H_MEAN, S_MEAN, V_MEAN; // Mean values for HSV - Hue, Saturatoin and Value
    double H_SD, S_SD, V_SD;// SD means the Standarized deviatio
    double samples; //number of Pixels into the ROI
    Point corner1, corner2;
    double H_MIN, H_MAX, S_MIN, S_MAX, V_MIN, V_MAX;


public:
    TargetFinder();
    Mat Find_Target(Mat Raw_Image, Point corner1, Point corner2);
    void Standarized_Deviation(Mat &ROI_Image);
    void Mean(Mat &ROI_Image);
    void DrawObject (int x, int y, Mat &frame);
    void morphOps(Mat &thresh);
    void trackFilteredObject(int &x, int &y, Mat threshold, Mat &cameraFeed);
    void recordHSV_Values(Mat &GivenImage, int &H_MIN, int &H_MAX, int &S_MIN, int &S_MAX, int &V_MIN, int &V_MAX);
    void setCorners(Point c1, Point c2);
    void setHSV_Range(double &precision);
    string intToString(int number);

    void MainEngine(Mat &GivenImage, Point c1, Point c2);

};

#endif // TARGETFINDER_H
