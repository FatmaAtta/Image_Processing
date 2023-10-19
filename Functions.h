//FCAI - OOP Programming - 2023 - Assignment 1
//Program Name: main.cpp
//Last Modification Date: 10/5/2023
//Purpose: Using a bitmap library to convert an image into an array in order to apply some filters on it
//version 1.0 grayscale
//Fatma Mahmoud Atta 20220510
//Shahd Mohammed Ahmed 20220533
//Reham Fawzy 20220141
//fatmamaali@gmail.com
//shahdelnassag@gmail.com
//fwrymw@gmail.com

#ifndef IMAGE_PROCESSING_FUNCTIONS_H
#define IMAGE_PROCESSING_FUNCTIONS_H

void displayChoices();
void initChoice(char choice);
void loadImage();
void saveImage();
void ToImage(unsigned char arr[SIZE][SIZE]);
void WhiteBackground(unsigned char arr[SIZE][SIZE]);
void Transpose();
void Divide4();
void BlackWhite();
void InvertImage();
void MergeImage();
void FlipImageVertically();
void FlipImageHorizontally();
void Darken();
void Lighten();
void Rotate270();
void RotateImage(int degree);
void detectImageEdges();
void EnlargeImage(int degree);
void Shrink(int sh);
void mirrorImage();
void ShuffleImage();
void blurImage();
void cropImage();
void skewHorizontally();
void skewVertically();

#endif //IMAGE_PROCESSING_FUNCTIONS_H
