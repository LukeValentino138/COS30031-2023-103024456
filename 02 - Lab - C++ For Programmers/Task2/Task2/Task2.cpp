#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

void one(int a, int b)
{
    std::cout << "-----Feature 1-----" << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

int two(int a) 
{
    std::cout << "-----Feature 2-----" << std::endl;
    a *= 5;
    return a;
}

void three() 
{
    std::cout << "-----Feature 3-----" << std::endl;
    string test = "test";
    string* ptr = &test;
    std::cout << test << std::endl;
    std::cout << ptr << std::endl;
}

void four() 
{
    std::cout << "-----Feature 4-----" << std::endl;
    
    for (int i = 0; i <= 20; i++) 
    {
        if (i % 2 != 0) {
            std::cout << i << " ";
        }
    }
    std::cout<<endl;
}

void five() 
{
    std::cout << "-----Feature 5-----" << std::endl;

    srand(static_cast<unsigned int>(time(0)));

    int array[5];

    for (int i = 0; i < 5; i++) 
    {
        array[i] = rand();
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << array[i] << std::endl;
    }

}

void six() 
{
    std::cout << "-----Feature 6-----" << std::endl;
    string text = "Gondor calls for aid";
    string word = "";

    for (int i = 0; i <= text.size(); i++) 
    {
        char x = text[i];
        if (x == ' ' || i == text.size()) {
            std::cout << word << std::endl;
            word = "";
        }
        else {
            word = word + x;
        }
    }
}

class Seven 
{
    private:
        int value;
    public:
        int value2;

        Seven(int initialValue) : value(5), value2(initialValue) {}

        void feature() {
            std::cout << "-----Feature 7-----" << std::endl;
        }

        int multiply() 
        {
            return value * value2;
        }
};

int main()
{
    int a = 5;
    int b = 10;

    one(a, b);

    int altered = two(a);
    std::cout << altered << std::endl;

    three();

    four();

    five();

    six();

    Seven instance(10);
    instance.feature();
    int product = instance.multiply();
    std::cout << product << std::endl;

    return 0;
}
