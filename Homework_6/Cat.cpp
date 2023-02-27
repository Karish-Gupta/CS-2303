// include class definiation from Cat.h
#include "Cat.h"

// constructers

// populate color and type with arguments
Cat::Cat(string tp, string c):Animal(c){
    type = tp;
}

// constructer with no arguments
// make color black and type unk by default 
Cat::Cat():Animal("black"){
    type = "unk";
}

/**************************************************
* void Cat::setType(string tp)
*
* Sets type of variable of cat object to type argument.
*
* Input:
*   string tp: a string that represents a type of cat.
* Output:
*   Returns void and sets type of cat object to tp.
***************************************************/
void Cat::setType(string tp) {
    type = tp;
}

/**************************************************
* void Cat::displayInfo(string c)
*
* Prints type and color to the screen.
*
* Input:
*   string c: a string that represents the color of the cat.
* Output:
*   Returns void and prints cat type and color to screen.
***************************************************/
void Cat::displayInfo(string c) {
    cout << "I am a " << type << endl;
    cout << "My color is " << c << endl;
}

/**************************************************
* void Cat::meow()
*
* Prints cat meows string to the screen.
*
* Input:
*   none
* Output:
*   Returns void and prints cat meows to screen.
***************************************************/
void Cat::meow() {
    cout << "I can speak! Meow meow!!" << endl;
}




