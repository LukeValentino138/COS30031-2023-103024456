#include <iostream>
#include <stack>
using namespace std;

//forward declaration for abtsract state
class GameManager;

//Abstract base class with pure virtual methods
class State {
    protected:
        GameManager* _manager = nullptr; 
    public:
        virtual void update() = 0;
        virtual void render() = 0;
};

class GameManager {
    private:
        std::stack<State*> _states; //LIFO
    public:
        //if we have a state, we are running...
        bool running() const {return !_states.empty();}
        //Return the top of LIFO stack!
        State* current() {return _states.top();}

        void push_state(State* state){_states.push(state);}
        void pop_state(){
            delete _states.top();
            _states.pop();
        }

        ~GameManager() {
            while(!_states.empty()) pop_state();
        }

        //constructor - defined after States are defined
        GameManager();
};



class Help : public State {
    public:
    void update() override {
        string command;
        cin >> command;
        if (command == "MainMenu"){
            _manager->pop_state();
        }
    }
    void render() override {
        cout<< "Zorkish :: Help" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout<<"The following commands are supported:" << endl;
        cout<<"quit," << endl;
        cout<<"hiscore" << endl;
        cout << "Press Enter to return to the Main Menu" << endl;
    }

    explicit Help(GameManager* manager){
        _manager=manager;
    }
};

class MainMenu : public State {
    public:
    void update() override {
        string command;
        cin >> command;
        if (command == "3"){
            _manager->push_state(new Help(_manager));
        }
        if (command == "5"){
            _manager->pop_state();
            _manager->pop_state();
        }
    }
    void render() override{
        cout << "Zorkish :: Main Menu" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Welcome to Zorkish Adventures" << endl;
        cout << "1. Select Adventure and Play" << endl;
        cout << "2. Hall of Fame" << endl;
        cout << "3. Help" << endl;
        cout << "4. About" << endl;
        cout << "5. Quit" << endl;
        cout << "Select 1-5: ";
    }

    explicit MainMenu(GameManager* manager) {
        _manager = manager;
    }
};

class Welcome : public State {
    public:
    void update() override {
        _manager->push_state(new MainMenu(_manager));
    }
    void render() override {
        cout << "Starting Game..." << endl;
    }
    explicit Welcome(GameManager* manager) {
        _manager = manager;
    }
};

GameManager::GameManager() {
    //add a first state to be ready
    push_state(new Welcome(this));
}

int main() {
    GameManager manager;
    //game loop
    while (manager.running()){
        manager.current()->render();
        manager.current()->update();
    }
    return 0;
}