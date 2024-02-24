#include <iostream>

/*
	================================
	|                              |
	|      EXCEPTION HANDLING      |
	|                              |
	================================

	Introduction
	------------
	Whenever a program encounters abnormal situation for which it it not designed 
	to handle, it will pass the control to the special section of the code that 
	handles this error.

	Exceptions refers to unexpected conditions/ errors that causes the program to 
	fail.
	Exception handling in C++ is a mechanism to handle these errors.

	Exception handling in C++ allows you to gracefully handle runtime errors and
	exceptional conditions that may occur during program execution. It provides a 
	mechanism to detect, signal, and handle errors without disrupting the normal 
	flow of the program.

	Exception handling mechanism
	----------------------------
	This mechanism consist of 3 blocks namely : try block, throw block and catch block

	try block   : The try block consist of set of statements which may throw 
	              exceptions
	catch block : Catch block immediately follows try block, which acts as exception 
                  handler
	throw block : This block is used to raise an exception when a error is generated. 
	              It initialise a temporary object of typeT used in throw

	Standard Exceptions
	-------------------
	C++ provides a set of standard exception classes in the <stdexcept> header, such
	as std::runtime_error, std::logic_error, etc., which can be used to represent 
	common types of exceptions.

	Syntax
	------
	try 
	{
		// Code that might throw an exception
		if (condition) 
		{
			throw SomeException("Error message");
		}
	}
	catch (const SomeException& e) 
	{
		// Handling code
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (...) 
	{
		// Catch-all block for handling any other type of exception
		std::cerr << "Unknown exception caught" << std::endl;
	}

*/

double divide(double dividend, double divisor) 
{
	if (divisor == 0) 
	{
		throw "Division by zero error";
	}
	return dividend / divisor;
}

int main()
{
	double a = 10, b = 0;
	try 
	{
		double result = divide(a, b);
		std::cout << "Result: " << result << std::endl;
	}
	catch (const char* error)
	{
		std::cerr << "Error: " << error << std::endl;
	}

	return 0;
}
