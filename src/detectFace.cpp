// Copyright 2020 Shulman Egor
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include "../include/detectFace.h"

using namespace std;
using namespace cv;
using namespace samples;

int SelectingOperatingMode()
{
    // 1 - Photo || 2 - Camera
    int mode = 0;
    cout << "Select the operating mode:\n[1] - Photo\n[2] - Camera\n";
    cin >> mode;

    if (mode != 1 && mode != 2) {
        cout << "Mode error!\n";
        exit(-1);
    }

    return mode;
}

void detectAndDisplay(Mat image, CascadeClassifier face_cascade)
{
    Mat frame_gray;
    cvtColor(image, frame_gray, COLOR_BGR2GRAY); // Convert image to grayscale because faceDetector requires grayscale image.
    equalizeHist(frame_gray, frame_gray); // equalize histograms of images
    
    //Detect faces
    vector<Rect> faces;
    vector< vector<Point2f> > landmarks;

    if (image.empty())
    {
        cout << "Couldn't find or open the file!\n";
        return;
    }
    face_cascade.detectMultiScale(frame_gray, faces);
    for (int i = 0; i < faces.size(); i++)
    {
        Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
        rectangle(image, faces[i], Scalar(0, 0, 255), 2);
        Mat faceROI = frame_gray(faces[i]);
    }
    imshow("Search of persons", image);
    if (waitKey(10) == 27)
    {
        return; // escape
    }
}