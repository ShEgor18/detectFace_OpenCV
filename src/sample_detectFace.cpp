// Copyright 2020 Shulman Egor
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include "../include/detectFace.h"

using namespace std;
using namespace cv;
using namespace samples;

int main()
{
    CascadeClassifier face_cascade;
    String face_cascade_name = findFile("data/haarcascades/haarcascade_frontalface_alt.xml");
    int mode = 0;
   
    //1. Load the cascades
    if (!face_cascade.load(face_cascade_name))
    {
        cout << "Error loading face cascade!\n";
        return -1;
    };


    //2. Mode selection
    Mat image;
    VideoCapture capture;
    mode = SelectingOperatingMode(); // 1 - Photo || 2 - Camera
    switch (mode)
    {
    case 1:
        //2.1 Upload image
        image = imread("C:/test2.jpg");
        while (1)
        {
            detectAndDisplay(image, face_cascade);
        }
        break;

    case 2:
        //2.2 Read the video stream
        capture.open(0);
        if (!capture.isOpened())
        {
            cout << "Error opening video capture\n";
            return -1;
        }
        while (capture.read(image))
        {
            detectAndDisplay(image, face_cascade);
        }
        break; 

    default:
        cout << "Exit\n";
        return -1;
        break;
    }
    return 0;
}