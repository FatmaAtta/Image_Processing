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
#include <bits/stdc++.h>
#include <fstream>
#include "bmplib.h"
#include "Functions.h"
using namespace std;
unsigned char imageBMP[SIZE][SIZE];  //the image to be processed
unsigned char mergeBMP[SIZE][SIZE];  // the image that will be merged
unsigned char imageT[SIZE][SIZE];    //transposed imageBMP used for the rotate filter
unsigned char flipBMP[SIZE][SIZE];  // the imageBMP that will be flipped
unsigned char shrinkBMP[SIZE][SIZE];  // store the shrunken image
unsigned char croppedImage[SIZE][SIZE];    //2d array to store the cropped image
unsigned char imageSkew[SIZE][SIZE];    //array to store the skewed imageBMP
unsigned char imageblur[SIZE][SIZE];    //array to store the blurred image
unsigned char q1[SIZE / 2][SIZE / 2];   //2d arrays to store the imageBMP divided into quarters
unsigned char q3[SIZE / 2][SIZE / 2];   //
unsigned char q4[SIZE / 2][SIZE / 2];   //
unsigned char q2[SIZE / 2][SIZE / 2];   //
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
//function to choose
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
        case '6':
            int degree;
            cout<<"Rotate (90) or (180) or (270)? \n"; // if 180 use flip, also the 270 is flip of 90
            cin>>degree;
            RotateImage(degree);
            break;
        case '7':
            detectImageEdges();
            break;
        case '8':
            int quarter;
            cout<<"Enlarge quarter 1, 2, 3, or 4?\n";
            cin>>quarter;
            EnlargeImage(quarter);
            break;
        case '9':
            int sh;
            cout<<"Shrink to half (2) or third (3) or quarter (4)?\n";
            cin>>sh;
            Shrink(sh);
            break;
        case 'a':
            mirrorImage();
            break;
        case 'b':
            ShuffleImage();
            break;
        case 'c':
            blurImage();
            break;
        case 'd':
            cropImage();
            break;
        case 'e':
            skewHorizontally();
            break;
        case 'f':
            skewVertically();
            break;
        case 's':
            saveImage();
            break;
    }
}
//function to load the image
void loadImage(){
    char fileName[100];
//    char basePath[]="D:\\GitHub\\Image_Processing\\cmake-build-debug\\Images\\";
    cout<<"Hello Please enter the imageBMP file name to process: \n";
    cin>>fileName;
    strcat(basePath,fileName); //concatenating the base path to the file name to the extension
    strcat(basePath,".bmp");
    readGSBMP(basePath, imageBMP);   //loads the imageBMP into imageBMP 2d array
}
//funciton to save the image
void saveImage(){
    char basePath6[]="./Images/";
    char newFileName[100];
    cout<<"Enter the new file name\n";
    cin>>newFileName;
    strcat(basePath6,newFileName);
    strcat(basePath6,".bmp");
    writeGSBMP(basePath6, imageBMP); //saves the imageBMP in imageBMP 2d array
}
//function that copies the elements of a 3d array to the imageRGBBMP array
void ToImage(unsigned char arr[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]=arr[i][j];
        }
    }
}
void WhiteBackground(unsigned char arr[SIZE][SIZE]){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            arr[i][j]=255;
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
    ToImage(imageT);
}
//function that divides the imageBMP array into 4 quarters to be used in shuffle and enlarge and shrink filters
void Divide4(){
    for(int i =0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(i<(SIZE/2)&&j<(SIZE/2)){
                q1[i][j]=imageBMP[i][j];
            }
            else if(i<(SIZE/2)&&j>=(SIZE/2)){
                q2[i][j - (SIZE / 2)]= imageBMP[i][j];
            }
            else if(i>=(SIZE/2)&&j<(SIZE/2)){
                q3[i - (SIZE / 2)][j]= imageBMP[i][j];
            }
            else if(i>=(SIZE/2)&&j>=(SIZE/2)){
                q4[i - (SIZE / 2)][j - (SIZE / 2)]= imageBMP[i][j];
            }
        }
    }
}
//function that turns the imageBMP into black and white
void BlackWhite(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            if(imageBMP[i][j] < 127){
                imageBMP[i][j]=0;
            }else{
                imageBMP[i][j]=255;
            }
        }
    }
}
//function to invert the imageBMP colors
void InvertImage(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]= 255 - imageBMP[i][j];
        }
    }
}
//function to merge 2 images together
void MergeImage(){
    char basePath4[]="./Images/";
    char mergeName[100];
    cout<<"Please enter the name of imageBMP file to merge with:\n";
    cin>>mergeName;
    strcat(basePath4,mergeName);
    strcat(basePath4,".bmp");
    readGSBMP(basePath4, mergeBMP);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            imageBMP[i][j] = (imageBMP[i][j] + mergeBMP[i][j]) / 2; //takes the average of the GS value of each pixel of the two images
        }
    }

}
//function that flips the image vertically
void FlipImageVertically(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            flipBMP[i][j]=imageBMP[SIZE - i][j];
        }
    }
    ToImage(flipBMP);
}
//function that flips the image horizontally
void FlipImageHorizontally(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            flipBMP[i][j]=imageBMP[i][SIZE - j];
        }
    }
    ToImage(flipBMP);
}
//function that darkens the imageBMP by 50%
void Darken(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]= imageBMP[i][j] - imageBMP[i][j] / 2; //darkens it by 50%
        }
    }
}
//function that lightens the imageBMP by 50%
void Lighten(){
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            imageBMP[i][j]= imageBMP[i][j] + imageBMP[i][j] / 2; //lightens the imageBMP by 50%
        }
    }
}
//function that rotates images by 270 degrees
void Rotate270(){
    Transpose();
    FlipImageVertically();
}
//function that rotates an image by an inputted degree
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
//function that detects the image edges
void detectImageEdges(){
    for(int i=0;i<SIZE;++i){
        for(int j=0;j<SIZE ;++j){
            if(imageBMP[i+1][j+1]-imageBMP[i][j]>45){
                imageBMP[i][j]=0;
            }
            else if(imageBMP[i][j]-imageBMP[i+1][j+1]>45){
                imageBMP[i][j]=0;
            }
            else{
                imageBMP[i][j]=255;
            }
        }
    }
}
//function that enlarges a quarter of the image
void EnlargeImage(int quarter){
    Divide4();
    switch(quarter){
        case 1:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q1[i / 2][j / 2];
                }
            }
            break;
        case 2:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q2[i / 2][j / 2];
                }
            }
            break;
        case 3:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q3[i / 2][j / 2];
                }
            }
            break;
        case 4:
            for(int i =0;i<SIZE;i++){
                for(int j=0;j<SIZE;j++){
                    imageBMP[i][j]=q4[i / 2][j / 2];
                }
            }
            break;
    }
}
//function that shrinks the image to a specific size
void Shrink(int sh){
    WhiteBackground(shrinkBMP);
    for(int i=0;i<SIZE;i++){
        for(int j=0;j<SIZE;j++){
            shrinkBMP[i / sh][j / sh]= (imageBMP[i][j] + imageBMP[i][j + 1] + imageBMP[i + 1][j] + imageBMP[i + 1][j + 1]) / 4;
        }
    }
    ToImage(shrinkBMP);
}
//function that mirrors a half of the image
void mirrorImage(){
    char a;
    cout<<"Mirror (l)eft, (r)ight, (u)pper or (d)own\n";
    cin>>a;
    if(a=='r'||a=='R') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                imageBMP[i][j] = imageBMP[i][ 255-j];
            }
        }
    }
    if(a=='l'||a=='L') {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 255; j > SIZE/2; --j) {
                imageBMP[i][j] = imageBMP[i][255-j];
            }
        }
    }
    if(a=='d'||a=='D') {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                imageBMP[i][j] = imageBMP[255-i][ j];
            }
        }
    }
    if(a=='u'||a=='U') {
        for (int i = 255; i > SIZE/2; --i) {
            for (int j = 0; j < SIZE; ++j) {
                imageBMP[i][j] = imageBMP[255-i][j];
            }
        }
    }

}
//function that shuffles the quarters of an image
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
                        imageBMP[i][j]=q1[i][j - 128];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i][j - 128];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i][j - 128];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i][j - 128];
                        break;
                }
            }
            else if(i>=(SIZE/2)&&j<(SIZE/2)){ //3rd quarter
                switch(order[2]){
                    case 1:
                        imageBMP[i][j]=q1[i - 128][j];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i - 128][j];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i - 128][j];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i - 128][j];
                        break;
                }
            }
            else if(i>=(SIZE/2)&&j>=(SIZE/2)){ //4th quarter
                switch(order[3]){
                    case 1:
                        imageBMP[i][j]=q1[i - 128][j - 128];
                        break;
                    case 2:
                        imageBMP[i][j]=q2[i - 128][j - 128];
                        break;
                    case 3:
                        imageBMP[i][j]=q3[i - 128][j - 128];
                        break;
                    case 4:
                        imageBMP[i][j]=q4[i - 128][j - 128];
                        break;
                }
            }
        }
    }

}
//function that blurs the image
void blurImage(){

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            imageblur[i][j] = ( imageBMP[i-1][j-1] + imageBMP[i-1][j]+ imageBMP[i-1][j+1] +
                                imageBMP[i][j-1] + imageBMP[i][j] + imageBMP[i][j+1] +
                                imageBMP[i+1][j-1] + imageBMP[i+1][j] +imageBMP[i+1][j+1] ) /9;
        }
    }
    ToImage(imageblur);
}
//function that crops the image
void cropImage(){
    WhiteBackground(croppedImage);
    int x,y,l,w;
    cout<<"Please enter x, y, l, w:\n";
    cin >> x >> y>>l>>w;

    for(int i=x; i < SIZE-x; ++i){
        for(int j=y; j <SIZE-y; ++j){
            croppedImage[i][j]=imageBMP[i][j];
        }
    }
    ToImage(croppedImage);
}
//function that skews the image horizontally
void skewHorizontally() {
    // convert angle to radian
    double rad;
    cout << "Enter the angle: ";
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    //  factor that stretches the image in the horizontal direction
    double skewfactor = tan(rad);
    double scalefactor = 2.0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            //calculate the new y-coordinate using the following formula
            int new_j =  j * scalefactor - skewfactor * i; // 1*2.0    - tan(30)*1
            if (new_j >= 0 && new_j < SIZE) {
                imageSkew[i][j] = imageBMP[i][new_j];
            } else {
                imageSkew[i][j] = 255;
            }
        }
    }
    ToImage(imageSkew);
}
//function that skews the image horizontally
void skewVertically(){
    // convert angle to radian
    double rad;
    cout << "Enter the angle: ";
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    double skew_factor = tan(rad);
    //  factor that stretches the image in the verticall direction
    double scale_factor = 2.0;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            // calculate the new x-coordinate using the following formula//
            int new_i = i * scale_factor - skew_factor * j;
            if (new_i >= 0 && new_i < SIZE) {
                imageSkew[i][j] = imageBMP[new_i][j];
            } else {
                imageSkew[i][j] = 255;
            }

        }
    }
    ToImage(imageSkew);
}
