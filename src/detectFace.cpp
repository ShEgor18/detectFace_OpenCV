// Copyright 2020 Shulman Egor
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include "../include/detectFace.h"

using namespace std;
using namespace cv;
using namespace samples;

void detectAndDisplay(Mat image, CascadeClassifier face_cascade)
{
    Mat frame_gray;
    cvtColor(image, frame_gray, COLOR_BGR2GRAY); // Convert image to grayscale because faceDetector requires grayscale image.

    equalizeHist(frame_gray, frame_gray); // equalize histograms of images

    //Detect faces
    vector<Rect> faces;
    vector< vector<Point2f> > landmarks;
    face_cascade.detectMultiScale(frame_gray, faces);
    for (int i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
        rectangle(image, faces[i], Scalar(0, 0, 255), 2);
        Mat faceROI = frame_gray(faces[i]);
    }
    imshow("Search of persons", image);
}