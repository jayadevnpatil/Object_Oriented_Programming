#include <iostream>

/*
    ===========================================
    |                                         |
    |             FRIEND FUNCTIONS            |
    |                                         |
    ===========================================

    Introduction
    -------------
    Friend functions in C++ provide access to private and protected members of 
    a class from outside the class scope. They are not members of the class but 
    have access to its private and protected members.

    This facilitates the sharing of specific functionalities without requiring 
    to be incorporated as class members

    Definition
    ----------
    A friend function of a class is a function (external) that is not a member 
    of the class but has access to its private and protected members. 
    
    Characteristics
    ---------------
    - They are declared inside the class with the 'friend' keyword.
    - They are not in the scope of the class to which they are declared as friend.
    - They can be invoked like a member function without the help of any object.

    - They can be used to access private and protected members of the class.
    - They can be regular functions or member functions of other classes.

    Usage
    -----
    - Friend functions are often used when an external function/ member functions 
      of other classes needs access to private or protected members of a class for 
      specific operations
    - They can provide flexibility in design by allowing certain functions to 
      interact directly with class internals while maintaining encapsulation.

    Declaration
    -----------
    It is declared using the `friend` keyword inside the class.The friend function 
    is defined outside of any class using the regular C++ function syntax.The 
    definition does not use the `friend` keyword or the scope operator `::`

    Syntax
    ------
    friend return-type function-name(parameters);

    Note: The friend function declaration must appear inside the class definition,
    but the actual function definition can be outside the class.
*/

// =======================
//     Basic structure
// =======================

class MyClass
{
private:

    int data;

public:

    MyClass(int d) : data(d) 
    {}

    // Declaration of friend function
    friend void DisplayData(const MyClass& obj);
};

// Definition of friend function
void DisplayData(const MyClass& obj)
{
    std::cout << "Data from friend function: " << obj.data << std::endl;
}

void RunSample1()
{
    MyClass obj(42);

    // Accessing private member through friend function
    DisplayData(obj); 
}

/*
    ===========================================
    |                                         |
    |             FRIEND CLASSES              |
    |                                         |
    ===========================================

    Definition
    ----------
    A friend class is a class that is granted access to the private and protected
    members of another class. It is declared using the 'friend' keyword inside the 
    class whose members need to be accessed.

    Syntax
    ------
    friend class ClassName;

*/

// =======================
//     Basic structure
// =======================

class SampleClass
{
private:
    int value;

public:
    SampleClass(int v) : value(v) {}

    // Declaration of friend class
    friend class FriendClass;
};

class FriendClass
{
public:
    void DisplayValue(const SampleClass& obj)
    {
        std::cout << "Value from FriendClass: " << obj.value << std::endl;
    }
};

void RunSample2()
{
    SampleClass obj(100);
    FriendClass fc;

    // Accessing private member through friend class
    fc.DisplayValue(obj);
}


// ==================================================
//    Example : A function friendly to two classes
// ==================================================

// Forward declaration
class Class2;

class Class1 
{
private:

    int value1;

public:

    void SetData(int val) { value1 = val; }
    void Display() { std::cout << value1 << std::endl; }
    friend void Exchange(Class1&, Class2&);
};

class Class2 
{
private:

    int value2;

public:

    void SetData(int val) { value2 = val; }
    void Display() { std::cout << value2 << std::endl; }
    friend void Exchange(Class1&, Class2&);
};

void Exchange(Class1& x, Class2& y) {
    int temp = x.value1;
    x.value1 = y.value2;
    y.value2 = temp;
}

void RunSample3() 
{
    Class1 c1;
    Class2 c2;

    c1.SetData(100);
    c2.SetData(200);

    std::cout << "Values before exchange:" << std::endl;

    c1.Display();
    c2.Display();

    Exchange(c1, c2);

    std::cout << "Values after exchange:" << std::endl;

    c1.Display();
    c2.Display();
}

int main() 
{
    std::cout << ">> Run Sample 1" << std::endl;
    RunSample1();

    std::cout << ">> Run Sample 2" << std::endl;
    RunSample2();

    std::cout << ">> Run Sample 3" << std::endl;
    RunSample3();
    return 0;
}
