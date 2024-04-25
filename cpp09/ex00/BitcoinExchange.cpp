#include"BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() 
{

}

BitcoinExchange::~BitcoinExchange()
{
	_db.clear();
	_input.clear();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
	if(this != &rhs)
	{
		_db = rhs._db;
		_input = rhs._input;
	}
	return (*this);
}

void	BitcoinExchange::readDb()
{
	std::fstream dbFile;

	dbFile.open(DB_NAME, std::fstream::in);
	if (dbFile.fail())
		return ; // fail should throw a std::exception::failure let see
	
}
void	BitcoinExchange::readInput(const std::string filename);
void	BitcoinExchange::conversion() const;

