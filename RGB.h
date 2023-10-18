//
// Created by fatma on 09/10/2023.
//

#ifndef IMAGE_PROCESSING_RGB_H
#define IMAGE_PROCESSING_RGB_H

void RGBdisplayChoices();
void RGBloadImage();
void RGBToImage(unsigned char arr[SIZE][SIZE][3]);
void RGBsaveImage();
void RGBWhiteBackground(unsigned char arr[SIZE][SIZE][3]);
void RGBBlackWhite();
void RGBInvertImage();
void RGBTranspose();
void RGBShrink(int sh);
void RGBDivide4();
void RGBMergeImage();
void RGBDarken();
void RGBLighten();
void RGBFlipImageVertically();
void RGBFlipImageHorizontally();
void RGBRotate270();
void RGBRotateImage(int degree);
void RGBEnlargeImage(int degree);
void RGBShuffleImage();
void RGBSkewHorizontally();
void RGBinitChoice(char choice);

#endif //IMAGE_PROCESSING_RGB_H
