
#include "Dog.h"

Dog::Dog(string tp, string c):Animal(c){

    type = tp;
}
Dog::Dog():Animal("black"){
    type = "unk";
}
void Dog::setType(string tp) {
    type = tp;
}

void Dog::displayInfo(string c) {
    cout << "I am a " << type << endl;
    cout << "My color is " << c << endl;
}

void Dog::bark() {
    cout << "I can bark! Woof woof!!" << endl;
}
