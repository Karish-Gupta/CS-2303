#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>
#include "Animal.h"
using std::string;
using std::cout;
using std::endl;

// derived class
class Dog : public Animal {

    public:
        Dog(string tp, string c);

        Dog();
        void setType(string tp);

        void displayInfo(string c);
    
        void bark();
};
#endif




