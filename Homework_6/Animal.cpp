// base class
#include "Animal.h"

Animal::Animal(string clr) {
    color = clr;
}
void Animal::eat() {
    cout << "I can eat!" << endl;
}

void Animal::sleep() {
    cout << "I can sleep!" << endl;
}

void Animal::setColor(string clr) {
    color = clr;
}

string Animal::getColor() {
    return color;
}
