#include <iostream>

using namespace std;

class Person{

    // friend void diplay(Person & person){
    //         cout<< "age" << person.age << endl;
    //   }

    public:

        Person(){};

    protected:
        int age =12;
    

};


class Player : private Person{


    friend void display(Player& player){
        cout << "player age "  << player.age << endl;
    }

    public:

        Player(){};

    private:

        int age2 =10;


};


// Definition of the friend function

int main() {

    Player obj;
    display(obj); // Initially privateData = 0

    // friendFunction(obj); // Call to the friend function

    // obj.display(); // Now privateData = 42

    return 0;
}