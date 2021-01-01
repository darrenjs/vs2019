#include <iostream>
#include <map>
#include <string>
#include <iterator>

int main()
{
	// create a dict
	std::map<std::string, double> rates;

	// add some entries
	rates.insert(std::make_pair("GBP", 1.37));
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


	// do we have JPY ?
	if (rates.find("JPY") != rates.end())
		std::cout << std::endl << "found JPY" << std::endl;
	if (rates.find("JPY") == rates.end())
		std::cout << std::endl << "missing JPY" << std::endl;

	// delete an item
	rates.erase("GBP");
	std::cout << std::endl << "number of entries is " << rates.size() << std::endl;


	return 0;
}


