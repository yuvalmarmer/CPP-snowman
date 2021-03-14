#include <iostream>

#define WIDTH 7
#define HEIGHT 5

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