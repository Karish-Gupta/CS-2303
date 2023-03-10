To compile the code enter: g++ Animal.cpp Cat.cpp Dog.cpp test_cat.cpp -o runCat.exe
To run the code enter: ./runCat.exe

This program has an animal class which has a private variable called color and a protected variable called type. It also has 4 public functions. The class cat is a derived class of the Animal class. It can be instantiated by entering a type and color or by not using any arguments in the constructor (creating a default cat object with black color and unk type). This class also has 3 methods: setType, displayinfo, and meow. The function setType takes in a string type and sets the cat type to the new string. This variable is protected so it is directly accessible by the cat class. The display info method prints the type and color of the object to the screen.  The meow function prints the cat’s noises to the screen. 

The animal and cat classes and methods are defined in Animal.h and Cat.h respectively. The method logic of each class is defined in the Animal.cpp and Cat.cpp files.

The test_cat file instantiates a cat object. It then runs each of the Animal methods on the cat object. It then calls the derived class methods on the object. 
