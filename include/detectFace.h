// Copyright 2020 Shulman Egor
#ifndef DETECTFACE_H
#define DETECTFACE_H
#include "opencv2/objdetect.hpp"

void detectAndDisplay(cv::Mat image, cv::CascadeClassifier face_cascade);

#endif  // DETECTFACE_H