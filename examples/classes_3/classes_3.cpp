/*
This is a basic skeleton file we can use to start any project.
*/
#include <iostream>
#include <string>
#include <map>
#include <cmath>


#define PV(X) \
std::cout << #X << ":" << X << std::endl;

/* Represent a real number, ie, double + NaN indicator */
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
		/* Reminder: C++ default is pass-by-copy (python is pass-by-ref). So, in C++, we
		   can use & for pass-by-ref, avoids a copy being made, more efficient.  */
		catch (const std::invalid_argument& error) // Always catch exceptions by reference (and const reference if possible)
		{
			// example of helpful user message; do not make string checks
			// on the what() message.  Cannot guarentee will be consistent.
			std::cout << "error, cannot convert value '" << s << "' to double (exection:" << error.what() << ")" << std::endl;
			is_nan = true;
		}

	}

};


std::map<std::string, std::string> read_record_from_file() {
	return {};
}



struct OptionContract
{
	Real S;
	Real K;
	Real T;
	Real r;
	Real v;
	Real j;
};


// Standard normal probability density function
double norm_pdf(const double& x) {
	return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x);
}

// An approximation to the cumulative distribution function
// for the standard normal distribution
// Note: This is a recursive function
double norm_cdf(const double& x) {
	double k = 1.0 / (1.0 + 0.2316419 * x);
	double k_sum = k * (0.319381530 + k * (-0.356563782 + k * (1.781477937 + k * (-1.821255978 + 1.330274429 * k))));

	if (x >= 0.0) {
		return (1.0 - (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x) * k_sum);
	}
	else {
		return 1.0 - norm_cdf(-x);
	}
}

// This calculates d_j, for j in {1,2}. This term appears in the closed
// form solution for the European call or put price
double d_j(const int& j, const double& S, const double& K, const double& r, const double& v, const double& T) {
	return (log(S / K) + (r + (pow(-1, j - 1)) * 0.5 * v * v) * T) / (v * (pow(T, 0.5)));
}

double d_j_v3(const int& j, OptionContract oc) {
	return (log(oc.S.value / oc.K.value) + (oc.r.value + (pow(-1, j - 1)) * 0.5 * oc.v.value * oc.v.value) * oc.T.value) / (oc.v.value * (std::pow(oc.T.value, 0.5)));
}

// With V3 we can handle missing values
Real call_price_v3(OptionContract oc) {

	// if S is missing, return a Real(nan)
	if (oc.S.is_nan == true) {
		Real nan;
		nan.is_nan = true;
		return nan; 
	}

	// otherwise, perform calculation
	Real retval;
	retval.value = oc.S.value * norm_cdf(d_j_v3(1, oc)) - oc.K.value * exp(-oc.r.value * oc.T.value) * norm_cdf(d_j_v3(2, oc));
	return retval;
}





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


	std::map<std::string, std::string> raw_values = read_record_from_file();

	// Rule: if you lookup map value, and not found, returns empty string.
	std::string raw_S = raw_values["S"];

	Real my_S(raw_S);
	std::cout << "S has value: " << my_S.value << ":" << my_S.is_nan << std::endl;


	OptionContract oc;
	oc.S = my_S;
	oc.K = 2.0;

	std::cout << "break" << std::endl;

	// we have need: convert a string to a value
	// eg, convert "2.3" to a real value
	Real usdgbp("1.3");
	Real usdgbp2("   ");

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
