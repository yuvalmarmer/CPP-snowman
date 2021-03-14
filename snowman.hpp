#include <iostream>
#include <vector>


//DEFENITIONS
const int WIDTH = 7;
const int HEIGHT = 5;

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

const int LEFT_SIDE = 1;
const int RIGH_SIDE = 5;

using namespace std;
namespace ariel
{
    string snowman(int num);

    //init for snowman 
    void initSnowman(vector<vector<char>> &skelton);
    
    //Hat function
    void Hat(vector<vector<char>> &skelton, int num);

    //Left arm
    void LeftArm(vector<vector<char>> &skelton, int num);

    //Right arm
    void RightArm(vector<vector<char>> &skelton, int num);

    //Left eye
    void LeftEye(vector<vector<char>> &skelton, int num);

    //Right eye
    void RightEye(vector<vector<char>> &skelton, int num);

    //Nose
    void Nose(vector<vector<char>> &skelton, int num);

    //Torso
    void Torso(vector<vector<char>> &skelton, int num);

    //Base
    void Base(vector<vector<char>> &skelton, int num);

    //Remove spaces
    void RemoveSpaces(vector<vector<char>> &skelton);

    //Building the string
    string BuildStringFromArray(vector<vector<char>> &skelton);
};