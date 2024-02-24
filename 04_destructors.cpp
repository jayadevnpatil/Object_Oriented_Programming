#include <iostream>

/*
    ===========================================
    |                                         |
    |              DESTRUCTORS                |
    |                                         |
    ===========================================

    Introduction
    -------------
    A destructor is used to destroy objects that have been created by a constructor. 
    They are responsible for releasing resources allocated to the object during its 
    lifetime. 
    
    Like a constructor, the destructor is a member function whose name is the same 
    as the class name but is preceded by a tilde (~).

    Definition
    ----------
    A destructor is a member function of a class with the same name as the class
    preceded by a tilde (~) symbol. It has no return type and takes no parameters. 
    The compiler automatically invokes the destructor when the object is destroyed.

    Characteristics
    ---------------
    - Destructors are the opposite of constructors. While constructors initialize an 
      object's state, destructors clean up resources when the object is no longer 
      needed.
    - They are called automatically when an object is destroyed, either when it goes 
      out of scope or when 'delete' is called on a dynamically allocated object.
    - Destructors are particularly useful for releasing dynamically allocated memory,
      closing files, releasing locks, and performing other cleanup tasks.
    - If a class does not define a destructor, the compiler provides a default 
      destructor that performs no operations.

    Syntax
    ------
    ~ClassName();

*/

// =======================
//     Basic structure
// =======================

class MyClass 
{
public:
    MyClass()  { std::cout << "Constructor called!" << std::endl; }
    ~MyClass() { std::cout << "Destructor  called!" << std::endl; }
};

void RunSample1() 
{
    {
        MyClass obj; // Constructor called
    } // Destructor called when obj goes out of scope

}

int main()
{
    std::cout << ">> Run Sample 1" << std::endl;
    RunSample1();

    return 0;
}