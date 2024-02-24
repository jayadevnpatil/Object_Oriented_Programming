#include <iostream>
#define COUT(str) std::cout << str << std::endl;

/*
	======================
	|                    |
	|   `this` POINTER   |
	|	             |
	======================

	Background
	----------
	Whenever multiple objects of the same class are created each object gets its 
	own copy of data members, but shares only one copy of member functions. But 
	how are correct data members accessed ??

	Introduction
	------------
	In C++, `this` is a pointer to the object, whose member function is being 
	executed. When the (non-static) member function is called, the compiler 
	implicitly passes `this` pointer as an hidden argument allowing the access
	to the calling object's data members and member functions within that function.

*/

class MyClass 
{
public:

    int x;

    MyClass(int val) : x(val) {}

    void print() 
    {
        // Accessing the member variable 'x' using 'this'
        std::cout << "The value of x is: " << this->x << std::endl;
    }

    void compare(MyClass& other)
    {
        // Accessing the member function 'print()' using 'this'
        this->print();

        // Comparing 'x' of the calling object with 'x' of 'other' object
        if (this->x == other.x)
            std::cout << "Both objects have the same value of x." << std::endl;
        else
            std::cout << "The objects have different values of x." << std::endl;
    }
};

void RunSample1()
{
    MyClass obj1(5);
    MyClass obj2(10);

    obj1.print();
    obj2.print();

    obj1.compare(obj2);
}


// =================================
//       Pointer to an object
// =================================

/*
    An object is similar to any other data type, as pointers can be defined to basic 
    data types in C++, pointers can also be defined for an object type.

    In C++, a pointer to an object is a variable that holds the memory address of an
    object. This allows you to indirectly access and manipulate the object through 
    the pointer.
*/

class Base
{
public:
    Base()
    {}

    virtual void Display()
    {
        COUT("Base class")
    }
};

void RunSample2()
{
    Base b;
    Base* bptr = &b;
    bptr->Display();
}

// =========================================
//      Pointer to derived class object
// =========================================

/*  
    In C++, we can use a base class pointer to refer to objects of a derived class. 
    This is a fundamental aspect of polymorphism and allows for dynamic binding of 
    functions at runtime. 
*/

class Derived : public Base
{
public:
    Derived()
    {}

    void Display()
    {
        COUT("Derived")
    }
};

void RunSample3()
{
    Derived d1;
    Derived d2;
    
    Derived* dptr;
    Base* bptr;

    dptr = &d1;
    bptr = &d2;

    dptr->Display();
    bptr->Display();
}

int main() 
{
    COUT(">> Run Sample1")
    RunSample1();

    COUT(">> Run Sample1")
    RunSample2();

    COUT(">> Run Sample1")
    RunSample3();

    return 0;
}
