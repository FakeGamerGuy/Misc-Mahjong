// Mahjong tile shuffler
// Proof of concept practice based off the "Word Jumble" exercise in
// chapter 3 of Beginning C++ Through Game Programming

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    const unsigned short int NUM_TILES = 136;
    const string tiles[NUM_TILES]=
    {
        // Pinzu
        "P1","P1","P1","P1", "P2","P2","P2","P2", "P3","P3","P3","P3",
        "P4","P4","P4","P4", "P5","P5","P5","P5", "P6","P6","P6","P6",
        "P7","P7","P7","P7", "P8","P8","P8","P8", "P9","P9","P9","P9",  // 36

        // Souzu
        "S1","S1","S1","S1", "S2","S2","S2","S2", "S3","S3","S3","S3",
        "S4","S4","S4","S4", "S5","S5","S5","S5", "S6","S6","S6","S6",
        "S7","S7","S7","S7", "S8","S8","S8","S8", "S9","S9","S9","S9",  // 72

        // Manzu
        "M1","M1","M1","M1", "M2","M2","M2","M2", "M3","M3","M3","M3",
        "M4","M4","M4","M4", "M5","M5","M5","M5", "M6","M6","M6","M6",
        "M7","M7","M7","M7", "M8","M8","M8","M8", "M9","M9","M9","M9",  // 108

        // Honors
        "Gr","Gr","Gr","Gr", "Rd","Rd","Rd","Rd", "Wh","Wh","Wh","Wh",  // 120
        "E ","E ","E ","E ", "S ","S ","S ","S ", "W ","W ","W ","W ", "N ","N ","N ","N "  // 136
    };

    // Create and initialize the wall
    // The index is the position in the wall, and the value is the tile ID
    // For example, theWall[20] is the 21st tile in the wall which might hold
    // the ID 100, which 8 Manzu
    unsigned int theWall[NUM_TILES];
    for(int i=0; i<NUM_TILES; i++)
    {
        theWall[i]=i;
    }

    // Shuffle the wall
    unsigned int shuffles = 6502;   // The number of times 2 tiles are swapped
    for(int i=0; i<shuffles; i++)
    {
        int index1 = (rand()%NUM_TILES);
        int index2 = (rand()%NUM_TILES);
        int temp = theWall[index1];

        theWall[index1] = theWall[index2];
        theWall[index2] = temp;
    }

    // Look at the wall to make sure it's shuffled well, or at all
    cout << "Loc\tID\tType\n";
    for(int i=0; i<NUM_TILES; i++)
    {
        if(theWall[i]!=i)
        {
            cout << "[" << i << "]\t" << theWall[i] << "\t" << tiles[(theWall[i])] << endl << endl;
        }
    }

    // Draw hands
    // We'll just assume player1 is the dealer since they draw first
    short int playerHands[4][13];
    short int lastDrawnTile = 0;

    /*
    playerHands[0][0] = theWall[0];
    playerHands[0][1] = theWall[1];
    playerHands[0][2] = theWall[2];
    playerHands[0][3] = theWall[3];

    playerHands[1][0] = theWall[4];
    playerHands[1][1] = theWall[5];
    playerHands[1][2] = theWall[6];
    playerHands[1][3] = theWall[7];
    ...
    playerHands[3][0] = theWall[12];
    playerHands[3][1] = theWall[13];
    playerHands[3][2] = theWall[14];
    playerHands[3][3] = theWall[15];

    playerHands[0][4] = theWall[16];
    playerHands[0][5] = theWall[17];
    playerHands[0][6] = theWall[18];
    playerHands[0][7] = theWall[19];
    */

    // Show player hands
    for(int i=0; i<13; i++)
    {
        cout << "[" << tiles[(playerHands[0][i])] << "]";
    }

    cout << endl;

    return 0;
}