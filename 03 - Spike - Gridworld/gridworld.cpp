#include <iostream>
using namespace std;

const int arraySize = 8;

struct Player {
    int x;
    int y;
};

string mapArray[arraySize][arraySize] = {
    {"#", "#", "#", "#", "#", "#", "#", "#"},
    {"#", "G", " ", "D", "#", "D", " ", "#"},
    {"#", " ", " ", " ", "#", " ", " ", "#"},
    {"#", "#", "#", " ", "#", " ", "D", "#"},
    {"#", " ", " ", " ", "#", " ", " ", "#"},
    {"#", " ", "#", "#", "#", "#", " ", "#"},
    {"#", " ", " ", " ", " ", " ", " ", "#"},
    {"#", "#", "S", "#", "#", "#", "#", "#"}  
};

void outputMap(Player player)
{
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            if (i == player.y && j == player.x) {
                cout << "P";
            } else {
                cout << mapArray[i][j];
            }
        }
        cout << endl;
    }
}


Player playerMovement(Player player)
{
    char dir;

    cout << "Choose a direction to travel (N,E,S,W) or Quit (Q): ";
    cin >> dir;
    dir = toupper(dir);

    switch (dir) {
        case 'N':
            if (player.y > 0) {
                player.y--;
            }
            break;
        case 'S':
            if (player.y < arraySize - 1) {
                player.y++;
            }
            break;
        case 'W':
            if (player.x > 0) {
                player.x--;
            }
            break;
        case 'E':
            if (player.x < arraySize - 1) {
                player.x++;
            }
            break;
        case 'Q':
            exit(0);
        default:
            cout << "Invalid direction." << endl;
    }
    return player;
}

int main()
{
    Player player = {2, 7};

    while (true) {
        outputMap(player);
        cout << endl;
        player = playerMovement(player);
    }

    return 0;
}
