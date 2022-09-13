// Animation thingie

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void printHappy()
{
    for(int i=0; i<100; i++)
    {
        cout << endl;
    }
        cout << "      ___           ___           ___         ___                                                           \n";
        cout << "     /\\  \\         /\\  \\         /\\  \\       /\\  \\                                                          \n";
        cout << "     \\:\\  \\       /::\\  \\       /::\\  \\     /::\\  \\       ___                                               \n";
        cout << "      \\:\\  \\     /:/\\:\\  \\     /:/\\:\\__\\   /:/\\:\\__\\     /|  |                                              \n";
        cout << "  ___ /::\\  \\   /:/ /::\\  \\   /:/ /:/  /  /:/ /:/  /    |:|  |                                              \n";
        cout << " /\\  /:/\\:\\__\\ /:/_/:/\\:\\__\\ /:/_/:/  /  /:/_/:/  /     |:|  |                                              \n";
        cout << " \\:\\/:/  \\/__/ \\:\\/:/  \\/__/ \\:\\/:/  /   \\:\\/:/  /    __|:|__|                                              \n";
        cout << "  \\::/__/       \\::/__/       \\::/__/     \\::/__/    /::::\\  \\                                              \n";
        cout << "   \\:\\  \\        \\:\\  \\        \\:\\  \\      \\:\\  \\    ~~~~\\:\\  \\                                             \n";
        cout << "    \\:\\__\\        \\:\\__\\        \\:\\__\\      \\:\\__\\        \\:\\__\\                                            \n";
        cout << "     \\/__/         \\/__/         \\/__/       \\/__/         \\/__/                                            \n";
}

void printBirthday()
{
    cout << "                                ___                         ___                         ___                 \n";
    cout << "     _____                     /\\  \\                       /\\  \\         _____         /\\  \\                \n";
    cout << "    /::\\  \\       ___         /::\\  \\         ___          \\:\\  \\       /::\\  \\       /::\\  \\         ___   \n";
    cout << "   /:/\\:\\  \\     /\\__\\       /:/\\:\\__\\       /\\__\\          \\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\       /|  |  \n";
    cout << "  /:/ /::\\__\\   /:/__/      /:/ /:/  /      /:/  /      ___ /::\\  \\   /:/  \\:\\__\\   /:/ /::\\  \\     |:|  |  \n";
    cout << " /:/_/:/\\:|__| /::\\  \\     /:/_/:/__/___   /:/__/      /\\  /:/\\:\\__\\ /:/__/ \\:|__| /:/_/:/\\:\\__\\    |:|  |  \n";
    cout << " \\:\\/:/ /:/  / \\/\\:\\  \\__  \\:\\/:::::/  /  /::\\  \\      \\:\\/:/  \\/__/ \\:\\  \\ /:/  / \\:\\/:/  \\/__/  __|:|__|  \n";
    cout << "  \\::/_/:/  /   ~~\\:\\/\\__\\  \\::/~~/~~~~  /:/\\:\\  \\      \\::/__/       \\:\\  /:/  /   \\::/__/      /::::\\  \\  \n";
    cout << "   \\:\\/:/  /       \\::/  /   \\:\\~~\\      \\/__\\:\\  \\      \\:\\  \\        \\:\\/:/  /     \\:\\  \\      ~~~~\\:\\  \\ \n";
    cout << "    \\::/  /        /:/  /     \\:\\__\\          \\:\\__\\      \\:\\__\\        \\::/  /       \\:\\__\\          \\:\\__\\\n";
    cout << "     \\/__/         \\/__/       \\/__/           \\/__/       \\/__/         \\/__/         \\/__/           \\/__/\n";
}

void printRia()
{
    cout << "      ___                       ___                                                                         \n";
    cout << "     /\\  \\                     /\\  \\                                                                        \n";
    cout << "    /::\\  \\       ___         /::\\  \\                                                                       \n";
    cout << "   /:/\\:\\__\\     /\\__\\       /:/\\:\\  \\                                                                      \n";
    cout << "  /:/ /:/  /    /:/__/      /:/ /::\\  \\                                                                     \n";
    cout << " /:/_/:/__/___ /::\\  \\     /:/_/:/\\:\\__\\                                                                    \n";
    cout << " \\:\\/:::::/  / \\/\\:\\  \\__  \\:\\/:/  \\/__/                                                                    \n";
    cout << "  \\::/~~/~~~~   ~~\\:\\/\\__\\  \\::/__/                                                                         \n";
    cout << "   \\:\\~~\\          \\::/  /   \\:\\  \\                                                                         \n";
    cout << "    \\:\\__\\         /:/  /     \\:\\__\\                                                                        \n";
    cout << "     \\/__/         \\/__/       \\/__/                                                                        \n";
    }

void printBlank()
{
    for(int i=0; i<11; i++)
    {
        cout << endl;
    }
}

void clearScreen()
{
    for(int i=0; i<132; i++)
    {
        cout << endl;
    }
}

int main()
{
    int lastTime = time(0);
    const int numFrames = 4;
    int frame = 0;
    
    while(true)
    {
        if(time(0)>lastTime)
        {
            lastTime = time(0);
            switch(frame)
            {
                case 0:
                    clearScreen();
                    break;
                case 1:
                    printHappy();
                    printBlank();
                    printBlank();
                    break;
                case 2:
                    printHappy();
                    printBirthday();
                    printBlank();
                    break;
                case 3:
                    printHappy();
                    printBirthday();
                    printRia();
                    break;
            }
            frame++;
            frame%=numFrames;
        }
    }

    return 0;
}