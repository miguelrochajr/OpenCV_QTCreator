#ifndef OPENCVIEW_H
#define OPENCVIEW_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include "targetfinder.h"
#include <QWidget>

using namespace cv;

class OpenCview : public QWidget
{
    Q_OBJECT

public:
    explicit OpenCview(QWidget *parent = 0);
    void FindTarget(Mat &M);
    int H_MEAN, S_MEAN, V_MEAN; // Mean values for HSV - Hue, Saturatoin and Value
    int H_SD, S_SD, V_SD;// SD means the Standarized deviatio
signals:
    
public slots:
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
private:
    Mat Raw_Image, Display_Image; //Display Image is the image that is going to be displayed
    VideoCapture cap;
    TargetFinder Target;
    Point corner1, corner2; //coordinates for two opposite corners of an rectangle of interest. Here we have two points: (x0, y0) and (x1, y1)
    bool selectMode, flag_Process;

};

#endif // OPENCVIEW_H
