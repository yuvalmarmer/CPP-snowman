#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

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
            break;
        }
    }


    //Left arm
    void LeftArm(char (*skelton)[WIDTH], int num){

        for(int i=0;i<HEIGHT;i++){
            for(int j=0;j<WIDTH;j++){
                cout << skelton[i][j];
            }
            cout << endl;
        }
    }

    //Right arm
    void RightArm(char (*skelton)[WIDTH], int num){}

    //Left eye
    void LeftEye(char (*skelton)[WIDTH], int num){}

    //Right eye
    void RightEye(char (*skelton)[WIDTH], int num){}

    //Nose
    void Nose(char (*skelton)[WIDTH], int num){}

    //Torso
    void Torso(char (*skelton)[WIDTH], int num){}

    //Base
    void Base(char (*skelton)[WIDTH], int num){}

    //char skelton[HEIGHT][WIDTH];
    auto skelton = new char[HEIGHT][WIDTH];

    void (*functions[])(char(*)[WIDTH], int) = {Hat, Nose, LeftEye, RightEye, LeftArm, RightArm, Torso, Base};
    string snowman(int number){
        int number_of_digits = 0;
        int temp = number;

        int num = -1;
        do {
            num = temp%10;

            if(num<1 || num > 4)
                throw std::invalid_argument("Invalide code");

            functions[number_of_digits](skelton, num);
            
            temp /= 10;
            ++number_of_digits; 


        } while (temp);


        if(number_of_digits>8)
            throw std::exception();

        
        return " _===_ \n (.,.) \n ( : ) \n ( : ) ";
    }

        
};