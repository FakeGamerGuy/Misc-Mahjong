// Rewriting the tile shuffling/drawing stuff because I wanted to play with vectors
// Still needs to draw the other player hands and draw tiles in 4-4-4-1 instead of
// all 13 at once

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    // Starting values
    srand((int)time(0));
    const unsigned int tileTypes = 34;
    const unsigned int totalTiles = 136;
    const int shuffleAmount = 1000;
    string tileNames[34]=
    {
        "1-sou","2-sou","3-sou","4-sou","5-sou","6-sou","7-sou","8-sou","9-sou",    // 9      36
        "1-man","2-man","3-man","4-man","5-man","6-man","7-man","8-man","9-man",    // 18     36
        "1-pin","2-pin","3-pin","4-pin","5-pin","6-pin","7-pin","8-pin","9-pin",    // 27     36
        "East","South","West","North",                                              // 31     16
        "Green","Red","White"                                                       // 34     12
    };                                                                              // Total 136
    
    // Initialize wall
    vector<unsigned int> tileWall;
    for(int i=0; i<totalTiles; i++)
    {
        tileWall.push_back(i);
    }
    
    // Shuffle wall
    int index1, index2, temp1;
    for(int i=0; i<shuffleAmount; i++)
    {
        index1 = rand()%totalTiles;
        index2 = rand()%totalTiles;
        temp1 = tileWall[index1];
        
        tileWall[index1] = tileWall[index2];
        tileWall[index2] = temp1;
    }
    
    // Initialize player hand
    vector<unsigned int> player1Hand;
    
    // Draw hand
    int tilesToDraw = 13;
    for(int i=0; i<tilesToDraw; i++)
    {
        player1Hand.push_back(tileWall[tileWall.size()-1]);
        tileWall.pop_back();
    }
    
    // Show hand
    cout << "Ordinal║TileID ║Tile Type" << endl;
    cout << "═══════╩═══════╩═════════" << endl;
    for(int i=0; i<player1Hand.size(); i++)
    {
        cout << player1Hand[i] << "\t" << player1Hand[i]/4 << "." << player1Hand[i]%4 << "\t" << tileNames[player1Hand[i]/4] << endl;
    }
    
    return 0;
}
