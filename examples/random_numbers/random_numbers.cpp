// random_numbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <random>

// using namespace std;  dont do this.

#define PV(X) \
std::cout << #X << ":" << X << std::endl;

/* Generate a random string of ascii printables of length 'len' */
std::string random_ascii_string(size_t len, unsigned int seed = std::random_device()())
{
   std::string temp(len, 'x'); //  gets overwritten below

   std::mt19937 engine(seed);
   std::uniform_int_distribution<> distr('!', '~'); // asci printables

    for (auto& x : temp)
        x = distr(engine);

    return temp;
}

int _main_(int argc, char** argv)
{
	std::string str1 = random_ascii_string(10);
	PV(str1);

	auto str2 = random_ascii_string(10);
	PV(str2);

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
