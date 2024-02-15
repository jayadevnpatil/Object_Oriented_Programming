#include<iostream>

/*
     ===========================================
     |                                         |
     |             ACCESS SPECIFIERS           |
     |                                         |
     ===========================================
 
    Introduction
    -------------
    Encapsulation is one of the fundamental principles of OOPS that involves bundling 
    data(attributes) and methods(functions) that operate on the data into a single unit 
    known as a class.

    Access specifiers provide encapsulation and data hiding in C++ classes, which is 
    essential for achieving the principles of Object-Oriented Programming (OOP).

    Definition
    ----------
    Access specifiers in C++ are keywords used to control the access level/ visibility of 
    class members.
    
    There are three access specifiers in C++:
    1. Public:
    - Members declared as public are accessible from any part of the program
    - They can be accessed outside the class through object instances
    - Public members provide an interface for interacting with the object
    
    2. Private:
    - Members declared as private are accessible only within the class
    - They are not directly accessible from outside the class or through object instances
	- Public members (methods) can be used to access private members
    - Private members are often used to hide the internal implementation details of a class
    
    3. Protected:
    - Members declared as protected are accessible within the class and its subclasses 
      (derived classes).
    - They are not accessible from outside the class hierarchy.
    - Protected members are used when you want to allow access to derived classes but not to 
      the outside world.
    
    Note: By default, members are private if not specified otherwise.
*/

// =======================
//	  Basic structure
// =======================

class MyCLass 
{

public:

    // Public members can be accessed from any part of the program
    int publicVar;

    // Public member function can be accessed from outside the class
    void publicFunction() 
    {
        std::cout << "Public function called. PublicVar: " << publicVar << std::endl;
    }

private:

    // Private members are only accessible within the class
    int privateVar;

    // Private member function can only be called within the class
    void privateFunction() 
    {
        std::cout << "Private function called. PrivateVar: " << privateVar << std::endl;
    }

protected:

    // Protected members are accessible within the class and its subclasses
    int protectedVar;

    // Protected member function can be called within the class and its subclasses
    void protectedFunction() 
    {
        std::cout << "Protected function called. ProtectedVar: " << protectedVar << std::endl;
    }

};

void RunSample1()
{
    //Creating object of MyClass
    MyCLass obj;

    // Public members can be accessed outside the class
    obj.publicVar = 10;
    obj.publicFunction();

    // Private members cannot be accessed outside the class
    // Uncommenting the following line will result in a compilation error
    // obj.privateVar = 20;
    // obj.privateFunction();

    // Protected members cannot be accessed outside the class hierarchy
    // Uncommenting the following line will result in a compilation error
    // obj.protectedVar = 30;
    // obj.protectedFunction();
}

// =======================
//         Example
// =======================
class BankAccount 
{

private:

    double balance;

public:

    // Public method to access the private member
    void setBalance(double amount) 
    {
        if (amount >= 0)
            balance = amount;
        else
            std::cout << "Invalid amount\n";
    }

    // Public method to display the balance
    void displayBalance() 
    {
        std::cout << "Balance: " << balance << "\n";
    }
};

void RunSample2()
{
    // Creating object of BankAccount
    BankAccount account;

    // Using public methods to access and display the balance of BankAccount
    account.setBalance(1000.50);
    account.displayBalance();
}

int main() 
{
    RunSample1();
    RunSample2();
    return 0;
}
