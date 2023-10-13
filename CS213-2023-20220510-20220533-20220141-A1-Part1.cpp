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
#include <fstream>
#include <bits/stdc++.h>
#include "bmplib.h"
#include "Functions.h"
using namespace std;
int main(){
    char choice,type;
    cout<<"Do you want to process a (G)S or (R)GB image?\n ";
    cin>>type;
    loadImage();
    displayChoices();
    cin>>choice;
    initChoice(choice);
    while(choice!='0'){
        displayChoices();
        cin>>choice;
        initChoice(choice);
    }
    return 0;
}