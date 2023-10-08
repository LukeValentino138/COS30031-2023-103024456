#include <iostream>
using namespace std;

class Basic {
private:

public:
	int _integer;
	char _character;
	float _float;

	Basic(int integer, char character, float f) {
		_integer = integer;
		_character = character;
		_float = f;
	}
};

int main() {
	Basic(1, 'a', 2.0f);
	return 0;
}