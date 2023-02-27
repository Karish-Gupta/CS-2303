// C++ program to demonstrate protected members

#include <iostream>
#include <string>
#include "Cat.h"

int main() {
    // Create object of the Cat class
    Cat cat1;

    // Calling members of the base class
    cat1.eat();
    cat1.sleep();
    cat1.setColor("white");

    // Calling member of the derived class
    cat1.meow();
    cat1.setType("mammal");

    // Using getColor() of cat1 as argument
    // getColor() returns string data
    cat1.displayInfo(cat1.getColor());

    return 0;
}