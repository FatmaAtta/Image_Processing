//FCAI - OOP Programming - 2023 - Assignment 1
//Program Name: main.cpp
//Last Modification Date: 10/5/2023
//Fatma Mahmoud Atta 20220510
//Shahd Mohammed Ahmed 20220533
//Reham Fawzy 20220141

#include <bits/stdc++.h>
using namespace std;

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
int main() {
    string fileName, mergeFile;
    char initialChoice,choice;
    cout<<"Hello,\n Please enter the image file name to process\n";
    cin>>fileName;
    cout<<"Please select any option:\n";
    displayChoices();
    cin >> initialChoice;
//    while(initialChoice){
        switch (initialChoice){
            case 1: ;
                break;
            case 2: ;
                break;
            case 3:
                cout<<"Please enter the image file name to merge:\n";
                cin>>mergeFile;
                break;
            case 4:
                cout<<"Flip (h)orizontally or (v)ertically? \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                }
                break;
            case 5:
                cout<<"Flip (d)arken or (l)ighten? \n";
                cin>>choice;
                if(choice=='d'){

                }else{

                };
                break;
            case 6:
                cout<<"Flip (90) or (180) or (360)? \n";
                cin>>choice;

                break;
            case 7: ;
                break;
            case 8:
                cout<<"Which quarter to enlarge 1, 2, 3, 4? \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 9:
                cout<<"Shrink to (1/2) or (1/3) or (1/4)? \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 'a':
                cout<<"Mirror (l)eft or (r)ight or (u)p or (d)own side? \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 'b':
                cout<<"New order of quarters? \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 'c': ;
                break;
            case 'd':
                cout<<"Please enter x y l w: \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 'e':
                cout<<"Please enter degree to skew right: \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 'f':
                cout<<"Please enter degree to skew up: \n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 's':
                cout<<"Please enter new file name:\n";
                cin>>choice;
                if(choice=='h'){

                }else{

                };
                break;
            case 0:;
                break;
        }
//    }
    return 0;
}
