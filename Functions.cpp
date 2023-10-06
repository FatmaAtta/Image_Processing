#include <bits/stdc++.h>
#include <fstream>
#include "bmplib.h"
#include "Functions.h"
using namespace std;
unsigned char imageBMP[SIZE][SIZE];
void displayChoices(){
    cout<<"1- Black & White Filter\n "
          "2- Invert Colors\n "
          "3- Merge Two Images\n "
          "4- Flip Image \n "
          "5- Darken or Lighten \n "
          "6- Rotate Image \n "
          "7- Detect Image Edges \n "
          "8- Enlarge Image \n "
          "9- Shrink Image \n "
          "a- Mirror 1/2 Image \n "
          "b- Shuffle Image \n "
          "c- Blur Image \n "
          "d- Crop Image \n "
          "e- Skew Image Right \n "
          "f- Skew Image Up \n "
          "s- Save The New Image \n "
          "0- Exit \n";
}
void loadImage(){
    char fileName[100];
    cout<<"Please enter the image file name to process\n";
    cin>>fileName;
    strcat(fileName,".bmp");
    readGSBMP(fileName,imageBMP);
}
void saveImage(){
    char newFileName[100];
    cout<<"Enter the new file name\n";
    cin>>newFileName;
    strcat(newFileName,".bmp");
    writeGSBMP(newFileName,imageBMP);
}
void InvertImage(){

}
void Transpose(){

}
void BlackWhite(){
    for(int i=0;i<256;i++){
        for(int j=0;j<256;j++){
            if(imageBMP[i][j] <128){
                imageBMP[i][j]=0;
            }else{
                imageBMP[i][j]=255;
            }
        }
    }
}
void Divide4(){

}
void Darken(){

}
void Lighten(){

}
void FlipImageVertically(){}
void FlipImageHorizontally(){}
void Rotate270(){
    Transpose();
    FlipImageVertically();
}
void RotateImage(int degree){
    if(degree==90){
        Rotate270();
        FlipImageVertically();
        FlipImageHorizontally();
    }else if(degree==180){
        FlipImageVertically();
        FlipImageHorizontally();
    }else if(degree==270){
        Rotate270();

    }
}
void EnlargeImage(){
    Divide4();
}
void ShuffleImage(){
    Divide4();
}
void SkewHorizontally(){

}
void initChoice(char choice){
    switch (choice){
        case 1:
            BlackWhite();
            break;
//        case 2:
//            InvertImage();
//            break;
//        case 3:
//
            break;
        case 4:
            char hv;
            cout<<"Flip (h)orizontally or (v)ertically? \n";
            cin>>hv;
//            if(hv=='h'){
//                FlipImageHorizontally();
//            }else{
//                FlipImageVertically();
//            };
            break;
        case 5:
            char dl;
            cout<<"(d)arken or (l)ighten? \n";
            cin>>dl;
//            if(dl=='d'){
//                Darken();
//            }else{
//                Lighten();
//            };
            break;
        case 6:
            int degree;
            cout<<"Flip (90) or (180) or (270)? \n"; // if 180 use flip, also the 270 is flip of 90
            cin>>degree;
//            RotateImage(degree);
//            break;
//        case 7:
//            break;
//        case 8:
//            EnlargeImage();
//            break;
//        case 9:
//            break;
//        case 'a':
//            break;
//        case 'b':
//            ShuffleImage();
//            break;
//        case 'c':
//            break;
//        case 'd':
//            break;
//        case 'e':
//            SkewHorizontally();
//            break;
//        case 'f':
//            break;
        case 's':
            saveImage();
            break;
    }
}
