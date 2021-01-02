#include <iostream>
#include <map>
#include <string>
#include <iterator>


/*

Primitive Types (from C)
========================

- int  (long int, short int, long long int)
- double
- char
- bool
- float (smaller double)

Aggregrate Types (mainly C++)
=============================

- creating structs and classes
- standard library (std::string, std::map, std::vector, std::set, std::list)
- 3rd party libs  (socket, boosts?)
- your own  (eg, FxPair)

- so "std::" is the namespace
  - use separate class names

*/
int main()
{
	// create a dict
	//
	// store a collection of  std::pair<std::string, double>
	// so, each item of the collection has this type:   std::pair<std::string, double>
	std::map<std::string, double> rates;

	// add some entries
	rates["GBP"] = 1.37; // less efficient, but more common

	rates.insert(std::make_pair("GBP", 1.37));  // <--- much better
	rates.insert(std::make_pair("NZD", 0.72));
	rates.insert(std::make_pair("CHF", 1.11));
	rates.insert(std::make_pair("EUR", 1.21));
	rates.insert(std::make_pair("CAD", 0.79));

	// print out number of entries
	std::cout << "number of entries is " << rates.size() << std::endl << std::endl;

	// print all rates
	std::map<std::string, double>::iterator it = rates.begin();
	while (it != rates.end())
	{
		std::cout << it->first << " :: " << it->second << std::endl;
		it++;
	}

	// Modern C++ pattern way of iterating a container
	//
	// In Python we would write an iteration
	//
	//      for (item in my_list)  print(item);

	// Remember, C++ by defaulyt is passs by copy, so need '&' to use pass by reference (more efficient)
	//
	// Here, const is used to indicate we don't intend to change the items in anyway.
	for (const auto & item : rates) {
		std::cout << item.first << " :: " << item.second << std::endl;
	}

	/*

	STL Container

	-  I-class: set, map(tree), vector, list
	-  II-class: deque, stack, queuehashset, multimap, multiset
	-  III-class: hashset, hastmap

	Same concepts

	- Iterators

	Imagine container is vauge group:   [  {}   {}   {}   {}   {}  ]  ##  <-- 'end' is NOT an item

	Concept of iterators:
										   ^                          ^
										   |                          |
										  begin()                    end()

	 For an empty container:

					 [ ]  ##  <-- 'end' is NOT an item
						  ^^
						  ||
					 begin	end

	Example, lets write out own container:


	class Trades {
		Iterator begin();  // return iterator
		Iterator end();    // return iterator
		Iterator find(); // return iterator
		bool empty();
		int size();
	};


	Trades today_trades;

	for (const auto& trade: today_trades)
	{ ... }

	*/
	// Pre-modern C++, this is preferred way
	// do we have JPY ?  -- here, find returns an iterator to the item, or else, iterator to end()
	if (rates.find("JPY") != rates.end())
		std::cout << std::endl << "found JPY" << std::endl;

	// Note, better to use 'else' here
	// And, here we can use an iterator too.
	std::map<std::string, double>::iterator it2 = rates.find("JPY");
	if (it2 == rates.end())
		std::cout << std::endl << "missing JPY" << std::endl;

	// auto means "type deduction"  ... this is medium C++
	// Note, generally no & here.
	auto it3 = rates.find("JPY");
	if (it3 == rates.end())
		std::cout << std::endl << "missing JPY" << std::endl;

	// delete an item
	rates.erase("GBP");
	std::cout << std::endl << "number of entries is " << rates.size() << std::endl;

	// test is it empty() ?  begin() == end()?   .empty()?  
	// .size() == 0    <--- BAD, this can cause a count to take place

	return 0;
}



class FxPair {};


/*

RETURN BY COPY

For this code:

	FxPair ccy_copy = find_currency("GBPUSD");

--> find_currency

		   FxPair: [GBPUSD, 1.3, major]     <-- our FxPair object, size 100, at 0x5760
  fx -------^

<-- find_currency,

	as we return, we create a copy (its return by copy)


put a COPY of FX into the variable that capture the return ("stack variable")


		  FxPair: [GBPUSD, 1.3, major]     <-- our FxPair object, size 100, at 0x00342160

ccy_copy--^



RETURN BY REFERENCE

But, lets try using a reference, see what happens:


--> find_currency

		   FxPair: [GBPUSD, 1.3, major]     <-- our FxPair object, size 100, at 0x5760
  fx ------^
	  as we return, we create a copy (its return by copy) ... this is a tempory

		   |
<-- find_cu|rency,
		   |
ccy_ref----^

!!!!! But, after function exists, local variables are destroyed.

		   Trade:{????}
		   Junk? abcde62781a

ccy_ref----^

*/

/* Note the return type is not a reference kind, hence, this is RETURN BY COPY.
   Ie it does not have reference &

*/
FxPair  find_currency(std::string name) {
	FxPair  fx;  /* local variable (aka stack variable) */


	FxPair* fx;

	// fetch data base, fill in detaisl of 'fx'
	return fx;
}



// the & says returning a reference, not return by copy
BloombergConnection& get_bloomberg_connection() {
	// 
}

// here we are taking a copy of a thing that is returned by reference
// this might compile
// BAD
BloombergConnection bbg = get_bloomberg_connection();

/*

def get_trades():
   df = pd.DataFrame("file.csv")
   return df.copy()

trades = get_trades()
*/

void main2()
{
	// C++ by dfault, pass by copy, AND, return by copy (opposite to python)

	// For return by copy, we get given a copy of the local variable,
	// before it is destory, which we have to hold on it.
	FxPair ccy_copy = find_currency("GBPUSD");

	// ERROR: we saying ccy_ref is reference to the temporary being return,
	// but the temporary will be destroy.
	FxPair& ccy_ref = find_currency("GBPUSD");  // Python is always this one

	// BUT: we can "extend the lifetime of a temporary" like this
	// This is C/C++, but says, we can have a reference to something
	// that normally would die stragith away, provided our reference
	// is 'const', so that we cannot modify it.
	const  FxPair& ccy_const_ref = find_currency("GBPUSD");

	// LATER: talk about move.
	// C++11 added a new was, in addtion to copy, and ref, this is "move sematics"
}

/*

C 1970's

100K

int:   4 bytes, 10000 - 10003

   sizeof(my_var);   ==> 4
   &my_var           ==> give me the address

manage memory  -- lot of owrk

C++ 1980

   - make it easier
   - object, reference, pass by copy, pass by ref
   - even this is hard
   - NO garbage collection
	 - so what does C++ give me to help
	 - mangement and doing it efficienly

Python

   - totally forget(almost) about memory
   - solving real problems, less cognitive burdenr of manging memeory
   - python does it for you
   - garbage collection

*/




