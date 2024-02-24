#include <iostream>

/*
    ===========================================
    |                                         |
    |              POLYMORPHISM               |
    |                                         |
    ===========================================

    Introduction
    ------------
    Polymorphism == Many forms

    Polymorphism is one of the core concepts in object-oriented programming (OOP).
    It refers to the ability of a function/ operator/ object to behave in
    specific ways based on the objects it operates on or the context in which it 
    is called.

    Types of Polymorphism
    ---------------------
    1. Compiler Time Polymorphism:
       - Resolved by the compiler during compile-time.
       - Achieved through function overloading and operator overloading.
       - The other names for this type of polymorphism : Early Binding, Static 
         polymorphism.

    2. Run Time Polymorphism:
       - Resolved during the runtime.
       - Achieved through function and member overriding, primarily using virtual
         functions.
       - The other names for this type of polymorphism : Late Binding, Dynamic 
         polymorphism.

    Types of Compile Time Polymorphism
    -----------------------------------
    1. Function Overloading:
       - Defining multiple functions with the same name but different parameters.
       - The appropriate function is determined by the number and types of
         arguments during compile-time.

    2. Operator Overloading:
       - Redefining the behavior of operators such as +, -, *, etc., for user-
         defined types.
       - Enables the use of operators with user-defined types.

       Note : Refer Earlier scripts of this repository for types of compile time 
              polymorphism

    Types of Run Time Polymorphism
    --------------------------------
    1. Function and Member Overriding:
       - In Inheritence, Base class and Derived class can have same members
       - Redefining a base class function or member in a derived class is called 
         Overriding
       - The appropriate function or member is determined by the type of the 
         calling object at runtime.

    2. Virtual Functions:
       // The Content will be explained below......
*/

// ===========================================
//           Run Time Polymorphism
//      1. Function and Member Overriding
// ===========================================

class Animal
{
public:

    void sound()
    {
        std::cout << "Animal makes a sound" << std::endl;
    }

    bool isTailPresent = false;
};

class Dog : public Animal
{
public:

    // Overriding of base class method
    void sound()
    {
        std::cout << "Dog barks" << std::endl;
    }

    // Overriding of base class member
    bool isTailPresent = true;
};

void RunSample1()
{
    Animal a;
    Dog d;

    // Based on the type of the object the member is invoked
    std::cout << a.isTailPresent << std::endl;
    a.sound();

    std::cout << d.isTailPresent << std::endl;
    d.sound();

    // Accessing base class members through derived class
    d.::Animal::sound();
}

// ===========================================
//           Run Time Polymorphism
//           2. Virtual Functions
// ===========================================

/*
    VERY VERY IMPORTANT !!!
    -----------------------
    Consider a situation where we use base class pointer to point to an 
    object of the derived class, even though the calling object is derived,
    since the pointer to the object is of base class, it is binded during 
    the compile time, resulting in a call for base class member function.

    Refer the below example to understand above explaination
*/

class Base 
{
public:

    void print() 
    {
        std::cout << "Base Function" << std::endl;
    }
};

class Derived : public Base 
{
public:

    void print() 
    {
        std::cout << "Derived Function" << std::endl;
    }
};

void RunSample2()
{
    Base* bPtr;
    bPtr = new Derived;

    // Compile time bining
    // OP Expected : "Derived Function"
    // OP Obtained : "Base Function"
    bPtr->print();
}

/*
    Virtual functions are member functions in a base class that are declared with 
    the keyword `virtual`.They are intended to be overridden by derived classes. 
    
    When a virtual function is called through a base class pointer or reference, 
    the function call is resolved dynamically based on the actual object type 
    pointed to or referenced at runtime. This mechanism is known as late binding.

    In C++, virtual functions enable polymorphism, allowing different derived 
    classes to provide their own implementation of the same function declared 
    in the base class.

    Syntax
    ------
    The general syntax of the virtual function declaration is:
        
        class class_name
        {
        public:
            virtual return_type function_name1 (arguments);
            virtual return_type function_name2 (arguments);
            virtual return_type function_name3 (arguments);
        }

*/

class BaseV
{
public:
    // THIS MAKES DIFFERENCE
    virtual void print()
    {
        std::cout << "Base Function" << std::endl;
    }
};

class DerivedV : public BaseV
{
public:

    void print() override
    {
        std::cout << "Derived Function" << std::endl;
    }
};

void RunSample3()
{
    BaseV* bPtr;
    bPtr = new DerivedV;

    // Run time bining
    // OP Expected : "Derived Function"
    // OP Obtained : "Derived Function"
    bPtr->print();
}

/*
    ^The keyword `virtual` instructs the compiler to perform late binding, so as 
    to check the type of the object during the run time, and match with relevant 
    functions.

    ^In simple terms, virtual functions asserts the polymorphic behaviour by 
    different function being executed instead of knowing the exact type of 
    object invoked.

    The below example shows how with  base class pointers and without knowing the
    type of derived class objects the member methods can be called.
*/

class Matter
{
public:
    virtual void Definition()
    {
        std::cout << "A state of matter is one of the distinct \
                     forms in which matter can exist" << std::endl;
    }
};

class Solid : public Matter
{
public:
    void Definition()
    {
        std::cout << "Solid : Particles are tightly arranged" << std::endl;
    }
};

class Liquid : public Matter
{
public:
    void Definition()
    {
        std::cout << "Liquid : Particles are close, but can move around" << std::endl;
    }
};

void RunSample4()
{
    // Creating the objects of different derived classes
    Solid s;
    Liquid l;

    // Creating pointers of base class
    Matter *ps, *pl;

    // Assigning the reference of objects to pointers
    ps = &s;
    pl = &l;

    // Calling the functions
    ps->Definition(); // Each execute their own version
    pl->Definition(); // of the function call
}

int main()
{
    std::cout << ">> Run Sample 1" << std::endl;
    RunSample1();
    std::cout << ">> Run Sample 2" << std::endl;
    RunSample2();
    std::cout << ">> Run Sample 3" << std::endl;
    RunSample3();
    std::cout << ">> Run Sample 4" << std::endl;
    RunSample4();
}