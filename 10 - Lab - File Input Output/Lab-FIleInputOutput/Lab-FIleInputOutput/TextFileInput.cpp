#include <iostream>
#include <fstream>
#include <string>


using namespace std;

class TextFile {
private:
	string filename = "test2.txt";
public:
	void editFile() {
		fstream file(filename, fstream::in);


		if (!file) {
			cerr << "Error, cannot open file" << filename << endl;
			return;
		}

		string line;
        while (getline(file, line)) {
            if (line == "") {
                continue;
            }
            else if (line[0] == '#') {
                continue;
            }
            else {
                string word = "";
                int bitsCount = 0;
                for (int i = 0; i <= line.size(); i++) {
                    char x = line[i];
                    if (x == ' ' || i == line.size()) {
                        bitsCount++;
                        cout << word << endl;
                        word = "";
                    }
                    else {
                        word = word + x;
                    }
                }
                if (bitsCount != 2) {
                    cout << "Does not have correct amount of bits." << endl;
                }
            }
        }
		file.close();
	}
};

int main() {
	TextFile tf;
	tf.editFile();

	return 0;
}