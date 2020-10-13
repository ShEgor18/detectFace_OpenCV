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

    //1. Load the cascades
    if (!face_cascade.load(face_cascade_name))
    {
        cout << "Error loading face cascade!\n";
        return -1;
    };

    //2. Upload image
    Mat image = imread("C:/test2.jpg");
    while(1)
    { 
        if (image.empty())
        {
            cout << "Couldn't find or open the file!\n";
            break;
        }
        detectAndDisplay(image, face_cascade);
        if (waitKey(10) == 27)
        {
            break; // escape
        }
    }

    return 0;
}