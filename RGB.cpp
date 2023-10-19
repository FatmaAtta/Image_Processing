//
// Created by fatma on 09/10/2023.
//
#include <bits/stdc++.h>
#include <fstream>
#include "bmplib.h"
#include "RGB.h"
using namespace std;
unsigned char imageRGBBMP[SIZE][SIZE][3];  //the image to be processed
unsigned char mergeRGBBMP[SIZE][SIZE][3];  // the image that will be merged
unsigned char flipRGBBMP[SIZE][SIZE][3];  // the image that will be flipped
unsigned char shrinkRGBBMP[SIZE][SIZE][3];  // the image that will be flipped
unsigned char imageRGBT[SIZE][SIZE][3];    //transposed image used for the rotate filter
unsigned char imageRGBSkew[SIZE][SIZE][3];    //array to store the skewed image
unsigned char q1RGB[SIZE / 2][SIZE / 2][3];   //2d arrays to store the image divided into quarters
unsigned char q2RGB[SIZE / 2][SIZE / 2][3];
unsigned char q3RGB[SIZE / 2][SIZE / 2][3];
unsigned char q4RGB[SIZE / 2][SIZE / 2][3];
char basePath2[]="./Images/";
//function to display the choices
void RGBdisplayChoices(){
    cout<<" 1- Black & White Filter\n "
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

void RGBinitChoice(char choice){
    switch (choice){
        case '1':
            RGBBlackWhite();
            break;
        case '2':
            RGBInvertImage();
            break;
        case '3':
            RGBMergeImage();
            break;
        case '4':
            char hv;
            cout<<"Flip (h)orizontally or (v)ertically? \n";
            cin>>hv;
            if(hv=='h'){
                RGBFlipImageHorizontally();
            }else{
                RGBFlipImageVertically();
            };
            break;
        case '5':
            char dl;
            cout<<"(d)arken or (l)ighten? \n";
            cin>>dl;
            if(dl=='d'){
                RGBDarken();
            }else{
                RGBLighten();
            };
            break;
        case '6':
            int degree;
            cout<<"Rotate (90) or (180) or (270)? \n"; // if 180 use flip, also the 270 is flip of 90
            cin>>degree;
            RGBRotateImage(degree);
            break;
        case '7':
            RGBDetectImageEdges();
            break;
        case '8':
            int quarter;
            cout<<"Enlarge quarter 1, 2, 3, or 4?\n";
            cin>>quarter;
            RGBEnlargeImage(quarter);
            break;
        case '9':
            int sh;
            cout<<"Shrink to half (2) or third (3) or quarter (4)?\n";
            cin>>sh;
            RGBShrink(sh);
            break;
        case 'a':
            RGBmirrorImage();
            break;
        case 'b':
            RGBShuffleImage();
            break;
//        case 'c': blur
//            break;
//        case 'd': crop
            break;
//        case 'e':
//            SkewHorizontally();
//            break;
//        case 'f': skew up
//            break;
        case 's':
            RGBsaveImage();
            break;
    }
}

void RGBloadImage(){
    char fileName[100];
    cout<<"Hello Please enter the image file name to process: \n";
    cin>>fileName;
    strcat(basePath2,fileName); //concatenating the base path to the file name to the extension
    strcat(basePath2,".bmp");
    readRGBBMP(basePath2,imageRGBBMP);   //loads the image into imageRGBBMP 2d array
}
void RGBsaveImage(){
    char basePath5[]="./Images/";
    char newFileName[100];
    cout<<"Enter the new file name\n";
    cin>>newFileName;
    strcat(basePath5,newFileName);
    strcat(basePath5,".bmp");
    writeRGBBMP(basePath5,imageRGBBMP); //saves the image in imageRGBBMP 2d array
}
void RGBToImage(unsigned char arr[SIZE][SIZE][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                imageRGBBMP[j][k][i]=arr[j][k][i];
            }
        }
    }
}
void RGBWhiteBackground(unsigned char arr[SIZE][SIZE][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                arr[j][k][i]=255;
            }
        }
    }
}
//function used in the rotate function
void RGBTranspose(){
    for(int i=0;i<3;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                imageRGBT[j][k][i]=imageRGBBMP[k][j][i];
            }
        }
    }
    RGBToImage(imageRGBT);
}
//function that divides the image array into 4 quarters to be used in shuffle and enlarge and shrink filters
void RGBDivide4(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                if(i<(SIZE/2)&&j<(SIZE/2)){
                    q1RGB[i][j][k]=imageRGBBMP[i][j][k];
                }
                else if(i<(SIZE/2)&&j>=(SIZE/2)){
                    q2RGB[i][j - (SIZE / 2)][k]= imageRGBBMP[i][j][k];
                }
                else if(i>=(SIZE/2)&&j<(SIZE/2)){
                    q3RGB[i - (SIZE / 2)][j][k]= imageRGBBMP[i][j][k];
                }
                else if(i>=(SIZE/2)&&j>=(SIZE/2)){
                    q4RGB[i - (SIZE / 2)][j - (SIZE / 2)][k]= imageRGBBMP[i][j][k];
                }
            }
        }
    }
}
//function that turns the image into black and white
void RGBBlackWhite(){
    int sum=0,average;
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            sum=0;
            for(int k=0;k<3;k++){
                sum+=imageRGBBMP[i][j][k];
            }
            average=sum/3;
            if(average<128){
                for(int k=0;k<3;k++){
                    imageRGBBMP[i][j][k]=0;
                }
            }
            else
                for(int k=0;k<3;k++){
                    imageRGBBMP[i][j][k]=255;
                }

        }
    }
}
//function to invert the image colors
void RGBInvertImage(){
    for(int i=0;i<3;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                imageRGBBMP[j][k][i]= 255 - imageRGBBMP[j][k][i];
            }
        }
    }
}
//function to merge 2 images together
void RGBMergeImage(){
    char basePath3[]="./Images/";
    char mergeName[100];
    cout<<"Please enter the name of image file to merge with:\n";
    cin>>mergeName;
    strcat(basePath3,mergeName);
    strcat(basePath3,".bmp");
    readRGBBMP(basePath3,mergeRGBBMP);

    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                imageRGBBMP[i][j][k]=(imageRGBBMP[i][j][k]+mergeRGBBMP[i][j][k])/2;
            }
        }
    }

}
//function that copies flipped image to the image array
void RGBFlipImageVertically(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                flipRGBBMP[i][j][k]=imageRGBBMP[SIZE-i][j][k];
            }
        }
    }
    RGBToImage(flipRGBBMP);
}
void RGBFlipImageHorizontally(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                flipRGBBMP[i][j][k]=imageRGBBMP[i][SIZE-j][k];
            }
        }
    }
    RGBToImage(flipRGBBMP);
}
//function that darkens the image by 50%
void RGBDarken(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                imageRGBBMP[i][j][k]-=imageRGBBMP[i][j][k]/2;
            }
        }
    }
}

//function that lightens the image by 50%
void RGBLighten(){
    for(int i=0;i<3;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<SIZE;k++){
                imageRGBBMP[i][j][k]+=imageRGBBMP[i][j][k]/2;
            }
        }
    }
}
void RGBRotate270(){
    RGBTranspose();
    RGBFlipImageVertically();
}
void RGBRotateImage(int degree){
    if(degree==90){
        RGBRotate270();
        RGBFlipImageVertically();
        RGBFlipImageHorizontally();
    }else if(degree==180){
        RGBFlipImageVertically();
        RGBFlipImageHorizontally();
    }else if(degree==270){
        RGBRotate270();
    }
}
void RGBDetectImageEdges(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                if(imageRGBBMP[i+1][j+1][k]-imageRGBBMP[i][j][k]>45){
                    imageRGBBMP[i][j][k]=0;
                }
                else if(imageRGBBMP[i][j][k]-imageRGBBMP[i+1][j+1][k]>45){
                    imageRGBBMP[i][j][k]=0;
                }
                else{
                    imageRGBBMP[i][j][k]=255;
                }
            }
        }
    }
}
void RGBEnlargeImage(int quarter){
    RGBDivide4();
    switch(quarter){
        case 1:
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    for(int k=0;k<3;k++){
                        imageRGBBMP[i][j][k]=q1RGB[i / 2][j / 2][k];
                    }
                }
            }
            break;
        case 2:
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    for(int k=0;k<3;k++){
                        imageRGBBMP[i][j][k]=q2RGB[i / 2][j / 2][k];
                    }
                }
            }
            break;
        case 3:
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    for(int k=0;k<3;k++){
                        imageRGBBMP[i][j][k]=q3RGB[i / 2][j / 2][k];
                    }
                }
            }
            break;
        case 4:
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    for(int k=0;k<3;k++){
                        imageRGBBMP[i][j][k]=q4RGB[i / 2][j / 2][k];
                    }
                }
            }
            break;
    }
}
void RGBShrink(int sh){
    RGBWhiteBackground(shrinkRGBBMP);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                shrinkRGBBMP[i / sh][j / sh][k]= (imageRGBBMP[i][j][k] + imageRGBBMP[i][j + 1][k] + imageRGBBMP[i + 1][j][k] + imageRGBBMP[i + 1][j + 1][k]) / 4;
            }
        }
    }
    RGBToImage(shrinkRGBBMP);
}
void RGBmirrorImage(){
    char a;
    cout<<"Mirror (l)eft, (r)ight, (u)pper or (d)own\n";
    cin>>a;
    if(a=='r'||a=='R') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                for(int k=0;k<3;k++){
                    imageRGBBMP[i][j][k] = imageRGBBMP[i][ 255-j][k];
                }
            }
        }
    }
    if(a=='l'||a=='L') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 255; j > SIZE/2; --j) {
                for(int k=0;k<3;k++){
                    imageRGBBMP[i][j][k] = imageRGBBMP[i][255-j][k];
                }
            }
        }
    }
    if(a=='d'||a=='D') {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                for(int k=0;k<3;k++){
                    imageRGBBMP[i][j][k] = imageRGBBMP[255-i][ j][k];
                }
            }
        }
    }
    if(a=='u'||a=='U') {
        for (int i = 255; i > SIZE/2; --i) {
            for (int j = 0; j < SIZE; ++j) {
                for(int k=0;k<3;k++){
                    imageRGBBMP[i][j][k] = imageRGBBMP[255-i][j][k];
                }
            }
        }
    }

}
void RGBShuffleImage(){
    int order[4];
    cout<<"Enter the new order of quarters\n";
    for(int i =0;i<4;i++){
        cin>>order[i];
    }
    RGBDivide4();
    for(int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            for(int k=0;k<3;k++){
                if(i<(SIZE/2)&&j<(SIZE/2)){ //1st quarter
                    switch(order[0]){
                        case 1:
                            imageRGBBMP[i][j][k]=q1RGB[i][j][k];
                            break;
                        case 2:
                            imageRGBBMP[i][j][k]=q2RGB[i][j][k];
                            break;
                        case 3:
                            imageRGBBMP[i][j][k]=q3RGB[i][j][k];
                            break;
                        case 4:
                            imageRGBBMP[i][j][k]=q4RGB[i][j][k];
                            break;
                    }
                }
                else if(i<(SIZE/2)&&j>=(SIZE/2)){ //2nd quarter
                    switch(order[1]){
                        case 1:
                            imageRGBBMP[i][j][k]=q1RGB[i][j - 128][k];
                            break;
                        case 2:
                            imageRGBBMP[i][j][k]=q2RGB[i][j - 128][k];
                            break;
                        case 3:
                            imageRGBBMP[i][j][k]=q3RGB[i][j - 128][k];
                            break;
                        case 4:
                            imageRGBBMP[i][j][k]=q4RGB[i][j - 128][k];
                            break;
                    }
                }
                else if(i>=(SIZE/2)&&j<(SIZE/2)){ //3rd quarter
                    switch(order[2]){
                        case 1:
                            imageRGBBMP[i][j][k]=q1RGB[i - 128][j][k];
                            break;
                        case 2:
                            imageRGBBMP[i][j][k]=q2RGB[i - 128][j][k];
                            break;
                        case 3:
                            imageRGBBMP[i][j][k]=q3RGB[i - 128][j][k];
                            break;
                        case 4:
                            imageRGBBMP[i][j][k]=q4RGB[i - 128][j][k];
                            break;
                    }
                }
                else if(i>=(SIZE/2)&&j>=(SIZE/2)){ //4th quarter
                    switch(order[3]){
                        case 1:
                            imageRGBBMP[i][j][k]=q1RGB[i - 128][j - 128][k];
                            break;
                        case 2:
                            imageRGBBMP[i][j][k]=q2RGB[i - 128][j - 128][k];
                            break;
                        case 3:
                            imageRGBBMP[i][j][k]=q3RGB[i - 128][j - 128][k];
                            break;
                        case 4:
                            imageRGBBMP[i][j][k]=q4RGB[i - 128][j - 128][k];
                            break;
                    }
                }
            }
        }
    }
}
