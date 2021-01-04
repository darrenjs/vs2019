/*
This is a basic skeleton file we can use to start any project.
*/
#include <iostream>

#define PV(X) \
std::cout << #X << ":" << X << std::endl;

/* A class - that was added to C++ */
class FxPair {
	// all these members below are Private, by default
	std::string ccy1;
	std::string ccy2;
};

/* A struct -- this is from C */
struct FxPair {
	// all these members below are Public, by default
	std::string ccy1;
	std::string ccy2;
};


// Why classes?

char FORWARD = 'F';
char FUTURE = 'f';

/*
import FxLib
#include "FxLib.h"
*/


// New Trade API

// struct (and class) defines a type, so Trade is now a type,  **just like int**

// idea is encapsulation of related data

// now, we have our first model (a class!) of what a real world trade looks like 

// also called a record
struct Trade   
{
	int volume;
	double price;
	char side;
};

// string is a C++ defined Type, a class
//
//  'j', 'o', 'e'
std::string name = "joe";  


Trade read_single_trade_from_csv(std::string filename) {

	// open_file(filename)
	
	Trade t = file.read_trade();
	return t;
}

/*
std::vector< Trade >    trades;
^^^^^^^^^^^^^^^^^^^^    ^^^^^^^
C++TYPE                  NAME
*/

// #include "fxquant/utils/csvreader.h"


struct OptionContract {
	double S;
	double K;	
};

struct OptionPricing
{
	double call;
	double put;
	//std::string model_name;
};

 std::vector< OptionPricing> price_contracts(std::vector< OptionContract> contracts) {

	 std::vector< OptionPricing> prices;
	 
	for (constract : contracts) {
		double call = call_price(constract);
		double put = put_price(constract);

		OptionPricing pricing;
		pricing.call = call;
		pricing.put = put;
		prices.push_back(pricing);

		//OptionPricing 
	}

	return prices;
}

struct CsvReader
{
  	std::vector< std::vector<std::string>  > read_lines();
	//           ^^^^^^^^^^^^^^^^^^^^^^^
	//            strings of a single row
};

std::vector<Trade> read_multi_trades_from_csv (std::string filename)  // <=== refered to as the function signature
// ^^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^^^^^^^^^^^ ^^^^^^^^^^^^^^^^^^^^^
//  return type        name                          argument
{ 
	std::vector<int>  scores;  // vector template type
	//  [  [int][int][int] ]

	// side, volume, price
	//    b,1000,1.4,    GBPUSD FORWARD JUNE ,2021, 
	//    s,200,2.1
	std::vector<Trade> list_of_trades;
	CsvReader reader(filename, delimintor=",", trim_space=true);

	for (line : reader.read_lines()) {   // loops/iteratse over each line in CSV file

		// iterate/parse a line into separate components
		char side = string_to_char( line.get(0) );
		int volume = string_to_int(line.get(1));
		double price = string_to_double( line.get(2) );

		// construct a single object
		Trade trade;
		trade.side = side;
		trade.volume = volume;
		trade.price = price;

		// copy into  to our collection
		list_of_trades.push_back(trade);
	}

	// [  [Trade]              [Trade]              [Trade]               ]
	// [  [volume|price|side]  [volume|price|side]  [volume|price|side]   ]

	return list_of_trades;
}

void create_dummy_trade()
{
	// 3 vars for the building blocks of the trade
	int volume = 100.0;
	double price = 0.97;
	char side = 'B';

	save_to_csv("single_trade.csv", side, price, volume);

	// Using the Trade class
	Trade example_trade;

	// python:  example_trade = [100.0, 0.97, 'B']

	example_trade.volume = 100.0;
	example_trade.price = 0.97
	example_trade.side = 'B';

	save_to_csv_v2("single_trade.csv", example_trade);
}

// Repeats

/*
Problems of this approach

1. repetative
2. prone to various erros, eg, ordering, mismatch of type

*/

void send_to_plot_dashboard_v2(Trade trade, double value_usd)
{
	// socket.connect_to_gui();
	// socket.send(tostring(trade.price), tostring(trade.volume), tostring(value_usd));
}

void send_to_plot_dashboard(int price, int volume, double value_usd)
{
}
void send_to_plot_dashboard_v2(Trade trade, double value_usd)
{
}

void store_trade(int volume, double price, char optionType, std::string instumentId, std::string ccy, double value_usd)
{
	// WRITE TO AN EXTERNAL SYSTEM, EG DATABASE
}
void store_trade_v2(Trade trade, char optionType, std::string instumentId, std::string ccy, double value_usd)
{
	// WRITE TO AN EXTERNAL SYSTEM, EG DATABASE
}


double price_trade(int volume, double price, char optionType, std::string instumentId, std::string ccy) {
	// COMPLETE
	return 100.0;
}
double price_trade_v2(Trade trade, char optionType, std::string instumentId, std::string ccy) {
	// COMPLETE
	return 100.0;
}

void raise_approval_alert(int volume, double price, char optionType, std::string instumentId, std::string ccy, double value_usd)
{
	// SEND AN EMAIL TO OPERATIONS
}

void raise_approval_alert_v2(Trade trade, char optionType, std::string instumentId, std::string ccy, double value_usd)
{
	// SEND AN EMAIL TO OPERATIONS
}



void analysis() {

	// build an example trade
	//tradeSource.getLastTrade().get_volume();
	//tradeSource.getLastTrade().get_price();

	const double limit_threshold = 10000000;

	// shape of trade
	int volume = 100.0;
	double price = 0.97;
	char side; 
	string entity_code;
	char optionType = FORWARD;
	std::string instumentId = "USD/NZD";
	std::string ccy = "USD";

	// aside: if we had multiple trades -- VERY UGLY, ERROR PRONE
	vector<int> volumes; // 5
	vector<double> prices; // 5
	for (int = 0; i < 5; i++) {
		int vol = volumes[i];
		int prc = prices[i];
	}

	double trade_value_usd = price_trade(volume, price, optionType, instumentId, ccy);
	store_trade(volume, price, optionType, instumentId, ccy, trade_value_usd);

	if (trade_value_usd > limit_threshold)
		raise_approval_alert(volume, price, optionType, instumentId, ccy, trade_value_usd);

	send_to_plot_dashboard( volume,  price,  value_usd);
}


void analysis_v2() {

	// build an example trade
	//tradeSource.getLastTrade().get_volume();
	//tradeSource.getLastTrade().get_price();

	const double limit_threshold = 10000000;

	// shape of trade
	Trade trade;   /// instantiation: create/construct instance of a class

	trade.volume = 100.0;
	trade.price = 0.97;
	//char side;
	char optionType = FORWARD;
	std::string instumentId = "USD/NZD";
	std::string ccy = "USD";

	double trade_value_usd = price_trade_v2(trade, optionType, instumentId, ccy);
	store_trade_v2(trade, optionType, instumentId, ccy, trade_value_usd);

	if (trade_value_usd > limit_threshold)
		raise_approval_alert_v2(trade, optionType, instumentId, ccy, trade_value_usd);

	send_to_plot_dashboard_v2(trade, value_usd);

	// aside: if we had multiple trades 
	std::vector< Trade > trades;
	std::map< int, Trade> map_of_id_to_trade;
	
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
