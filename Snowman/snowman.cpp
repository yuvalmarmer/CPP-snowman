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

    char skelton[HEIGHT][WIDTH];
    
    string snowman(int number){
        
        return " _===_ \n (.,.) \n ( : ) \n ( : ) ";

        int number_of_digits = 0;
        int temp = number;

        int number = -1;
        do {
            ++number_of_digits; 
            number = temp/10;

            if(number<1 || number > 4)
                throw invalid_argument("Invalide code");
            temp /= 10;
        } while (temp);
    
    }

        
};