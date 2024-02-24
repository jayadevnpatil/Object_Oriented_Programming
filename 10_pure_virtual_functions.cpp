#include <iostream>

/*
	================================
	|                              |
	|     PURE VIRTUAL FUNCTIONS   |
	|                              |
	================================

	Introduction
	------------
	In C++, a pure virtual function is a virtual function declared in a base
	class that has no implementation provided. It serves as a template for 
	derived classes to override and provide their own implementations. Pure 
	virtual functions are declared by assigning 0 to them, indicating that 
	they have no implementation in the base class and must be overridden in 
	derived class.

	Pure virtual functions very essential for achieving Polymorphism.

	Syntax
	------
	class Base 
	{
	public:
		virtual void pureVirtualFunction() = 0;
	};

	Characteristics
	---------------
	- Pure virtual functions have no implementation in the base class and 
	  are meant to be overridden by derived classes.
	- Typically acts as a place holder functions.
        - Any class containing at least one pure virtual function becomes an 
	  abstract base class, and instances of such classes cannot be created.
	- Derived classes must provide an implementation for all pure virtual 
	  functions to be considered concrete classes.

	Usage
	-----
	- Pure virtual functions are useful for defining an interface or protocol
	  that derived classes must adhere to.
	- They enable polymorphic behavior where different derived classes can 
	  have their own specific implementations of the function.

*/

// Abstract Base Class with Pure Virtual Function
class Shape 
{
public:

	// Pure virtual function to calculate area
	virtual double calculateArea() const = 0;

	// Regular member function
	void display() const 
	{
		std::cout << "This is a shape." << std::endl;
	}
};

// Concrete Derived Class
class Circle : public Shape 
{
private:

	double radius;

public:

	Circle(double r) : radius(r)
	{}

	// Implementation of pure virtual function
	double calculateArea() const override 
	{
		return 3.14 * radius * radius;
	}
};

// Concrete Derived Class
class Rectangle : public Shape 
{
private:

	double length;
	double width;

public:

	Rectangle(double l, double w) : length(l), width(w) 
	{}

	// Implementation of pure virtual function
	double calculateArea() const override 
	{
		return length * width;
	}
};

int main() {

	// Shape shape; // Error: Cannot create instance of an abstract class

	Circle circle(5);
	Rectangle rectangle(4, 6);

	circle.display();
	std::cout << "Area of Circle: " << circle.calculateArea() << std::endl;

	rectangle.display();
	std::cout << "Area of Rectangle: " << rectangle.calculateArea() << std::endl;

	return 0;
}


/*
	================================
	|                              |
	|        ABSTRACT CLASS        |
	|                              |
	================================

	Key Features
	------------
	- Pure Virtual Functions: Abstract classes typically contain one or more pure 
				  virtual functions, which must be overridden by 
				  derived classes.

	- No Instantiation: Instances of abstract classes cannot be created. They exist 
	                    only to define a common interface for derived classes.

	- Interface Definition: Abstract classes define an interface that specifies the 
			        functionality required by derived classes.
	
	- Inheritance: Derived classes inherit the interface and structure of the 
	               abstract class but must provide their implementations for pure 
		       virtual functions.
*/
