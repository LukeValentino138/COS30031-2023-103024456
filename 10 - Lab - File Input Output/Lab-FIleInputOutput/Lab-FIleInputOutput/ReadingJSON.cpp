#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>

using namespace std;

class ReadJson {
private:
    string filename = "test3.json";
public:
	void readAndPrintJSON() {
        fstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error, cannot open file." << std::endl;
            return;
        }

        nlohmann::json j;
        file >> j;

        std::cout << j.dump(1) << std::endl;
    }

};

int main() {
    ReadJson rj;
    rj.readAndPrintJSON();
    return 0;
}