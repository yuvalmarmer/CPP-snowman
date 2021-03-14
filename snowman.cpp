#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstring>
#include <vector>
#include <functional>
#include <array>


using namespace std;


namespace ariel{
    
    bool leftArmFlag = false; //Flag for deleting spaces on left side
    bool rightArmFlag = false; //Flag for deleting spaces on right side
    bool hatFlag = false;
    const int RightBoudeHat = 5;
    //Init the snowman
    void initSnowman(vector<vector<char>> &skelton){
        //Set flags to false
        leftArmFlag = false;
        rightArmFlag = false;
        hatFlag = false;
        //Set all to ' '
        for (int i=0;i<HEIGHT;i++){
            vector<char> temp;
            temp.resize(WIDTH);
            for(int j=0;j<WIDTH;j++){
                temp.push_back(' ');
            }
            skelton.push_back(temp);
        }
        //Adding left boundes
        skelton.at(2).at(LEFT_SIDE) ='(';
        skelton.at(3).at(LEFT_SIDE) ='(';
        skelton.at(4).at(LEFT_SIDE) ='(';

        //Adding right boundes
        skelton.at(2).at(RIGH_SIDE)=')';
        skelton.at(3).at(RIGH_SIDE)=')';
        skelton.at(4).at(RIGH_SIDE)=')';

    }

    //Hat
    void Hat(vector<vector<char>> &skelton, int num){
        switch (num)
        {
        case 1:
            skelton.at(HAT_DOWN).at(1) =  '_';
            skelton.at(HAT_DOWN).at(2) =  '=';
            skelton.at(HAT_DOWN).at(3) =  '=';
            skelton.at(HAT_DOWN).at(4) =  '=';
            skelton.at(HAT_DOWN).at(RightBoudeHat) =  '_';
            hatFlag = true;

            break;
        case 2:
            skelton.at(HAT_UP).at(2) = '_';
            skelton.at(HAT_UP).at(3) = '_';
            skelton.at(HAT_UP).at(4) = '_';

            skelton.at(HAT_DOWN).at(1) = '.';
            skelton.at(HAT_DOWN).at(2) = '.';
            skelton.at(HAT_DOWN).at(3) = '.';
            skelton.at(HAT_DOWN).at(4) = '.';
            skelton.at(HAT_DOWN).at(RightBoudeHat) = '.';
            break;

        case 3:

            skelton.at(HAT_UP).at(3)  = '_';

            skelton.at(HAT_DOWN).at(2) = '/';
            skelton.at(HAT_DOWN).at(3) = '_';
            skelton.at(HAT_DOWN).at(4) = '\\';
            break;

        case 4:
            skelton.at(HAT_UP).at(2) = '_';
            skelton.at(HAT_UP).at(3) = '_';
            skelton.at(HAT_UP).at(4) = '_';

            skelton.at(HAT_DOWN).at(1) = '(';
            skelton.at(HAT_DOWN).at(2) = '_';
            skelton.at(HAT_DOWN).at(3) = '*';
            skelton.at(HAT_DOWN).at(4) = '_';
            skelton.at(HAT_DOWN).at(RightBoudeHat) = ')';
            break;
        
        default:
            throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Left arm
    void LeftArm(vector<vector<char>> &skelton, int num){

        switch (num)
        {
            case 1:
                skelton.at(3).at(ARM_LFT) = '<';
                break;
            case 2:
                skelton.at(2).at(ARM_LFT) = '\\';
                break;

            case 3:
                skelton.at(3).at(ARM_LFT) = '/';
                break;

            case 4:
                leftArmFlag=true;
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }
    
    //Right arm
    void RightArm(vector<vector<char>> &skelton, int num){
        switch (num)
        {
            case 1:
                skelton.at(3).at(ARM_RIG) = '>';
                break;
            case 2:
                skelton.at(2).at(ARM_RIG) = '/';
                break;

            case 3:
                skelton.at(3).at(ARM_RIG) = '\\';
                break;

            case 4:
                rightArmFlag=true;
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Left eye
    void LeftEye(vector<vector<char>> &skelton, int num){
        switch (num)
        {
            case 1:
                skelton.at(2).at(EYE_LFT) = '.';
                break;
            case 2:
                skelton.at(2).at(EYE_LFT) = 'o';
                break;

            case 3:
                skelton.at(2).at(EYE_LFT) = 'O';
                break;

            case 4:
                skelton.at(2).at(EYE_LFT) = '-';
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Right eye
    void RightEye(vector<vector<char>> &skelton, int num){
        switch (num)
        {
            case 1:
                skelton.at(2).at(EYE_RIG) = '.';
                break;
            case 2:
                skelton.at(2).at(EYE_RIG) = 'o';
                break;

            case 3:
                skelton.at(2).at(EYE_RIG) = 'O';
                break;

            case 4:
                skelton.at(2).at(EYE_RIG) = '-';
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Nose
    void Nose(vector<vector<char>> &skelton, int num){
        switch (num)
        {
            case 1:
            
                skelton.at(2).at(NOSE)  = ',';
                break;
            case 2:
                skelton.at(2).at(NOSE) =  '.';
                break;

            case 3:
                skelton.at(2).at(NOSE) =  '_';
                break;

            case 4:
                skelton.at(2).at(NOSE) =  ' ';
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Torso
    void Torso(vector<vector<char>> &skelton, int num){
        switch (num)
        {
            case 1:
                skelton.at(TOR).at(3) = ':';
                
                break;
            case 2:
                skelton.at(TOR).at(2) = ']';
                skelton.at(TOR).at(4) = '[';
                break;

            case 3:     
                skelton.at(TOR).at(2) = '>';
                skelton.at(TOR).at(4) = '<';
                break;

            case 4:
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }
    
    //Base
    void Base(vector<vector<char>> &skelton, int num){
        switch (num)
        {
            case 1:
                skelton.at(BASE).at(3) = ':';
                
                break;
            case 2:
                skelton.at(BASE).at(2) = '"';
                skelton.at(BASE).at(4) = '"';
                break;

            case 3:     
                skelton.at(BASE).at(2) = '_';
                skelton.at(BASE).at(3) = '_';
                skelton.at(BASE).at(4) = '_';
                break;

            case 4:
                break;
            
            default:
                throw out_of_range("The code " + to_string(num) + " is out of range");
        }
    }

    //Remove spaces by if the flags are true
    void RemoveSpaces(vector<vector<char>> &skelton){
        if(leftArmFlag){ //Remove from left side all spaces
            for(int i=0;i<HEIGHT;i++){
                skelton.at(i).at(ARM_LFT) = '\0';
            }
        }

        if(rightArmFlag){ //Remove from right side all spaces
            for(int i=0;i<HEIGHT;i++){
                skelton.at(i).at(ARM_RIG) = '\0';
            }
        }

        if(hatFlag){ //Remove from top hat
            for(int i=0;i<WIDTH;i++){
                skelton.at(HAT_UP).at(i) = '\0';
            }
        }

    }
    
    //Building a string from 2D array
    string BuildStringFromArray(vector<vector<char>> &skelton){
        string str;
        //Building the string
        for (int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                if(skelton.at(i).at(j)!='\0'){
                    str.push_back(skelton[i][j]);
                }
            }
            if(!(i==0 && hatFlag)){
                str.push_back('\n');
            }
        }

        return str;
    }
    

    
    //Array of all funcitons
    //void (*functions[])(vector<vector<char>>&, int) = {Base, Torso, RightArm, LeftArm, RightEye, LeftEye, Nose, Hat};
    std::array<std::function<void(vector<vector<char>>&, int)>, 8> functions = {bind(Base, placeholders::_1, placeholders::_2),bind(Torso, placeholders::_1, placeholders::_2), 
                                                                                bind(RightArm, placeholders::_1, placeholders::_2),bind(LeftArm, placeholders::_1, placeholders::_2), 
                                                                                bind(RightEye, placeholders::_1, placeholders::_2),bind(LeftEye, placeholders::_1, placeholders::_2), 
                                                                                bind(Nose, placeholders::_1, placeholders::_2),bind(Hat, placeholders::_1, placeholders::_2)};
    //Snowman function
    string snowman(int number){

        //The skelton of snowman
        //auto skelton = new char[HEIGHT][WIDTH];
        std::vector<std::vector<char>> skelton;

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
            
            //Call a function with the spesific index
            auto fun = functions.at(function_indexer);
            fun(skelton, num);
            
            temp /= BASE_M;

            ++number_of_digits; 
            ++function_indexer;

        } while (temp>0);

        //Check if number of digits is less than 8
        if(number_of_digits<MAX_LEN){
            throw std::exception();
        }

        //Remove all spaces 
        RemoveSpaces(skelton);

        //Create String from 2D-Array

        string answer = BuildStringFromArray(skelton);
        //Delete the dynamic allocated of skelton function

        return answer;
    }

        
};