#include <iostream>

// ???
#define PV(X) \
std::cout << #X << ":" << X << std::endl;

//  
//   edit --> build(compile)  -> link ->  run / debug   --> GIT 
//
//             does it build?             does is run?
//


/*
double price_trade(TradeDetails, MarketData);

Two ways to build Quant frameworks

I - flat function, simple data parameters to function
II - classes, OOP, domain specific model

C++   "object oriented programming  OOP"

class TradeDetails
{
	int volume;
	double price;
	Currency localCcy;
	BookingState state;  // int: 0 = live, 1=booked, 2=cancelled
};

class BookedTrade {
	TradeDetails the_trade;
	string account_id;
	DateTime booking_date;
};

class FXMarketData {

};

class FXTick {

};

class Currney {
};

class CurrencyPair {

};

class FXInstrumcnt {
};

*/

/*

(1) read code
	- downloaded (rather than webpage)
	- VS install
	- other third party installed (database libraries, boost etc)
	- loaded project (quant framework) into VS,
	- use VS to read, explore & understand the code of existing quant framework
	- edit
	- create a hello world example,  call anything from the project system


(2) prototype
	- find examples / existing code / understand internal libraries
	- build basic example
	  - including,
		 - access ref data (currencys, instruments)
		 - access mkt data
		 - access trade history


(3) jupiter notebook



// What is they DataFrame equivalent?

// Finding a simple exaple in the exsiting code base
*/


/*
class BusinessAccount:
	principle,
	maccode
	shourt_id
	fund_name

class Position :
	currency,
	amount_usd,

class FxPositionSet   // their equiv of a dataframe
	list of positions;

*/

/*
position_df  : This is a dataFrame, withindex of major currency
*/
void price_fx_risk( /*FXPositionSet position_df, BusinessAccount  accounttid */) {
	double fxrate = 0.0;      // mistake!!!!
	// fxrate = database_get_rate("GBPUSD");
	//assert(fxrate != 0.0);
	// dfdsfsd
}

/*
core_utilies
readCSVDataFromFile(directoryname, filename, extension, handle_comma);

df = FxPositionSet.read_csv("fx_postiosn.csv")

price_fx_risk(df, "");  // <==== you want to call this




df = pd.read_csv()
accountit = "dummy;"

*/
// Effective MAIN 
int _main_(int argc, char** argv)
{
	std::cout << "Hello World!\n";

	// explore_object();

	return 0;
}



//  (1) array   (C)
//  (2) vector  (C++)  <==== python array/list


//   play_movies     terminator.mp4     aliens.mp4 
//              0                 1              2

//   ["play_movies", "terminator.mp4", "aliens.mp4"]   len:3

// "arguments"   --> 
// argc : argument Count.  == 3
// argv : argument Values  == ["play_movies", "terminator.mp4", "aliens.mp4"]


// generally accepted format of main(...) 


const double M_PI = 3.14;

/*
(1) rule
	 - const
(2) pattern
*/


class DataFrame {
	void update_base_ccy_tousd();
};


void graph_pnl(const DataFrame historic_position)
{
	// (1) change historic_position to USD

	// historic_position.update_base_ccy_tousd();  // EERROR .. cannt modify const obkect

	// (2) draw gprah 


}
class Position {};
void compute_pnl(const Position positions) {
	// position.flatten();
}




// Pass by Copy     
void print_int(int i) {
	// print(i);
}

// Pass by Reference 
void normalise_positions_to_usd(Position& pos) {
	// pos.append('USD');
}




class TradeListSource {};

class MarketDataProvider {};

class MarketDataSnapshot {};

class FxRiskPricer {};
class DateTime {};
class ProductType {};
// 



class FxTrade {
	FxPair instrument;
	double trade_price;
	double volumne;
	int side; // 1:buy -1:sell
	DateTime trade_lime;
	std::string desk;
	std::string traderid;
	ProductType type;
};

class Real {

};

// This models a pair of currencies
struct FxPair {
	std::string ccy1;
	std::string ccy2;

	// Constructor
	FxPair() {}
	FxPair(std::string ccy1, std::string ccy2) {
		ccy1 = ccy1;
		ccy2 = ccy2;
	}

};



struct FxRate {
	FxPair pair;
	double rate;

	// Constructors
	FxRate(std::string ccy1, std::string ccy2, double r)
	{
		pair.ccy1 = ccy1;
		pair.ccy2 = ccy2;
		rate = r;
	}
	// Class Member Function
	void invert_ccy() {
		this->rate = 1 / this->rate;
		// swap(this.pair.ccy1, this.pair.ccy2);
	}

	FxRate creeate_new_instance_inverted()
	{
		FxRate fx = FxRate(pair.ccy2, pair.ccy1, 1. / rate);
		return fx;
	}

	double get_rate_time_100() {
		return rate * 100;
	}
};


void invert_ccy_nonmember(FxRate fx) {
	fx.rate = 1 / fx.rate;
	swap(fx.pair.ccy1, fx.pair.ccy2);
}


void main3() {

	// 1
	FxRate gbpusd("GBP","USD", 0.7);
	gbpusd.invert_ccy();


	// 1.5
	invert_ccy_nonmember(gbpusd);

	// 2
	FxRate gbpusd222 = gbpusd.creeate_new_instance_inverted();

	FxRate gbpusd222 = gbpusd.creeate_new_instance_inverted();

	double rate1000 = gbpusd.get_rate_time_100();

	// create 3 Objects of FxPair
	// formally, construct 3 instances of type FxPair

	FxPair nzd("NZD","USD");
	FxPair gbp("GBP","USD");
	FxPair chf("USD","CHF");

	// FxPair nzd = refDatabase.getCcy("NZDUSD"); // goes to the database, takes 5 second


	/*
	* Code for specific risk scenario
	*/

}


class FxDataFrame {


};

#if 0
void main2() {

	TradeListSource tlSource("C:\ola_trade_source_config.ini");
	tlSource.init();

	liveTrades = tlSource.getTradeToday();
	// list of something?
	// list          of FxTrade's
	// std::vector
	// std::vector that contain FxTrades
	std::vector<FxTrade> liveTrades = tlSource.getTradeToday();


	// [ [FxTrades(USDNZD,1.0.)] [FxTrades] [FxTrades] [FxTrades] [FxTrades] ]
	std::cout << "number of trades is " << liveTrades.size();


	MarketDataProvider reuters("REUTERS_DELAYED");
	MarketDataSnapshot snap = reuters.snapshot();

	FxRiskPricer risk_pricer;
	auto risk_raw = risk_pricer.price_risk(liveTrades, snap);
	risk_raw.save_as_pdf("risk.pdf");
}
#endif


void  main()
{


/*

	# DF
		df = get_eod_positions();  # df holds a new Positions object

		# our DF(in memory), is passed t function below
		normalise_positions_to_usd(df);

	# passing our DF to report
		report(df);

*/
}


/*

objects
-------

		   [...]  <-- our Positions object, address, size, 0x5760


names
-----
  df -------^
  pos ------^

*/




/*
# positions is a DF, rows are dates, cols are ccy
def normalise_positions_to_usd(positions_df : DataFrame) :
	// names : positions_df
	// df.append('USD')
	positions_df.append('USD');

*/

/*
*
objects
-------
			+-+. id: 5670
			| |.
			+-+.

names
-----
'names' to something
names to an object

df        ----->
positions_df -->

*/


// Standard normal probability density function
double norm_pdf(const double& x) {
	return (1.0 / (pow(2 * M_PI, 0.5))) * exp(-0.5 * x * x);
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
