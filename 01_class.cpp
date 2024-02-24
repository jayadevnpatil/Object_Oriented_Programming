#include <iostream>

/*
	===========================================
	|                                         |
	|                 CLASS                   |
	|                                         |
	===========================================
	
	Definition
	----------
	Class is a user-defined data type that serves as a blueprint for creating 
	objects. It encapsulates data and the functions that operate on this data.
	
	Specifying a class
	------------------
	class declaration - shows the type and scope of its members
	class definition  - describes how class functions are implemented
	
	BreakDown
	---------
	The keyword 'class' is used to define a class, the body of the class 
	enclosed in curly braces '{}'
	
	Attributes       : variables 
	Methods          : functions
	Access Specifiers: determine the visibility and accessibility of class 
	                   members
	
	Types of access specfiers
	-------------------------
	public   : Members accessible from outside the class
	private  : Members accessible only from within the class
	protected: Members accessible within the class and derived classes

	Ways of writing class definition
	--------------------------------
	- When a function is written within a class it is called 'inline'
	- Member function declaration outside the class

	  Syntax:
		return-type  class-name :: function-name (argument declaration)
		{
			function body
		}
	
	Difference between class and object
	-----------------------------------
	Class  : A class is like a blueprint or template that defines the properties 
	         (attributes) and behaviors (methods) of a certain entity

	Object : It represents a specific instance of that class, with its own unique 
	         set of data and behavior.
	  
*/

// ======================
//     Class Structure
// ======================

class ClassName 
{

private:
	// private variables and functions

protected:
	// protected variables and functions
	
public:
	// public variables and functions
};

// =======================
//         Example
// =======================
class SampleClass
{

private:
	// private member can be accessed only within the class
	int x;

public:
	// inline method definition, scope is public
	void SetX(int inputX)
	{
		x = inputX;
	}

	// method declaration, scope is public
	int GetX();
};

// class method definition outside the class
int SampleClass::GetX()
{
	return x;
}

int main()
{
	// Creating an object from class template
	SampleClass s;

	// private member of the class
	// std::cout << s.x << std::endl;

	s.SetX(5);
	int x = s.GetX();

	std::cout << "Value of x : " << x << std::endl;
}
