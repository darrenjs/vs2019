#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


struct Trade
{
    int qty;
    double price;

    Trade() {}
    Trade(int quanty, double exec_price)
        : qty(quanty),
        price(exec_price) {
    }

};

void explore_array()
{
    // print out the size of type int

    // print out the size of type double

    // print out the size of type Trade

    // construct an instance of type Trade
    // print out the address of this instance (might need to convert to int for better display)
    // print out the size of this instance

    // declare a array (not vector) type Trade, of size 5

    // print out the address of the array
    // print out the sizeof the array

    // print out the address  of array first item, ie, [0]
    // print out the address  of array second item, ie, [1]
    // print out the address  of array third item, ie, [2]

    // create a pointer to the third item
    // use this pointer to print the address of 'qty' belong to the third item
}



// prototyping the function

void list_example();


int main()
{

    // call function

    list_example();


    return 0;
}

void list_example()

{
    // create a list
    std::vector<std::string> ccys;

    // add some items
    ccys.push_back("GBP");
    ccys.push_back("NZD");
    ccys.push_back("CHF");
    ccys.push_back("EUR");
    ccys.push_back("CAD");


    // print size

    std::cout << "number of ccys: " << ccys.size() << std::endl << std::endl;

    // print out each item
    for (std::string x : ccys)   // BUT: this is use a copy of each item
        std::cout << x << std::endl;

    // test existence

    if (std::find(ccys.begin(), ccys.end(), "JPY") != ccys.end())
    {
        std::cout << std::endl << std::endl << "we have JPY" << std::endl;

    }

    else

    {

        std::cout << std::endl << "missing JPY" << std::endl;

    }

    // remove items

    auto itr = std::find(ccys.begin(), ccys.end(), "CAD");
    if (itr != ccys.end()) ccys.erase(itr);

    // print size

    std::cout << std::endl << "number of ccys: " << ccys.size() << std::endl << std::endl;

}

