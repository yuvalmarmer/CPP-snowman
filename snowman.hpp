#include <iostream>

#define WIDTH 7
#define HEIGHT 5

using namespace std;
namespace ariel
{
    string snowman(int num);

    //init for snowman 
    void initSnowman(char (*skelton[WIDTH]));
    
    //Hat function
    void Hat(char (*skelton[WIDTH]), int num);

    //Left arm
    void LeftArm(char (*skelton[WIDTH]), int num);

    //Right arm
    void RightArm(char (*skelton[WIDTH]), int num);

    //Left eye
    void LeftEye(char (*skelton[WIDTH]), int num);

    //Right eye
    void RightEye(char (*skelton[WIDTH]), int num);

    //Nose
    void Nose(char (*skelton[WIDTH]), int num);

    //Torso
    void Torso(char (*skelton[WIDTH]), int num);

    //Base
    void Base(char (*skelton[WIDTH]), int num);
};