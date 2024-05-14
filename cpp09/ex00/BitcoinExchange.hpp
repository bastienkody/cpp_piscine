#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include<fstream>
#include<map>

#define DB_NAME "data.csv"

/*
	using std::multimap for the _db only (input is processed as read)
		it is key/value with ok doublons key
		it is sorted in kinda alphanum by keys
		[] operator ko
		insert with mmap.insert(std::pair<>())
		acces with mmap.find() or .bound(k)
	why this container?
	i must store pair value (date linked to value) => map
	could be several values for a single date 	=> multimap
	search perfect date in db or its lower one 	=> maps are sorted

	Overall use of sstream to detect format error in date or value _input
	date: 
		- Y-M-D to time_t then back to Y-M-D (bad leap year detected)
		- check date to be < now and > first _db date
	value:
		- str to double and then back to str
		- floatings precision counts implemented
*/

class BitcoinExchange
{
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

		void	readDb();
		void	printDb() const;
		void	trimWs(std::string &s);
		void	conversion(std::pair<std::string, std::string> pair);
		void	processInput(const std::string filename);

	private:
		std::multimap<std::time_t, double>	_db;

		std::time_t	checkDate(std::string src) const;
		double		checkValue(std::string src) const;

		std::time_t	getLowestDateFromDb() const;
		double		getValueAtDateOrLower(std::time_t t) const;
	
};

#endif
