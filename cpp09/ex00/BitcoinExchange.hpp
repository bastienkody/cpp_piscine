#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include<iostream>
#include<string>
#include<fstream>
#include<map>

#define DB_NAME "data.csv"


class BitcoinExchange
{
	public:

		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange & src);
		BitcoinExchange & operator=(const BitcoinExchange & rhs);

		void	readDb();
		void	readInput(const std::string filename);
		void	conversion() const;

	private:
		std::map<std::string, std::string>	_db;
		std::map<std::string, std::string>	_input;
};


#endif
