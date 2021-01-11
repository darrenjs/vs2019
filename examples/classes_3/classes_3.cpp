/*
This is a basic skeleton file we can use to start any project.
*/
#include <iostream>
#include <string>


#define PV(X) \
std::cout << #X << ":" << X << std::endl;


struct Real {
	// Data members
	double value;
	bool is_nan;


	/*  Default Constructor
	*
	* Simply a constructor with no parameters.
	*/
	Real()
		/* initializer-list

		convention: defaults should represent 'nothing'
		this is good practice

		*/
		: value(0.0),
		is_nan(false)
	{ /* body */
	}


	/* Constructor (overloaded)
	*
	*  Job here is to set all of data members
	*  of this class to reasonable values.
	*/
	Real(double value_)
		/* initializer-list */
		: value(value_),
		is_nan(false)
	{
	}

	/* Constructor -- overload & utility */
	Real(std::string s)
		/* initializer-list */
		: value(0.0),
		is_nan(false)
	{
		/*


	first, we want to check if s is empty, in which case, set to NaN
	also, what if the string is just spaces? also NaN
	parse s to get a value

	*/

		try
		{
			// If no conversion could be performed, an invalid_argument exception is thrown.
			value = std::stod(s);
		}
		catch (std::invalid_argument&) // Always catch exceptions by reference
		{
			std::cout << "exception caught in Real(std::string)" << std::endl;
			is_nan = true;
		}

	}

};


// Effective MAIN 
int _main_(int argc, char** argv)
{
	std::cout << "Hello World!\n";


	double raw_price = 0.0;  // what about NaN?  

	std::cout << raw_price << std::endl;  // '????'

	// this code says, construct a variable named 'price'
	// of type 'Real', using the default constructor,
	// i.e., we are passing no argument here.
	Real price;
	Real price3{};
	std::cout << price.value << std::endl;  // '0.0';
	std::cout << price3.value << std::endl;  // '0.0';

	// how do we use it?
	price.value;




	price.is_nan;

	// we have need: convert a string to a value
	// eg, convert "2.3" to a real value
	Real usdgbp("1.3");
	Real usdgbp2("");

	// CONTINUE, and also a static NaN variable
	std::cout << "usdgbp2:" << usdgbp2.value << ", " << usdgbp2.is_nan << std::endl;

	// usdgbp2: nan

	return 0;
}

int main(int argc, char** argv)
{
	try
	{
		return _main_(argc, argv);
	}
	catch (std::exception& e)
	{
		std::cout << "caught exception: " << e.what() << std::endl;
		return 1;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

// To format doc: ctrl-K, ctrl-D
