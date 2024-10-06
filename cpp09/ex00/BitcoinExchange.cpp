#include"BitcoinExchange.hpp"

/*	Constructors	*/
BitcoinExchange::BitcoinExchange() 
{
}
BitcoinExchange::~BitcoinExchange()
{
	_db.clear();
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange & src)
{
	*this = src;
}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & rhs)
{
	if(this != &rhs)
		_db = rhs._db;
	return (*this);
}


/*	data.csv reader into _db, no parse/format error check	*/
void	BitcoinExchange::readDb()
{
	std::fstream		dbFile;
	std::string			line, date, price;

	dbFile.open(DB_NAME, std::fstream::in);
	if (dbFile.fail())
		throw std::runtime_error("Could not read data.csv");
	
	getline(dbFile, line);	// first title line
	while (getline(dbFile, line))
	{
		date.assign(line.begin(), line.begin() + line.find(','));
		price.assign(line.begin() + line.find(',') + 1, line.end());
		_db.insert(std::pair<time_t, double>(checkDate(date), strtod(price.c_str(), NULL)));
	}
}

/*	*/
void	BitcoinExchange::processInput(const std::string filename)
{
	std::fstream	inputFile;
	std::string		line, date, value;

	inputFile.open(filename.c_str(), std::fstream::in);
	if (inputFile.fail())
		throw std::runtime_error("Cannot open input file");

	while (getline(inputFile, line))
	{
		if (line.size() == 0 || line.compare("date | value") == 0)
			continue;
		if (line.find('|') == std::string::npos)
			trimWs(line), conversion(std::pair<std::string, std::string>(line, ""));
		else
		{
			trimWs(date.assign(line.begin(), line.begin() + line.find('|')));
			trimWs(value.assign(line.begin() + line.find('|') + 1, line.end()));
			conversion(std::pair<std::string, std::string>(date, value));
		}
	}
}

/*	Conversions with format checks ; all possibly title lines skipped; -0 value case	*/
void	BitcoinExchange::conversion(std::pair<std::string, std::string> pair)
{
	double		value;
	std::time_t	date;

	std::cout << pair.first << "\t=>\t" << pair.second << "\t=\t";
	try {
		if ((date = checkDate(pair.first)) < getLowestDateFromDb())
			throw std::invalid_argument("Invalid date: before 2009-01-02");
		if ((value = checkValue(pair.second)) == -0)
			value = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl; return;
	}
	std::cout << std::fixed << std::setprecision(2) << value * getValueAtDateOrLower(date) << std::endl;
}

/*	format + validity + t < now	*/
time_t	BitcoinExchange::checkDate(std::string str) const
{
	std::stringstream	s(str);
	char				dash; 
	unsigned int		year, month, day;

	s >> year >> dash >> month >> dash >> day;
	if (s.fail() || !s.eof())
		throw std::invalid_argument("Invalid date: format");

	std::tm		tm;
	memset(&tm, 0, sizeof(tm));
	tm.tm_year	= year - 1900;
	tm.tm_mon	= month - 1;
	tm.tm_mday	= day;

	std::time_t	sec = mktime(&tm);
	if (sec == -1)
		throw std::runtime_error("Invalid date: mktime failed");

	char	buf[11];
	strftime(buf, sizeof(buf), "%Y-%m-%d", localtime(&sec));

	if (str.compare(buf) != 0)
		throw std::invalid_argument("Invalid date: format");
	if (sec > time(NULL))
		throw std::invalid_argument("Invalid date: in the future?");
	return sec;
}

/*	floatings for perfect reconstruction of the string (decimal value precison)	*/
double	BitcoinExchange::checkValue(std::string src) const
{
	std::stringstream	s(src), sBack;
	double				d, dd;
	size_t				floatings = src.find('.') == std::string::npos ? 0 : src.size() - src.find('.') - 1;

	s >> d;
	dd = d;
	if (floatings)
		sBack << std::fixed << std::setprecision(floatings) << dd;
	else
		sBack << dd;
	if (s.fail() || !s.eof() || sBack.str() != src)
		throw std::invalid_argument("Invalid number: format");
	if (d < 0 || d > 1000)
		throw std::invalid_argument("Invalid number: out of range");
	return d;
}

/* multimap::lower_bound is shitty it returns the perfect or the next above	*/
double	BitcoinExchange::getValueAtDateOrLower(std::time_t t) const
{
	std::map<std::time_t, double>::const_iterator it = _db.lower_bound(t);

	if (it->first != t)
		--it; // to get lower one if not perfect date match
	return it->second;
}

/*	ersatz for c++11 std::min_element (used by checkDate)	*/
std::time_t	BitcoinExchange::getLowestDateFromDb() const
{
	std::map<std::time_t, double>::const_iterator	it = _db.begin();
	std::time_t											smallest = it->first;

	while (it != _db.end())
	{
		if (it->first < smallest)
			smallest = it->first;
		++it;
	}
	return smallest;
}

/*	utils	*/
void	BitcoinExchange::printDb() const
{
	for (std::map<std::time_t, double>::const_iterator it = _db.begin(); it != _db.end(); ++it)
		std::cout << it->first << "-->" << it->second << std::endl;
}

/*	Whitespaces trimmer	(l and r)	*/
void	BitcoinExchange::trimWs(std::string &s)
{
	std::string::iterator	it = s.begin();
	while(it != s.end() && isspace(*it))
		++it;
	s.erase(s.begin(), it);

	std::string::reverse_iterator rit = s.rbegin();
	while(rit != s.rend() && isspace(*rit))
		++rit;
	if (rit.base() != s.end())
		s.erase(rit.base(), s.end());
}
