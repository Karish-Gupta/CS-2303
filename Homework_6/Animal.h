// base class

#ifndef ANIMAL_H                // if haven't seen ANIMAL_H yet,
#define ANIMAL_H                // then define ANIMAL_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Animal {

    private:
        string color;

    protected:
        string type;

    public:
        Animal(string clr);
        void eat();

        void sleep();

        void setColor(string clr);

        string getColor();
};

#endif