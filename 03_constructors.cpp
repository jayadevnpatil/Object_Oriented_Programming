#include <iostream>

/*
    ===========================================
    |                                         |
    |              CONSTRUCTORS               |
    |                                         |
    ===========================================
 
    Introduction
    -------------
    Constructors are special member functions in C++ that are automatically called
    when an object of a class is created. They initialize the object's state and
    perform any necessary setup operations.

    It is called constructor because it construct the values of data members of the 
    class.

    Definition
    ----------
    A constructor has the same name as the class and no return type. It can be
    used to initialize the data members of an object.

    Characteristics
    ---------------
    - They should be declared in the public section
    - They are invoked automatically when the objects are created
    - They don't have return types, not even void and therefore they cannot return 
      values
    - They cannot be inherited, though a derived class can call the base class 
      constructor
    - Like other C++ function, they can have default arguments

    Types of Constructors
    ---------------------
    1. Default Constructor:
       - Constructor with no parameters.
       - Automatically provided by the compiler if no constructor is explicitly
         defined.
       - Initializes member variables to default values (zero or null) or leaves 
         them uninitialized.

    2. Parameterized Constructor:
       - Constructor with parameters.
       - Allows initialization of member variables with specific values at the time 
       of creation.

    3. Copy Constructor:
       - Constructor that initializes an object using another object of the same class.
       - Automatically provided by the compiler if not defined.
       - Performs a deep copy of the data members

    Constructor Overloading
    -----------------------
    - Like other functions, constructors can be overloaded.
    - Multiple constructors can have the same name but different parameter lists.
    - Provides flexibility in object initialization based on different parameter combinations.

Constructor with member initializer list
It is a mechanism that allows for the initialization of class member variables directly within the constructor declaration.
It provides a concise and efficient way to set the initial values of these members before entering the constructor body.
It improves code readability and performance, especially when dealing with complex types or situations where the order of initialization is crucial.

*/

// =======================
//	  Basic structure
// =======================

class MyClass 
{
public:

    // Default Constructor
    MyClass() 
    {
        std::cout << "Default Constructor called!\n" << std::endl;
    }

    // Parameterized Constructor
    MyClass(int value) 
    {
        std::cout << "Parameterized Constructor called with value: \n" << value << std::endl;
    }

    // Copy Constructor
    MyClass(const MyClass& other) 
    {
        std::cout << "Copy Constructor called!\n" << std::endl;
    }

};

void RunSample1()
{
    // Default Constructor
    MyClass obj1;

    // Parameterized Constructor
    MyClass obj2(42);

    // Copy Constructor
    MyClass obj3(obj1);
    MyClass obj4 = obj1;

    // The copy constructor is not invoked in the following:
    MyClass obj5; // Default constructor
    obj5 = obj1;  // The assignment operator does member-wise copy of values
}


// =======================
//         Example
// =======================

class Wish 
{
public:
    // Default constructor
    Wish() 
    {
        std::cout << "Hello World!" << std::endl;
    }
};

class Person
{
private:
    std::string name;
    int age;

public:
    // Parameterized constructor
    Person(const std::string& n, int a)
    {
        name = n;
        age = a;
    }
};

class MyArray 
{
private:
    int* arr;
    int size;

public:
    // Default constructor
    MyArray()
    {

    }

    // Copy constructor
    MyArray(const MyArray& other) 
    {
        size = other.size;
        arr = new int[size];

        std::memcpy(arr, other.arr, size * sizeof(int));
    }
};

void RunSample1()
{
    MyArray arr1;

    Wish obj1;                  // Calls default constructor
    Person person1("John", 30); // Calls parameterized constructor
    MyArray arr2 = arr1;        // Calls copy constructor
}

/*
    ===========================================
    |                                         |
    |       MEMBER INITIALIZATION LIST        |
    |                                         |
    ===========================================

    Introduction
    -------------
    Member initialization lists in C++ provide a way to initialize class member variables
    directly within the constructor's definition. They offer several advantages over
    traditional assignment within the constructor body.

    Benefits
    --------
    1. Efficiency: Member initialization lists allow for direct initialization of
       member variables, which can be more efficient than assignment within the
       constructor body.

    2. Avoids Default Initialization: Using initialization lists ensures that member
       variables are initialized before the constructor body is executed, preventing
       default initialization.

    3. Initialization of Constants and References: Member initialization lists are
       necessary for initializing constants and reference member variables, which
       cannot be assigned values after initialization.

    Syntax
    ------
    Inside the constructor definition, the member initialization list appears after
    the constructor's parameter list and before the constructor's body. It consists
    of a colon followed by a comma-separated list of member variable initializations.

    Note: The member initialization list syntax initializes each member variable
    using its constructor, if available, or direct initialization syntax.
*/

class MySample 

{
private:

    int x;
    int y;

public:
    MySample()
    {

    }

    // Constructor with member initialization list
    MySample(int a, int b) : x(a), y(b)
    {
        // Constructor body (if needed)
    }
};