//
// Created by fatma on 06/10/2023.
//

#ifndef IMAGE_PROCESSING_FUNCTIONS_H
#define IMAGE_PROCESSING_FUNCTIONS_H
void displayChoices();
void loadImage();
void ToImage(unsigned char arr[SIZE][SIZE]);
void saveImage();
void WhiteBackground(unsigned char arr[SIZE][SIZE]);
void BlackWhite();
void InvertImage();
void Transpose();
void Shrink(int sh);
void Divide4();
void MergeImage();
void Darken();
void Lighten();
void FlipImageVertically();
void FlipImageHorizontally();
void Rotate270();
void RotateImage(int degree);
void EnlargeImage(int degree);
void ShuffleImage();
void SkewHorizontally();
void initChoice(char choice);
#endif //IMAGE_PROCESSING_FUNCTIONS_H
