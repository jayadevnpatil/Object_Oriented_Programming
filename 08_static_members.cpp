#include <iostream>

/*
    ===========================================
    |                                         |
    |             STATIC MEMBERS              |
    |                                         |
    ===========================================

    Introduction
    ------------
    Static members in C++ are class members that belong to the class rather than 
    individual objects.

    This means that there is only one copy of the static member shared among all
    instances of the class, and it is not associated with any particular object.

    Static variables are normally used to maintain values common to entire class.

    There are two types of static members in a C++ class : 
    * Static data members 
    * Static member functions

    Characteristics
    ---------------
    - Only one copy of static members exists regardless of the number of objects 
      created.
    - They are shared among all instances(objects) of a class.
    - They are initialized only once
    - Static members can be accessed without creating an object of the class by 
      using scope resolution operator '::'.
        
        Static Data Members:
            - Initialized to zero when the first object of its class is created.

        Static Member Functions:
            - A static member function in a class can only access static members
              within the same class, excluding non - static (instance)members.
            - Unlike regular member functions, static member functions lack 
              access to the 'this' pointer, which is specific to instances, as 
              they operate at the class level.
            - Frequently used for utility tasks.

    Declaration
    -----------
    - Static members are declared using the 'static' keyword.
    - They can be variables or member functions.

    Syntax
    ------
    - Static variable declaration: 
            static data-type variable-name;
    - Static member function declaration: 
            static return-type function-name(parameters);

    Usage
    -----
    - Static members are useful for maintaining common data among all objects of 
      the class, such as class-wide constants, counters, or utility functions.
    - They can be accessed using the class name followed by the scope resolution 
      operator '::'.

*/

// ===========================================
//              Static Members
// ===========================================

class MyClass
{
private:

    // Static data member
    static int count;

public:

    MyClass()
    {
        count++;
    }

    // Static member function
    static void DisplayCount()
    {
        std::cout << "Count: " << count << std::endl;
    }
};

// Initialization of static member outside the class
int MyClass::count = 0;

void RunSample1()
{
    MyClass obj1, obj2, obj3;

    // Accessing static member function using class name
    MyClass::DisplayCount(); 
}

// ===========================================
//           Static Member Functions
// ===========================================

class MyUtility
{
public:
    static int Add(int a, int b)
    {
        return a + b;
    }
};

void RunSample2()
{
    // Accessing static member function using class name
    int sum = MyUtility::Add(5, 10); 
    std::cout << "Sum: " << sum << std::endl;
}

int main()
{
    std::cout << ">> Run Sample 1" << std::endl;
    RunSample1();

    std::cout << ">> Run Sample 2" << std::endl;
    RunSample2();

    return 0;
}
