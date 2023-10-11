#include <bits/stdc++.h>
#include <fstream>
#include "bmplib.h"
#include "Functions.h"
using namespace std;
unsigned char imageBMP[SIZE][SIZE];  //the image to be processed
unsigned char mergeBMP[SIZE][SIZE];  // the image that will be merged
unsigned char flipBMP[SIZE][SIZE];  // the image that will be merged
unsigned char imageT[SIZE][SIZE];    //transposed image used for the rotate filter
unsigned char q1[SIZE/2][SIZE/2];   //2d arrays to store the image divided into quarters
unsigned char q3[SIZE/2][SIZE/2];
unsigned char q4[SIZE/2][SIZE/2];
unsigned char q2[SIZE/2][SIZE/2];
char basePath[]="./Images/";
//function to display the choices
void displayChoices(){
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


void loadImage(){
    char fileName[100];
    char basePath[]="D:\\GitHub\\Image_Processing\\cmake-build-debug\\Images\\";
    cout<<"Hello Please enter the image file name to process: \n";
    cin>>fileName;
    strcat(basePath,fileName); //concatenating the base path to the file name to the extension
    strcat(basePath,".bmp");
    readGSBMP(basePath,imageBMP);   //loads the image into imageBMP 2d array
}

void saveImage(){
    char newFileName[100];
    cout<<"Enter the new file name\n";
    cin>>newFileName;
    strcat(basePath,newFileName);
    strcat(basePath,".bmp");
    writeGSBMP(basePath,imageBMP); //saves the image in imageBMP 2d array
}
//function to invert the image colors
void InvertImage(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]=255-imageBMP[i][j];
        }
    }
}
//function used in the rotate function
void Transpose(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageT[i][j]=imageBMP[j][i];
        }
    }
}
//function that turns the image into black and white
void BlackWhite(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(imageBMP[i][j] <127){
                imageBMP[i][j]=0;
            }else{
                imageBMP[i][j]=255;
            }
        }
    }
}
//function that divides the image array into 4 quarters to be used in shuffle and enlarge and shrink filters
void Divide4(){
    for(int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i<(SIZE/2)&&j<(SIZE/2)){
                q1[i][j]=imageBMP[i][j];
            }
            else if(i<(SIZE/2)&&j>=(SIZE/2)){
                q2[i][j-(SIZE/2)]= imageBMP[i][j];
            }
            else if(i>=(SIZE/2)&&j<(SIZE/2)){
                q3[i-(SIZE/2)][j]= imageBMP[i][j];
            }
            else if(i>=(SIZE/2)&&j>=(SIZE/2)){
                q4[i-(SIZE/2)][j-(SIZE/2)]= imageBMP[i][j];
            }
        }
    }
}
//function to merge 2 images together
void MergeImage(){
    char mergeName[100];
    cout<<"Please enter the name of image file to merge with:\n";
    cin>>mergeName;
    strcat(basePath,mergeName);
    strcat(basePath,".bmp");
    readGSBMP(basePath,mergeBMP);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imageBMP[i][j] = (imageBMP[i][j] + mergeBMP[i][j])/2; //takes the average of the GS value of each pixel of the two images
        }
    }

}
//function that darkens the image by 50%
void Darken(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]=imageBMP[i][j]-imageBMP[i][j]/2; //darkens it by 50%
        }
    }
}
//function that lightens the image by 50%
void Lighten(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]=imageBMP[i][j]+imageBMP[i][j]/2; //lightens the image by 50%
        }
    }
}
//function that copies flipped image to the image array
void FlipToImage(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]=flipBMP[i][j];
        }
    }
}
void FlipImageVertically(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            flipBMP[i][j]=imageBMP[SIZE-i][j];
        }
    }
    FlipToImage();
}
void FlipImageHorizontally(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            flipBMP[i][j]=imageBMP[i][SIZE-j];
        }
    }
    FlipToImage();
}
//void Rotate270(){
//    Transpose();
//    FlipImageVertically();
//}
//void RotateImage(int degree){
//    if(degree==90){
//        Rotate270();
//        FlipImageVertically();
//        FlipImageHorizontally();
//    }else if(degree==180){
//        FlipImageVertically();
//        FlipImageHorizontally();
//    }else if(degree==270){
//        Rotate270();
//    }
//}
void EnlargeImage(int quarter){
    Divide4();
    switch(quarter){
        case 1:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q1[i/2][j/2];
                }
            }
            break;
        case 2:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q2[i/2][j/2];
                }
            }
            break;
        case 3:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q3[i/2][j/2];
                }
            }
            break;
        case 4:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q4[i/2][j/2];
                }
            }
            break;
    }
}
void ShuffleImage(){
    int order[4];
    cout<<"Enter the new order of quarters\n";
    for(int i =0;i<4;i++){
        cin>>order[i];
    }
    Divide4();
    for(int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i<(SIZE/2)&&j<(SIZE/2)){ //1st quarter
                switch(order[0]){
                    case 1:
                        imageBMP[i][j]=q1[i][j];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i][j];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i][j];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i][j];
                        break;
                }
            }
            else if(i<(SIZE/2)&&j>=(SIZE/2)){ //2nd quarter
                switch(order[1]){
                    case 1:
                        imageBMP[i][j]=q1[i][j-128];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i][j-128];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i][j-128];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i][j-128];
                        break;
                }
            }
            else if(i>=(SIZE/2)&&j<(SIZE/2)){ //3rd quarter
                switch(order[2]){
                    case 1:
                        imageBMP[i][j]=q1[i-128][j];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i-128][j];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i-128][j];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i-128][j];
                        break;
                }
            }
            else if(i>=(SIZE/2)&&j>=(SIZE/2)){ //4th quarter
                switch(order[3]){
                    case 1:
                        imageBMP[i][j]=q1[i-128][j-128];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i-128][j-128];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i-128][j-128];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i-128][j-128];
                        break;
                }
            }
        }
    }

}
void SkewHorizontally(){
    //input the degree and convert to radian
    //double mov=tan(rad)*256
           // double step=mov/SIZE;
        //    2d arr[size][size+mov]=we want the empty pixels to be white;
//            for(int i to size){
//                for(int j to size+mov){
//                    2d arr[i][j+mov]=image[i][j];
//
//                }
//mov-=step;
//            }
//            for(i to size){
//                for(j to size){
//                    image[i][j]=2d arr[i][j]
//                }
//            }
}
void initChoice(char choice){
    switch (choice){
        case '1':
            BlackWhite();
            break;
        case '2':
            InvertImage();
            break;
        case '3':
            MergeImage();
            break;
        case '4':
            char hv;
            cout<<"Flip (h)orizontally or (v)ertically? \n";
            cin>>hv;
            if(hv=='h'){
                FlipImageHorizontally();
            }else{
                FlipImageVertically();
            };
            break;
        case '5':
            char dl;
            cout<<"(d)arken or (l)ighten? \n";
            cin>>dl;
            if(dl=='d'){
                Darken();
            }else{
                Lighten();
            };
            break;
//        case '6':
//            int degree;
//            cout<<"Rotate (90) or (180) or (270)? \n"; // if 180 use flip, also the 270 is flip of 90
//            cin>>degree;
//            RotateImage(degree);
//            break;
//            break;
        case '7': //detect image edges
        case '8':
            int quarter;
            cout<<"Enlarge quarter 1, 2, 3, or 4?\n";
            cin>>quarter;
            EnlargeImage(quarter);
            break;
        case '9':
            int sh;
            //cout<<
            break;
//        case 'a': flip
//            break;
        case 'b':
            ShuffleImage();
            break;
//        case 'c': blur
//            break;
//        case 'd': crop
//            break;
//        case 'e': skew right
//            SkewHorizontally();
//            break;
//        case 'f': skew up
//            break;
        case 's':
            saveImage();
            break;
    }
}

