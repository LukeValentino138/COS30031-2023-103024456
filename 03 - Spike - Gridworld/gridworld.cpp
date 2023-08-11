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

    bool canMoveNorth = (player.y > 0 && mapArray[player.y-1][player.x] != "#");
    bool canMoveSouth = (player.y < arraySize - 1 && mapArray[player.y + 1][player.x] != "#");
    bool canMoveWest = (player.x > 0 && mapArray[player.y][player.x - 1] != "#");
    bool canMoveEast = (player.x < arraySize - 1 && mapArray[player.y][player.x + 1] != "#");

    cout << "Choose a direction to travel: ";
    if (canMoveNorth) cout << "N ";
    if (canMoveSouth) cout << "S ";
    if (canMoveWest) cout << "W ";
    if (canMoveEast) cout << "E ";
    cout << "or Quit (Q): ";

    cin >> dir;
    dir = toupper(dir);

    switch (dir) {
        case 'N':
            if (canMoveNorth) {
                player.y--;
            } else {
                cout << "Invalid direction." << endl;
            }
            break;
        case 'S':
            if (canMoveSouth) {
                player.y++;
            } else {
                cout << "Invalid direction." << endl;
            }
            break;
        case 'W':
            if (canMoveWest) {
                player.x--;
            } else {
                cout << "Invalid direction." << endl;
            }
            break;
        case 'E':
            if (canMoveEast) {
                player.x++;
            } else {
                cout << "Invalid direction." << endl;
            }
            break;
        case 'Q':
            exit(0);
        default:
            cout << "Invalid direction." << endl;
    }
    return player;
}



void EndGameConditions(Player player){
    if (mapArray[player.y][player.x] == "G"){
        cout << "\nCongratulations! You  Win!"<<endl;
        exit(0);
    } else if (mapArray[player.y][player.x] == "D"){
        cout <<"\nYou were killed by a cave troll! Game Over!" << endl;
        exit(0);
    }
}

int main()
{
    Player player = {2, 7};

    while (true) {
        outputMap(player);
        cout << endl;
        player = playerMovement(player);
        EndGameConditions(player);
    }

    return 0;
}
