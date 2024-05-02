#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<string>
#include <sstream>
#include<fstream>
#include<map>

#define DB_NAME "data.csv"


/*
	using std::multimap
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
		void	readInput(const std::string filename);

		void	printDb() const;
		void	printInput() const;
		void	trimWhitespaces(std::string &s);

		void	conversion();

	private:
		std::multimap<std::time_t, double>	_db;
		std::multimap<std::string, std::string>	_input;

		time_t	checkDate(std::string src) const;
		double	checkValue(std::string src) const;

		std::time_t	getLowestDateFromDb() const;
		double		getValueAtDateOrLower(std::time_t t) const;
	
};

#endif