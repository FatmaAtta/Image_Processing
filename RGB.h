//
// Created by fatma on 09/10/2023.
//

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
void RGBShuffleImage();


#endif //IMAGE_PROCESSING_RGB_H
