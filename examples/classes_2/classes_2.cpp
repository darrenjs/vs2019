/*
This is a basic skeleton file we can use to start any project.
*/
#include <iostream>
#include <vector>
#include <string>

#define PV(X) \
std::cout << #X << ":" << X << std::endl;



struct OptionContract {
	// data members
	double S;
	double K;
	double r;
	double v;
	double T;

	// Class constructor. 
	// This is a special function.
	// Note that the function name has to match the name of the class.
	// Is invoked to replace junk in memory with sensible values.
	OptionContract(double _S, double _K, double _r, double _v, double _T)
	{
		std::cout << this->S;  // Junk!!!!

		if (_S < 0.0)
			throw std::runtime_error("S cannot be negative");

		/* use constructor to initalise values */
		this->S = _S;
		this->K = _K;
		this->r = _r;
		this->v = _v;
		this->T = _T;
	}

	// Example of destructor  , optional here, because it doens't do anything.
	~OptionContract()
	{
	}
		
	// This is "method", i.e., "member function".
    // Method means a function that belongs to a class.
	// It has a sneaky hidden argument, the this pointer.
	// Methods contain a "this pointer", which refer to the object the are acting on.
	// We say, "call a method on an object", "method is acting on an object instance".
	void initialise_values(
		double _S, double _K, double _r, double _v,	double _T
	)
	{
		this-> S = _S;
		this-> K = _K;
		this-> r = _r;
		this-> v = _v;
		this-> T = _T;
	}
};

/*
      (front/lowest) -----  40 byte ->|

	  |<--- address: 0x134762
      +-----------------------------+
	  | dbl | dbl | dbl | dbl | dbl |  (OptionContract)
	  | S   | K   | r   | v   | T   |
	  +-----------------------------+

oc ---^  


*/

OptionContract mock_contract()
{
	OptionContract oc;

	oc.S = 1.0;
	oc.K = 2.0;
	oc.r = 0.5;
	oc.v = 0.1;
	oc.T = 0.05;
	return oc;
}


std::vector<OptionContract> mock_contract_list()
{
	std::vector<OptionContract>  retval;

	// explicit introduction of an inner scope, via { },
	// to limit variable lifetime
	{
		OptionContract oc;
		oc.S = 1.0;
		oc.K = 2.0;
		oc.r = 0.5;
		oc.v = 0.1;
		oc.T = 0.05;
		retval.push_back(oc);
	}

	{
		OptionContract oc; 
		oc.S = 2.0;
		oc.K = 2.0;
		oc.r = 0.5;
		oc.v = 2.1;
		oc.T = 0.075;
		retval.push_back(oc);
	}

	return retval;
}


void prototype_contract_2() {

	OptionContract oc(-1.0, 2.0, 0.5, 0.1, 1.1);   // 'oc', is constructed, ie, comes into life

	oc.K;  /// <<  K no longer has risk of containing junk

	OptionContract oc2(2.0, 2.0, 2.5, 2.1, 2.05);   // 'oc', is constructed, ie, comes into life

}


void prototype_contract_1() {

	// (1) construct object  (contains junk, added by C++ compiler)
	OptionContract oc(1.0, 2.0, 0.5, 0.1, 0.05);   // 'oc', is constructed, ie, comes into life
	

	std::cout << oc.S;    // now fully defined!!!! 

	// overwrite
	oc.initialise_values(1.0, 2.0, 0.5, 0.1, 0.05);


	std::cout << oc.S;    // undefined, still have a value.  500. 1.2e18 

	{
		// (2) overwrite members/attributes with desired values
		oc.S = 1.0;
		oc.K = 2.0;
		//oc.r = 0.5;   r left with total junk
		oc.v = 0.1;
		oc.T = 0.05;
	}

	std::cout << oc.S;    // 1.0

}


void prototype_calculation() {

	OptionContract oc1 = mock_contract();
	OptionContract oc2 = mock_contract();
}


const double M_PI = 3.14;

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

double d_j_2(const int& j, OptionContract oc) {
	return (log(oc.S / oc.K) + (oc.r + (pow(-1, j - 1)) * 0.5 * oc.v * oc.v) * oc.T) / (oc.v * (pow(oc.T, 0.5)));
}


/* Framework has a class to represent a price, which is just a double 
   and a flag to indicate NaN*/
struct Real {
	double value;
	bool  is_nan; 

	bool is_zero() {
		return value < 0.000001;
	}
};

// Calculate the European vanilla call price based on
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
Real call_price(const Real& S, const Real& K, const Real& r, const Real& v, const Real& T)
{
	// essential checks to obey the 'contract' that bad/missing input
	// leads to no-price


	// define a special value for no price
    Real no_price;
	no_price.value = 0.0; // not needed
	no_price.is_nan = true;

	// 0.500000000000000000000003"
	// 0.25
	// 0.25
	// 0.000000000000000000000003
	if (S.is_zero()) {  /* dangerous! to check 0.0 */
	}

	
	/* minimal input verification */
	if (S.is_nan)
		return no_price;


	if (S == nan)
		return no_price;

	if (K == nan)
		return no_price;


	return S * norm_cdf(d_j(1, S, K, r, v, T)) - K * exp(-r * T) * norm_cdf(d_j(2, S, K, r, v, T));  
}

// sets is_nan if missing data
Real read_value_from_record( std::string field);


std::vector<double> price_trades() {

    std:vector <double> all_prices;
	std::vector <OptionContract> all_contracts = database_get_trades(); // return 10,000 contracts

	for (contract : all_contracts) {

		/*
		  'S' was missing, we get exception -- 
		  'S' is blank, which means is missing for that record

		*/

		/* pre-verification [OPTIONAL] */
		// TODO: check S is not empty
		// TODO: check r is postive
		// ......  throw PricerInputError("failed on record number 50000, for S");

		/* parsing -- converting from CSV to double  -- mandatory */


		// this is heart of it ... how to we parse missing/bad data?  
		// in python, is NaN.
		// is that true of every framework?  
		// assume:  missing input lead to a NaN   , we assume the framework is doing this



		OptionContract oc;
		const double S = stod(dict['S']);  /// does this throw on a blank string? 
		const double K = 2.0;
		const double r = 3.0;
		const double v = 1.0;
		const double T = 0.0;

		
		
		// error propgation , bad values get turned into NaN , so that call_price returns a NaN

		// (1) need to avoid junk input leading junk output
		// (2) informative error detecting, save the user exploring themselves

		double price = call_pricer(S, K, r, v, T); /* */ 
		all_prices.push_back(price);
		// post-verification -- we only run post-verification for failed trades



		if (price == nan) {
			// do verification here
			// computer know (1) pricer failed  (2) the input data, eg, S, K etc

			if (S == NaN) cout << "S is NaN";
			if (K == NaN) cout << "K is NaN";
		}

	}

	// Perform the price verification entirely outside of the 
	// main pricing loop.
	for (size_t i = 0; i < all_prices.size(); i++) {
		if (all_prices[i] == nan) {
			if (all_conctracts[i].S == NaN) cout << "S is NaN";
			if (all_conctracts[i].K == NaN) cout << "S is NaN";
			if (all_conctracts[i].r == NaN) cout << "S is NaN";
			if (all_conctracts[i].t == NaN) cout << "S is NaN";
			// we dont have S !!!!
		}
	}

	
	return all_prices;
}


double call_price_v2(OptionContract oc) {
	return oc.S * norm_cdf(d_j_2 (1, oc)) - oc.K * exp(-oc.r * oc.T) * norm_cdf(d_j_2(2, oc));
}




// Calculate the European vanilla put price based on
// underlying S, strike K, risk-free rate r, volatility of
// underlying sigma and time to maturity T
double put_price(const double& S, const double& K, const double& r, const double& v, const double& T) {
	return -S * norm_cdf(-d_j(1, S, K, r, v, T)) + K * exp(-r * T) * norm_cdf(-d_j(2, S, K, r, v, T));
}





// Effective MAIN 
int _main_(int argc, char** argv)
{
	std::cout << "Hello World!\n";




	// explore_object();

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
