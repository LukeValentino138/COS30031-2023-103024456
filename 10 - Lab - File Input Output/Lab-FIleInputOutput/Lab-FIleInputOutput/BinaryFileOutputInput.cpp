#include <iostream>
#include <fstream>

using namespace std;

class Basic {
private:
	int _integer;
	char _character;
	float _float;

	std::string filename = "test1.bin";

public:

	Basic(int integer, char character, float f) {
		_integer = integer;
		_character = character;
		_float = f;
	}

	void openFile() {
		std::fstream file(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::app);

		if (!file) {
			std::cerr << "Error, cannot open file" << filename << std::endl;
			return;
		}

		file.write(reinterpret_cast<char*>(&_integer), sizeof(_integer));
		file.write(&_character, sizeof(_character));
		file.write(reinterpret_cast<char*>(&_float), sizeof(_float));

		file.close();
	}

	void readFile() {
		std::fstream file(filename, std::ios::in | std::ios::binary);

		if (!file) {
			std::cerr << "Error, cannot open file << filename << std::endl;
			return;
		}

		file.read(reinterpret_cast<char*>(&_integer), sizeof(_integer));
		file.read(&_character, sizeof(_character));
		file.read(reinterpret_cast<char*>(&_float), sizeof(_float));

		file.close();

		std::cout << "Verify file data:" << std::endl;
		std::cout << "Integer: " << _integer << std::endl;
		std::cout << "Character: " << _character << std::endl;
		std::cout << "Float: " << _float << std::endl;
	}

};

int main() {
	Basic basic(1, 'a', 2.0f);
	basic.readFile();

	return 0;
}