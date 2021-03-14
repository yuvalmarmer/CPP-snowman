#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
using namespace std;


#define WIDTH 7
#define HEIGHT 5

const int HAT_UP = 0;
const int HAT_DOWN = 1;

const int ARM_LFT = 0;
const int ARM_RIG = 6;

const int EYE_LFT = 2;
const int EYE_RIG = 4;

const int NOSE = 3;

const int TOR = 3;

const int BASE= 4;

const int BASE_M = 10;

const int MAX_LEN = 8;

const int RANGE_LOW = 1;
const int RANGE_HIGH = 4;



namespace ariel{
    
    bool leftArmFlag = false; //Flag for deleting spaces on left side
    bool rightArmFlag = false; //Flag for deleting spaces on right side
    bool hatFlag = false;

    //Init the snowman
    void initSnowman(char (*skelton)[WIDTH]){
        //Set flags to false
        leftArmFlag = false;
        rightArmFlag = false;
        hatFlag = false;
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
            skelton[HAT_DOWN][1] = '_';
            skelton[HAT_DOWN][2] = '=';
            skelton[HAT_DOWN][3] = '=';
            skelton[HAT_DOWN][4] = '=';
            skelton[HAT_DOWN][5] = '_';
            hatFlag = true;

            break;
        case 2:
            skelton[HAT_UP][2] = '_';
            skelton[HAT_UP][3] = '_';
            skelton[HAT_UP][4] = '_';

            skelton[HAT_DOWN][1] = '.';
            skelton[HAT_DOWN][2] = '.';
            skelton[HAT_DOWN][3] = '.';
            skelton[HAT_DOWN][4] = '.';
            skelton[HAT_DOWN][5] = '.';
            break;

        case 3:

            skelton[HAT_UP][3] = '_';

            skelton[HAT_DOWN][2] = '/';
            skelton[HAT_DOWN][3] = '_';
            skelton[HAT_DOWN][4] = '\\';
            break;

        case 4:
            skelton[HAT_UP][2] = '_';
            skelton[HAT_UP][3] = '_';
            skelton[HAT_UP][4] = '_';

            skelton[HAT_DOWN][1] = '(';
            skelton[HAT_DOWN][2] = '_';
            skelton[HAT_DOWN][3] = '*';
            skelton[HAT_DOWN][4] = '_';
            skelton[HAT_DOWN][5] = ')';
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
                skelton[3][ARM_LFT] = '<';
                break;
            case 2:
                skelton[2][ARM_LFT] = '\\';
                break;

            case 3:
                skelton[3][ARM_LFT] = '/';
                break;

            case 4:
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
                skelton[2][ARM_RIG] = ' ';
                skelton[3][ARM_RIG] = '>';
                break;
            case 2:
                skelton[2][ARM_RIG] = '/';
                skelton[3][ARM_RIG] = ' ';
                break;

            case 3:
                skelton[2][ARM_RIG] = ' ';
                skelton[3][ARM_RIG] = '\\';
                break;

            case 4:
                skelton[2][ARM_RIG] = ' ';
                skelton[3][ARM_RIG] = ' ';
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
                skelton[2][EYE_LFT] = '.';
                break;
            case 2:
                skelton[2][EYE_LFT] = 'o';
                break;

            case 3:
                skelton[2][EYE_LFT] = 'O';
                break;

            case 4:
                skelton[2][EYE_LFT] = '-';
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
                skelton[2][EYE_RIG] = '.';
                break;
            case 2:
                skelton[2][EYE_RIG] = 'o';
                break;

            case 3:
                skelton[2][EYE_RIG] = 'O';
                break;

            case 4:
                skelton[2][EYE_RIG] = '-';
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
                skelton[2][NOSE] = ',';
                break;
            case 2:
                skelton[2][NOSE] = '.';
                break;

            case 3:
                skelton[2][NOSE] = '_';
                break;

            case 4:
                skelton[2][NOSE] = ' ';
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
                skelton[TOR][3] = ':';
                break;
            case 2:
                skelton[TOR][2] = ']';
                skelton[TOR][4] = '[';
                break;

            case 3:     
                skelton[TOR][2] = '>';
                skelton[TOR][4] = '<';
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
                skelton[BASE][3] = ':';
                break;
            case 2:
                skelton[BASE][2] = '"';
                skelton[BASE][4] = '"';
                break;

            case 3:     
                skelton[BASE][2] = '_';
                skelton[BASE][3] = '_';
                skelton[BASE][4] = '_';
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

        if(hatFlag){ //Remove from top hat
            for(int i=0;i<WIDTH;i++)
                skelton[HAT_UP][i] = '\0';
        }

    }
    
    //Building a string from 2D array
    string BuildStringFromArray(char (*skelton)[WIDTH]){
        string str="";
        //Building the string
        for (int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(skelton[i][j]!='\0'){
                    str.push_back(skelton[i][j]);
                }
            }
            if(i!=0 && !hatFlag){
                str.push_back('\n');
            }
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
            num = temp%BASE_M;
            //Checks if the code is valid, else throw exception
            if(num<RANGE_LOW || num > RANGE_HIGH){
                throw std::invalid_argument("Invalide code");
            }

            //Check if there is more than 8 digits
            if(number_of_digits>=MAX_LEN){
                throw std::out_of_range("The code is more that 8 digits");
            }
            
            //Calll a function with the spesific index
            functions[function_indexer](skelton, num);
            
            temp /= BASE_M;

            ++number_of_digits; 
            ++function_indexer;

        } while (temp);

        //Check if number of digits is less than 8
        if(number_of_digits<MAX_LEN){
            throw std::exception();
        }

        //Remove all spaces 
        RemoveSpaces(skelton);

        //Create String from 2D-Array

        string answer = BuildStringFromArray(skelton);
        //Delete the dynamic allocated of skelton function
        //delete skelton;

        return answer;
    }

        
};