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

    bool leftArmFlag = false;
    bool rightArmFlag = false;

    void initSnowman(char (*skelton)[WIDTH]){

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

    //char skelton[HEIGHT][WIDTH];
    auto skelton = new char[HEIGHT][WIDTH];

    void (*functions[])(char(*)[WIDTH], int) = {Hat, Nose, LeftEye, RightEye, LeftArm, RightArm, Torso, Base};
    string snowman(int number){
        int number_of_digits = 0;
        int temp = number;

        int num = -1;
        initSnowman(skelton);
        do {
            num = temp%10;

            if(num<1 || num > 4)
                throw std::invalid_argument("Invalide code");

            functions[number_of_digits](skelton, num);
            
            temp /= 10;
            ++number_of_digits; 


        } while (temp);

        for (int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                cout << skelton[i][j];
            }
            cout << endl;
        }


        if(number_of_digits>8)
            throw std::exception();

        delete[] skelton;

        return " _===_ \n (.,.) \n ( : ) \n ( : ) ";
    }

        
};