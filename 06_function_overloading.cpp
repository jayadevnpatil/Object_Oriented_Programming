#include <iostream>

/*
    ===========================================
    |                                         |
    |              OVERLOADING                |
    |                                         |
    ===========================================

    Introduction
    ------------
    Overloading in C++ refers to the ability to define wwo or more members having the 
    same name but different in parameters.There are two main types of overloading in 
    C++:

    1.Function overloading
    2.Operator overloading

    ===========================================
    |                                         |
    |          FUNCTION OVERLOADING           |
    |                                         |
    ===========================================

    Definition
    ----------
    Function overloading is a feature in C++ that allows multiple functions with the same 
    name but different parameters to exist in the same scope. These functions are called 
    overloaded functions, and the process is known as function overloading.
    
    Overloaded functions are resolved at compile time based on the arguments passed to them.
    The compiler determines which function to call based on the number and types of arguments 
    passed to it.

    Purpose
    -------
    It allows developers to create functions that perform similar tasks but operate 
    on different types or numbers of arguments.

     Syntax
     ------
     * Varying number of arguments
     
        return-type FuncionName ( type arg1, type arg2 );
        return-type FuncionName ( type arg1, type arg2, type arg3 );
        return-type FuncionName ( type arg1, type arg2, type arg3, type arg4 );


     * Varying types of arguments
     
        return-type FuncionName ( type1 arg, type1 arg );
        return-type FuncionName ( type2 arg, type2 arg );
        return-type FuncionName ( type3 arg, type3 arg );


     * Varying return type but eithwe of above 2 features
     
        return-type1 FuncionName ( type1 arg );
        return-type2 FuncionName ( type2 arg );
        OR
        return-type1 FuncionName ( type arg1);
        return-type2 FuncionName ( type arg1, type arg2);

     * Any Combination of above

*/

// Function overloading with different parameter lists
void print(int x) 
{
    std::cout << "Integer: " << x << std::endl;
}

void print(double x) 
{
    std::cout << "Double: " << x << std::endl;
}

// Overloaded functions with different number of parameters
int sum(int a, int b) 
{
    return a + b;
}

int sum(int a, int b, int c) 
{
    return a + b + c;
}

// Overloaded functions with different param list and return type
int invert(int a)
{
    return -a;
}

double invert(double b)
{
    return -b;
}

void RunSample()
{
    print(5);
    print(5.60);

    std::cout << sum(4, 5) << std::endl;
    std::cout << sum(4, 5, 6) << std::endl;

    std::cout << invert(5) << std::endl;
    std::cout << invert(5.5) << std::endl;
}

int main()
{
    RunSample();
}
