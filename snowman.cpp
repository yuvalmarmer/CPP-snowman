#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
using namespace std;



/*
 HHHHH
 HHHHH
X(LNR)Y
X(TTT)Y
 (BBB)
*/

#define WIDTH 7
#define HEIGHT 5

namespace ariel{
    
    bool leftArmFlag = false; //Flag for deleting spaces on left side
    bool rightArmFlag = false; //Flag for deleting spaces on right side

    void initSnowman(char (*skelton)[WIDTH]){
        //Set flags to false
        leftArmFlag = false;
        rightArmFlag = false;

        //Set all to ' '
        for (int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                skelton[i][j]=' ';
            }
        }
        //Adding left boundes
        skelton[2][1]='(';
        skelton[3][1]='(';
        skelton[4][1]='(';

        //Adding right boundes
        skelton[2][5]=')';
        skelton[3][5]=')';
        skelton[4][5]=')';

    }

    //Hat
    void Hat(char (*skelton)[WIDTH], int num){
        switch (num)
        {
        case 1:
            strcpy(skelton[0], "       ");
            strcpy(skelton[1], " _===_ ");
            break;
        case 2:
            strcpy(skelton[0], "  ___  ");
            strcpy(skelton[1], " ..... ");
            break;

        case 3:
            strcpy(skelton[0], "   _   ");
            strcpy(skelton[1], "  /_\\  ");
            break;

        case 4:
            strcpy(skelton[0], "  ___  ");
            strcpy(skelton[1], " (_*_) ");
            break;
        
        default:
            throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Left arm
    void LeftArm(char (*skelton)[WIDTH], int num){

        switch (num)
        {
            case 1:
                skelton[2][0] = ' ';
                skelton[3][0] = '<';
                break;
            case 2:
                skelton[2][0] = '\\';
                skelton[3][0] = ' ';
                break;

            case 3:
                skelton[2][0] = ' ';
                skelton[3][0] = '/';
                break;

            case 4:
                skelton[2][0] = ' ';
                skelton[3][0] = ' ';
                leftArmFlag=true;
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }
    
    //Right arm
    void RightArm(char (*skelton)[WIDTH], int num){
        switch (num)
        {
            case 1:
                skelton[2][6] = ' ';
                skelton[3][6] = '>';
                break;
            case 2:
                skelton[2][6] = '/';
                skelton[3][6] = ' ';
                break;

            case 3:
                skelton[2][6] = ' ';
                skelton[3][6] = '\\';
                break;

            case 4:
                skelton[2][6] = ' ';
                skelton[3][6] = ' ';
                rightArmFlag=true;
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Left eye
    void LeftEye(char (*skelton)[WIDTH], int num){
        switch (num)
        {
            case 1:
                skelton[2][2] = '.';
                break;
            case 2:
                skelton[2][2] = 'o';
                break;

            case 3:
                skelton[2][2] = 'O';
                break;

            case 4:
                skelton[2][2] = '-';
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Right eye
    void RightEye(char (*skelton)[WIDTH], int num){
        switch (num)
        {
            case 1:
                skelton[2][4] = '.';
                break;
            case 2:
                skelton[2][4] = 'o';
                break;

            case 3:
                skelton[2][4] = 'O';
                break;

            case 4:
                skelton[2][4] = '-';
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Nose
    void Nose(char (*skelton)[WIDTH], int num){
        switch (num)
        {
            case 1:
                skelton[2][3] = ',';
                break;
            case 2:
                skelton[2][3] = '.';
                break;

            case 3:
                skelton[2][3] = '_';
                break;

            case 4:
                skelton[2][3] = ' ';
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Torso
    void Torso(char (*skelton)[WIDTH], int num){
        switch (num)
        {
            case 1:
                skelton[3][3] = ':';
                break;
            case 2:
                skelton[3][2] = ']';
                skelton[3][4] = '[';
                break;

            case 3:     
                skelton[3][2] = '>';
                skelton[3][4] = '<';
                break;

            case 4:
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }
    
    //Base
    void Base(char (*skelton)[WIDTH], int num){
        switch (num)
        {
            case 1:
                skelton[4][3] = ':';
                break;
            case 2:
                skelton[4][2] = '"';
                skelton[4][4] = '"';
                break;

            case 3:     
                skelton[4][2] = '_';
                skelton[4][3] = '_';
                skelton[4][4] = '_';
                break;

            case 4:
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Remove spaces by if the flags are true
    void RemoveSpaces(char (*skelton)[WIDTH]){
        if(leftArmFlag){ //Remove from left side all spaces
            for(int i=0;i<HEIGHT;i++)
                skelton[i][0] = '\0';
        }

        if(rightArmFlag){ //Remove from right side all spaces
            for(int i=0;i<HEIGHT;i++)
                skelton[i][6] = '\0';
        }
    }
    
    //Building a string from 2D array
    string BuildStringFromArray(char (*skelton)[WIDTH]){
        string str="";
        //Building the string
        for (int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(skelton[i][j]!='\0')
                    str.push_back(skelton[i][j]);
            }
            str.push_back('\n');
        }

        return str;
    }
    

    
    //Array of all funcitons
    void (*functions[])(char(*)[WIDTH], int) = {Base, Torso, RightArm, LeftArm, RightEye, LeftEye, Nose, Hat};
    //Snowman function
    string snowman(int number){
        //The skelton of snowman
        auto skelton = new char[HEIGHT][WIDTH];
        
        int number_of_digits = 0; //Number of digits
        int function_indexer = 0; //Index of function that will call from the array of fucntions

        int temp = number;

        int num = -1; //The num of each code
        
        initSnowman(skelton); //Init from snowman 

        do {     
            num = temp%10;
            //Checks if the code is valid, else throw exception
            if(num<1 || num > 4)
                throw std::invalid_argument("Invalide code");

            //Check if there is more than 8 digits
            if(number_of_digits>8)
                throw std::out_of_range("The code is more that 8 digits");
            
            //Calll a function with the spesific index
            functions[function_indexer](skelton, num);
            
            temp /= 10;

            ++number_of_digits; 
            ++function_indexer;

        } while (temp);

        //Check if number of digits is less than 8
        if(number_of_digits<8)
            throw std::exception();


        //Remove all spaces 
        RemoveSpaces(skelton);

        //Create String from 2D-Array

        string answer = BuildStringFromArray(skelton);
       // cout << "**********" << endl << answer << endl << "**********" << endl;
        //Delete the dynamic allocated of skelton function
        //delete skelton;

        return answer;
    }

        
};