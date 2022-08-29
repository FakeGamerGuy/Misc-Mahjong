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
    srand((signed int)time(0));
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
            cout << "[" << i << "]\t" << theWall[i] << "\t" << tiles[(theWall[i])] << endl;
        }
    }

    // Draw hands
    // I haven't implemented a 14th "just drawn/tsumo" tile
    const int NUM_PLAYERS = 4;
    const int MAX_HAND_SIZE = 13;
    short int playerHands[NUM_PLAYERS][MAX_HAND_SIZE];
    short int lastDrawnTile = 0;

    // Draw player hands
    for(int i=0; i<3; i++)      // Each rotation of all 4 players drawing their tiles
    {
        for(int j=0; j<4; j++)  // Individual players drawing 4 tiles at a time
        {                       // I feel like this *could* be a loop but it also seems unnecessary
            playerHands[j][(i*4+0)] = theWall[lastDrawnTile++];
            playerHands[j][(i*4+1)] = theWall[lastDrawnTile++];
            playerHands[j][(i*4+2)] = theWall[lastDrawnTile++];
            playerHands[j][(i*4+3)] = theWall[lastDrawnTile++];
        }
    }
    for(int i=0; i<4; i++)      // Each player drawing their last tile
    {
        playerHands[i][12] = theWall[lastDrawnTile++];
    }

    // Print player hands
    for(int i=0; i<4; i++)
    {
    cout << "\nPlayer " << i+1 << ":";
        for(int j=0; j<13; j++)
        {
            cout << "[" << tiles[(playerHands[i][j])] << "]";  
        }
    }

    cout << endl << endl;

    return 0;
}