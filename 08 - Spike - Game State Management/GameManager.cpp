#include <iostream>
#include <stack>
using namespace std;

//forward declaration for abtsract state
class GameManager;

enum class StateType {
    Welcome,
    MainMenu,
    About,
    Help,
    SelectAdventure,
    Gameplay,
    HighScore,
    HallOfFame,
    None
};

//Abstract base class with pure virtual methods
class State {
protected:
    GameManager* _manager = nullptr;
public:
    virtual StateType getStateType() const = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

class GameManager {
private:
    std::stack<State*> _states; //LIFO
    StateType _previousState = StateType::None;
    int _numPopsRequired = 0;
public:
    //if we have a state, we are running...
    bool running() const { return !_states.empty(); }

    //Return the top of LIFO stack!
    State* current() { return _states.top(); }

    //Get _previous state
    StateType getPreviousState() const { return _previousState; }

    //Queue pops
    void queuePop(int num) {
        _numPopsRequired = num;
    }

    //execute pops
    void executePops() {
        for (int i = 0; i < _numPopsRequired; i++) {
            if (!_states.empty()) {
                pop_state();
            }
        }
        _numPopsRequired = 0;  // Reset counter
    }


    //pushing new state
    void push_state(State* state) {
        if (!_states.empty()) {
            _previousState = _states.top()->getStateType();
        }
        _states.push(state);
    } 

    //popping state
    void pop_state() {
        _previousState = _states.top()->getStateType();
        delete _states.top();
        _states.pop();
    } 

    //destructor
    ~GameManager() { 
        while (!_states.empty()) pop_state();
    }

    //constructor - defined after States are defined
    GameManager();
};

class HallOfFame : public State {
public:
    StateType getStateType() const override {
        return StateType::HallOfFame;
    }
    void update() override {
        string command;
        cin >> command;
        if (command == "MainMenu") {
            if (_manager->getPreviousState() == StateType::HighScore) {
                _manager->queuePop(4);
            }
            if (_manager->getPreviousState() == StateType::MainMenu) {
                _manager->queuePop(2);
            }
        }

    }

    void render() override {
        cout << "Zorkish :: Hall of Fame" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "High Score List" << endl;
        cout << "1. Luke: 12000" << endl;
        cout << "2. George: 11000" << endl;
        cout << "3. Susan: 10000" << endl;
        cout << "4. Newman: 9000" << endl;
        cout << "5. Jerry: 8000" << endl;
        cout << "6. Elaine: 7000" << endl;
        cout << "Press Enter to return to the Main Menu" << endl;
    }

    explicit HallOfFame(GameManager* manager) {
        _manager = manager;
    }
};

class HighScore : public State {
public:
    StateType getStateType() const override {
        return StateType::HighScore;
    }
    void update() override {
        string name;
        cin >> name;
        if (!name.empty()) {
            _manager->push_state(new HallOfFame(_manager));
        }
    }
    void render() override {
        cout << "Zorkish :: New High Score" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Score: 3000" << endl;
        cout << "Enter your Name:" << endl;
    }

    explicit HighScore(GameManager* manager) {
        _manager = manager;
    }
};

class Gameplay : public State {
public:
    StateType getStateType() const override {
        return StateType::Gameplay;
    }
    void update() override {
        string command;
        cin >> command;
        if (command == "1") {
            _manager->push_state(new HighScore(_manager));
        }
        if (command == "2") {
            _manager->queuePop(2);
        }
    }
    void render() override {
        cout << "Zorkish :: Gameplay" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Choose An Option" << endl;
        cout << "1. Finish" << endl;
        cout << "2. Quit" << endl;
    }
    explicit Gameplay(GameManager* manager) {
        _manager = manager;
    }
};

class SelectAdventure : public State {
public:
    StateType getStateType() const override {
        return StateType::SelectAdventure;
    }
    void update() override {
        string command;
        cin >> command;
        if (command == "1") {
            _manager->push_state(new Gameplay(_manager));
        }
        if (command == "MainMenu") {
            _manager->queuePop(1);
        }
    }
    void render() {
        cout << "Zorkish :: Select Adventure" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "1. Game" << endl;
        cout << "Enter 'MainMenu' to return to the Main Menu" << endl;
    }

    explicit SelectAdventure(GameManager* manager) {
        _manager = manager;
    }
};

class About : public State {
public:
    StateType getStateType() const override {
        return StateType::About;
    }
    void update() override {
        string command;
        cin >> command;
        if (command == "MainMenu") {
            _manager->pop_state();
        }
    }
    void render() override {
        cout << "Zorkish :: About" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "Written By: Luke Valentino" << endl;
        cout << "Student Number: 103024456" << endl;
        cout << "Press Enter to return to the Main Menu" << endl;
    }

    explicit About(GameManager* manager) {
        _manager = manager;
    }
};

class Help : public State {
public:
    StateType getStateType() const override {
        return StateType::Help;
    }
    void update() override {
        string command;
        cin >> command;
        if (command == "MainMenu") {
            _manager->pop_state();
        }
    }
    void render() override {
        cout << "Zorkish :: Help" << endl;
        cout << "--------------------------------------------------------" << endl;
        cout << "The following commands are supported:" << endl;
        cout << "quit," << endl;
        cout << "hiscore" << endl;
        cout << "Press Enter to return to the Main Menu" << endl;
    }

    explicit Help(GameManager* manager) {
        _manager = manager;
    }
};

class MainMenu : public State {
public:
    StateType getStateType() const override {
        return StateType::MainMenu;
    }
    void update() override {
        string command;
        cin >> command;
        if (command == "1") {
            _manager->push_state(new SelectAdventure(_manager));
        }
        if (command == "2") {
            _manager->push_state(new HallOfFame(_manager));
        }
        if (command == "3") {
            _manager->push_state(new Help(_manager));
        }
        if (command == "4") {
            _manager->push_state(new About(_manager));
        }
        if (command == "5") {
            _manager->queuePop(2);
        }
    }
    void render() override {
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
    StateType getStateType() const override {
        return StateType::Welcome;
    }
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
    while (manager.running()) {
        manager.current()->render();
        manager.current()->update();
        manager.executePops();
    }
    return 0;
}