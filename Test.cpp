#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Diffrent hats"){
    //Straw Hat
    CHECK(nospaces(snowman(11114411)) == nospaces(string("_===_\n(.,.)\n( : )\n( : )")));    
    //Mexican Hat
    CHECK(nospaces(snowman(21114411)) == nospaces(string(" ___ \n.....\n(.,.)\n( : )\n( : )")));
    //Fez
    CHECK(nospaces(snowman(31114411)) == nospaces(string("  _  \n /_\\ \n(.,.)\n( : )\n( : )")));
    //Rusiian Hat
    CHECK(nospaces(snowman(41114411)) == nospaces(string(" ___ \n(_*_)\n(.,.)\n( : )\n( : )")));
1
}

TEST_CASE("Diffrent faces"){
    //Normal Nose Dot eye(Left and Right)
    CHECK(nospaces(snowman(21114411)) == nospaces(string(" ___ \n.....\n(.,.)\n( : )\n( : )")));

    //Normal Nose Bigger Dot eye(Left and Right)
    CHECK(nospaces(snowman(21224411)) == nospaces(string(" ___ \n.....\n(o,o)\n( : )\n( : )")));

    //Normal Nose Biggest Dot eye(Left and Right)
    CHECK(nospaces(snowman(21334411)) == nospaces(string(" ___ \n.....\n(O,O)\n( : )\n( : )")));

    //Normal Nose Closed eye(Left and Right)
    CHECK(nospaces(snowman(21444411)) == nospaces(string(" ___ \n.....\n(-,-)\n( : )\n( : )")));

    //Dot Nose 
    CHECK(nospaces(snowman(22444411)) == nospaces(string(" ___ \n.....\n(-,-)\n( : )\n( : )")));

    //Line Nose 
    CHECK(nospaces(snowman(23444411)) == nospaces(string(" ___ \n.....\n(-_-)\n( : )\n( : )")));

    //None Nose 
    CHECK(nospaces(snowman(24444411)) == nospaces(string(" ___ \n.....\n(- -)\n( : )\n( : )")));
}



TEST_CASE("Diffrent hands"){
    //Normal arm (Right and Left)
    CHECK(nospaces(snowman(21111111)) == nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) ")));

    //Upwards arm (Right and Left)
    CHECK(nospaces(snowman(21112211)) == nospaces(string("  ___  \n ..... \n\\(.,.)/\n ( : ) \n ( : ) ")));

    //Downwards Arm (Right and Left)
    CHECK(nospaces(snowman(21113311)) == nospaces(string("  ___  \n ..... \n (.,.) \n/( : )\\\n ( : ) ")));

    //None arm (Right and Left)
    CHECK(nospaces(snowman(21114411)) == nospaces(string(" ___ \n.....\n(.,.)\n( : )\n( : )")));

    //2 Diffrent hand 
    //None arm (Right and Left)
    CHECK(nospaces(snowman(21111211)) == nospaces(string("  ___  \n ..... \n (.,.)/\n<( : ) \n ( : ) ")));
}

TEST_CASE("Difrent Torso"){
    //Buttons torso
    CHECK(nospaces(snowman(21111111)) == nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) ")));

    //Vest torso
    CHECK(nospaces(snowman(21111121)) == nospaces(string("  ___  \n ..... \n (.,.) \n<(] [)>\n ( : ) ")));    
    
    //Inward Arms torso
    CHECK(nospaces(snowman(21111121)) == nospaces(string("  ___  \n ..... \n (.,.) \n<(> <)>\n ( : ) ")));    

    //None torso
    CHECK(nospaces(snowman(21111121)) == nospaces(string("  ___  \n ..... \n (.,.) \n<(   )>\n ( : ) ")));    

}


TEST_CASE("Diffrent Base"){
    //Buttons Base
    CHECK(nospaces(snowman(21111111)) == nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) ")));

    //Feet Base
    CHECK(nospaces(snowman(21111112)) == nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n (\" \") ")));
    
    //Flat Base
    CHECK(nospaces(snowman(21111113)) == nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n (___) ")));

    //None Base
    CHECK(nospaces(snowman(21111114)) == nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n (   ) ")));
}

TEST_CASE("Diffrent snowmans"){
    CHECK(nospaces(snowman(33232124)) == nospaces(string("  ___  \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) ")));

    CHECK(nospaces(snowman(32243324))== nospaces(string("   _   \n  /_\\  \n (o.-) \n /(] [)\\ \n (   ) ")));

    CHECK(nospaces(snowman(23232223)) == nospaces(string("  ___  \n  ..... \n\\(o_O)/\n (] [) \n (___) ")));

}


TEST_CASE("Bad snowman code") {
    
    //Less numbers
    CHECK_THROWS(nospaces(snowman(555)));
    
    CHECK_THROWS(nospaces(snowman(235322)));

    //Invalid numbers
    CHECK_THROWS(nospaces(snowman(23532223)));

    CHECK_THROWS(nospaces(snowman(23532551)));


    //More than needed 
    CHECK_THROWS(nospaces(snowman(235322232)));
    
    //Zeros
    CHECK_THROWS(nospaces(snowman(21101110)));
    
    
    //Negetive Number
    CHECK_THROWS(nospaces(snowman(-21111111)));

    //Bad Snowman

    CHECK(nospaces(snowman(21111111)) != nospaces(string("  ___  \n ..... \n (.,.) \n<( : )>\n (___) ")));
    CHECK(nospaces(snowman(21114411)) != nospaces(string("  ___  \n ..... \n (.,.) \n<(   )>\n ( : ) ")));   
}

