#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
using namespace std;



TEST_CASE("Good snowman code") {

    // Check if generated normal
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));
    
    
}

TEST_CASE("Difrent hats"){
    //Straw Hat
    CHECK(snowman(11114411) == string(" _===_ \n (.,.) \n ( : ) \n ( : ) "));    
    //Mexican Hat
    CHECK(snowman(21114411) == string("  ___  \n ..... \n (.,.) \n ( : ) \n ( : ) "));
    //Fez
    CHECK(snowman(31114411) == string("   _   \n  /_\\  \n (.,.) \n ( : ) \n ( : ) "));
    //Rusiian Hat
    CHECK(snowman(41114411) == string("  ___  \n (_*_) \n (.,.) \n ( : ) \n ( : ) "));

}

TEST_CASE("Difrent faces"){
    //Normal Nose Dot eye(Left and Right)
    CHECK(snowman(21114411) == string("  ___  \n ..... \n (.,.) \n ( : ) \n ( : ) "));

    //Normal Nose Bigger Dot eye(Left and Right)
    CHECK(snowman(21224411) == string("  ___  \n ..... \n (o,o) \n ( : ) \n ( : ) "));

    //Normal Nose Biggest Dot eye(Left and Right)
    CHECK(snowman(21334411) == string("  ___  \n ..... \n (O,O) \n ( : ) \n ( : ) "));

    //Normal Nose Closed eye(Left and Right)
    CHECK(snowman(21444411) == string("  ___  \n ..... \n (-,-) \n ( : ) \n ( : ) "));

    //Dot Nose 
    CHECK(snowman(22444411) == string("  ___  \n ..... \n (-,-) \n ( : ) \n ( : ) "));

    //Line Nose 
    CHECK(snowman(23444411) == string("  ___  \n ..... \n (-_-) \n ( : ) \n ( : ) "));

    //None Nose 
    CHECK(snowman(24444411) == string("  ___  \n ..... \n (- -) \n ( : ) \n ( : ) "));
}



TEST_CASE("Difrent hands"){
    //Normal arm (Right and Left)
    CHECK(snowman(21111111) == string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) "));

    //Upwards arm (Right and Left)
    CHECK(snowman(21112211) == string("  ___  \n ..... \n\\(.,.)/\n ( : ) \n ( : ) "));

    //Downwards Arm (Right and Left)
    CHECK(snowman(21113311) == string("  ___  \n ..... \n (.,.) \n/( : )\\\n ( : ) "));

    //None arm (Right and Left)
    CHECK(snowman(21114411) == string("  ___  \n ..... \n (.,.) \n ( : ) \n ( : ) "));

    //2 Diffrent hand 
    //None arm (Right and Left)
    CHECK(snowman(21111211) == string("  ___  \n ..... \n (.,.)/\n<( : ) \n ( : ) "));
}

TEST_CASE("Difrent Torso"){
    //Buttons torso
    CHECK(snowman(21111111) == string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) "));

    //Vest torso
    CHECK(snowman(21111121) == string("  ___  \n ..... \n (.,.) \n<(] [)>\n ( : ) "));    
    
    //Inward Arms torso
    CHECK(snowman(21111121) == string("  ___  \n ..... \n (.,.) \n<(> <)>\n ( : ) "));    

    //None torso
    CHECK(snowman(21111121) == string("  ___  \n ..... \n (.,.) \n<(   )>\n ( : ) "));    

}


TEST_CASE("Difrent Base"){
    //Buttons Base
    CHECK(snowman(21111111) == string("  ___  \n ..... \n (.,.) \n<( : )>\n ( : ) "));

    //Feet Base
    CHECK(snowman(21111112) == string("  ___  \n ..... \n (.,.) \n<( : )>\n (\" \") "));

    //Flat Base
    CHECK(snowman(21111113) == string("  ___  \n ..... \n (.,.) \n<( : )>\n (___) "));

    //None Base
    CHECK(snowman(21111114) == string("  ___  \n ..... \n (.,.) \n<( : )>\n (   ) "));
}

TEST_CASE("Difrent snowmans"){
    CHECK(snowman(33232124) == string("  ___  \n  /_\\  \n\\(o_O) \n (] [)>\n (   ) "));

    CHECK(snowman(32243324) == string("   _   \n  /_\\  \n (o.-) \n /(] [)\\ \n (   ) "));

    CHECK(snowman(23232223) == string("  ___  \n  ..... \n\\(o_O)/\n (] [) \n (___) "));

}


TEST_CASE("Bad snowman code") {

    //Invalid codes


    CHECK_THROWS(snowman(555));
    
    CHECK_THROWS(snowman(23532223));

    CHECK_THROWS(snowman(235322232));

    CHECK_THROWS(snowman(235322));

    CHECK_THROWS(snowman(23532551));


    //Bad Snowman

    CHECK(snowman(21111111) != string("  ___  \n ..... \n (.,.) \n<(] [)>\n ( : ) "));  
    CHECK(snowman(21114411) != string("  ___  \n ..... \n (-_-) \n ( : ) \n ( : ) "));
}

