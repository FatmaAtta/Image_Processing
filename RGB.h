// Created by fatma on 09/10/2023.
//FCAI - OOP Programming - 2023 - Assignment 1
//Program Name: main.cpp
//Last Modification Date: 10/5/2023
//Purpose: Using a bitmap library to convert an image into an array in order to apply some filters on it
//version 2.0 RGB
//Fatma Mahmoud Atta 20220510
//Shahd Mohammed Ahmed 20220533
//Reham Fawzy 20220141
//fatmamaali@gmail.com
//shahdelnassag@gmail.com
//fwrymw@gmail.com

#ifndef IMAGE_PROCESSING_RGB_H
#define IMAGE_PROCESSING_RGB_H

void RGBdisplayChoices();
void RGBinitChoice(char choice);
void RGBloadImage();
void RGBsaveImage();
void RGBToImage(unsigned char arr[SIZE][SIZE][3]);
void RGBWhiteBackground(unsigned char arr[SIZE][SIZE][3]);
void RGBTranspose();
void RGBDivide4();
void RGBBlackWhite();
void RGBInvertImage();
void RGBMergeImage();
void RGBFlipImageVertically();
void RGBFlipImageHorizontally();
void RGBDarken();
void RGBLighten();
void RGBRotate270();
void RGBDetectImageEdges();
void RGBRotateImage(int degree);
void RGBEnlargeImage(int degree);
void RGBShrink(int sh);
void RGBmirrorImage();
void RGBShuffleImage();
void RGBblurImage();
void RGBcropImage();
void RGBskewHorizontally();
void RGBskewVertically();

#endif //IMAGE_PROCESSING_RGB_H
