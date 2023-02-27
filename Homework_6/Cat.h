#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include "Animal.h"
using std::string;
using std::cout;
using std::endl;

// derived class
class Cat : public Animal {
   public:
        // constructors 
        Cat(string tp, string c); 

        Cat();                      // default type to "unk"

        // methods 
        void setType(string tp);

        void displayInfo(string c);
    
        void meow();    //print "I can speak! Meow meow!!"
};
#endif

