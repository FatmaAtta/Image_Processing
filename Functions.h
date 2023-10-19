//
// Created by fatma on 06/10/2023.
//

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
