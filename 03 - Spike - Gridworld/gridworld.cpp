#include <iostream>
#include <vector>
using namespace std;

const int arraySize = 8;

class Game {
private:
    struct Player {
        int x;
        int y;
    };

    Player player;
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

public:
    Game() : player{2, 7} {}

    void run() {
        while (true) {
            outputMap();
            cout << endl;
            char dir = processInputs();
            playerMovement(dir);
            EndGameConditions();
        }
    }

private:
    void outputMap() {
        for (int i = 0; i < arraySize; i++) {
            for (int j = 0; j < arraySize; j++) {
                if (i == player.y && j == player.x) {
                    cout << "P";
                } else {
                    cout << mapArray[i][j];
                }
            }
            cout << endl;
        }
    }

    char processInputs() {
        char dir;
        vector<string> availableDir;

        if (player.y > 0 && mapArray[player.y - 1][player.x] != "#") {
            availableDir.push_back("N");
        }
        if (player.y < arraySize - 1 && mapArray[player.y + 1][player.x] != "#") {
            availableDir.push_back("S");
        }
        if (player.x > 0 && mapArray[player.y][player.x - 1] != "#") {
            availableDir.push_back("W");
        }
        if (player.x < arraySize - 1 && mapArray[player.y][player.x + 1] != "#") {
            availableDir.push_back("E");
        }
        availableDir.push_back("Q");
        
        cout << "Choose a direction to travel ( ";
        for (size_t i = 0; i < availableDir.size(); ++i) {
            cout << availableDir[i];
            if (i < availableDir.size() - 1) {
                cout << ", ";
            }
        }
        cout << " ): ";

        bool validDirectionChosen = false;
        while (!validDirectionChosen) {
            cin >> dir;
            dir = toupper(dir);

            for (const string &direction : availableDir) {
                if (direction[0] == dir) {
                    validDirectionChosen = true;
                    break;
                }
            }

            if (!validDirectionChosen) {
                cout << "Invalid direction. Choose a valid direction: ";
            }
        }

        return dir;
    }

    void playerMovement(char dir) {
        switch (dir) {
            case 'N':
                player.y--;
                break;
            case 'S':
                player.y++;
                break;
            case 'W':
                player.x--;
                break;
            case 'E':
                player.x++;
                break;
            case 'Q':
                exit(0);
            default:
                cout << "Invalid direction." << endl;
        }
    }

    void EndGameConditions() {
        if (mapArray[player.y][player.x] == "G") {
            cout << "\nCongratulations! You  Win!" << endl;
            exit(0);
        } else if (mapArray[player.y][player.x] == "D") {
            cout << "\nYou were killed by a cave troll! Game Over!" << endl;
            exit(0);
        }
    }
};

int main() {
    Game game;
    game.run();
    return 0;
}
