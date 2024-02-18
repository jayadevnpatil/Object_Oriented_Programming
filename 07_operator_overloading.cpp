#include <iostream>

/*

    ===========================================
    |                                         |
    |          OPERATOR OVERLOADING           |
    |                                         |
    ===========================================

    Introdunction
    -------------
    Operator overloading in C++ allows you to redefine the behavior of operators such 
    as +, -, *, /, etc.

    We can overload all the C++ operators except the following:
    - Class members access operator (. , .*)
    - Scope resolution operator (: :)
    - Size operator(sizeof)
    - Condition operator (? :)

    When an operator is overloaded, its original meaning is not lost. For example, the 
    operator +, which has been overloaded to add two vectors, can still be used to add 
    two integers.

    The special function called operator function is used to overload the operator, 
    which describes the additional task that the operator has to perform.

    Types of operator overloading
    -----------------------------
    * Based on number of operands ( normal or friend functions )
      1. Unary operator overloading : An operator operating on one operand
      2. Binary operator overloading : An operator operating on two operands

    * Based on the location 
      - Outside class/structure
      - Inside class/structure

    Syntax
    ------
    Note: op is the operator being overloaded.

    * Normal function
        return-type operator op ( arg-list )
        {
            function body
        }

    * Friend function
        friend return-type operator op ( arg-list )
        {
            function body
        }

    * Class Member method
        return-type class-name operator op(arg-list)
        {
            function body
        }

    ALERT !!!!
    ----------
    Don't worry if you don't understand, It's easy understand through examples.
    GO AHEAD
*/

// ===========================================
//       Outside the class/structure
//            Normal Functions
// ===========================================

// Unary operator overloading
void operator + (std::string& str)
{
    std::cout << "Good Morning " << str << std::endl;
}

// Binary operator overloading
void operator - (std::string& wish, std::string& str)
{
    std::cout << wish << " " << str << std::endl;
}

void RunSample1()
{
    std::string str = "Jayadev";
    std::string wish = "Good Evening";

    + str;
    wish - str;
}

// ===========================================
//       Inside the class/structure
//            Friend Functions
// ===========================================

// The parameters (inturn object) required for operator overloading using friend 
// function are `EXPLICITLY` passed to the function.

class DemoFriend
{
private:

    int x=0, a=0, b=0;

public:
    
    // Default constructor 
    DemoFriend()
    {}

    // Parameterized constructor
    DemoFriend(int ix, int ia, int ib) : x(ix), a(ia), b(ib)
    {}

    // Function to display class variables
    void Show() 
    {
        std::cout << "X :" << x << std::endl;
        std::cout << "A :" << a << " B:" << b << std::endl;
        std::cout << std::endl;
    }

    // Unary operator overloading using friend function
    friend DemoFriend operator ~ (DemoFriend& obj) 
    {
        DemoFriend temp;
        temp.x = -obj.x;
        return temp;
    }

    // Binary operator overloading using friend function
    friend DemoFriend operator + (DemoFriend& obj1, DemoFriend& obj2) 
    {
        DemoFriend temp;
        temp.a = obj1.a + obj2.a;
        temp.b = obj1.b + obj2.b;
        return temp;
    }
};

void RunSample2()
{
    std::cout << "Unary overloaded operator ~ " << std::endl;
    DemoFriend obj(5, 0, 0);

    obj.Show();
    obj = ~obj;
    obj.Show();

    std::cout << "Binary overloaded operator + " << std::endl;
    DemoFriend ob1(0, 10, 20);
    DemoFriend ob2(0, 30, 40);
    DemoFriend ob3;

    ob3 = ob1 + ob2;
    ob3.Show();
}

// ===========================================
//       Inside the class/structure
//            Member Functions
// ===========================================

// For operator overloading using member function, we pass one argument less than 
// required as the object used to invoke the member function is passed implicitly 
// and therefore is available for the member functions.


class DemoMember
{
private:
    int x = 0, a = 0, b = 0;

public:
    // Default constructor 
    DemoMember() {}

    // Parameterized constructor
    DemoMember(int ix, int ia, int ib) : x(ix), a(ia), b(ib) {}

    // Function to display class variables
    void Show()
    {
        std::cout << "X :" << x << std::endl;
        std::cout << "A :" << a << " B:" << b << std::endl;
        std::cout << std::endl;
    }

    // Unary operator overloading using member function
    void operator ~()
    {
        x = -x;
    }

    // Binary operator overloading using member function
    DemoMember operator +(const DemoMember& obj)
    {
        DemoMember temp;
        temp.a = a + obj.a;
        temp.b = b + obj.b;
        return temp;
    }

    // OR
    
    //void operator +(const DemoMember& obj)
    //{
    //     a = a + obj.a;
    //     b = b + obj.b;
    //}
};


void RunSample3()
{
    std::cout << "Unary overloaded operator ~ " << std::endl;
    DemoMember obj(5, 0, 0);

    obj.Show();
    ~obj;
    obj.Show();

    std::cout << "Binary overloaded operator + " << std::endl;
    DemoMember ob1(0, 10, 20);
    DemoMember ob2(0, 30, 40);
    DemoMember ob3;

    ob3 = ob1 + ob2;
    ob3.Show();

}
// ==============
//     Main
// ==============

/*
---------------------------------------------------------------
|   Operator to   | Arguments passed to | Arguments passed to |
|    Overload     |    Member Function  |   Friend Function   |
---------------------------------------------------------------
| Unary Operator  |        No           |          1          |
| Binary Operator |         1           |          2          |
---------------------------------------------------------------
*/

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