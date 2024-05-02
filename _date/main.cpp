#include <iostream>
#include <sstream>
#include <ctime>
#include <string>
#include <cstring>


/*	For cpp09btc date checks (+ comp to now and first date)
	Takes a YYYY-MM-DD format date
	use sstream to parse into a tm (year/month/day)
	conv tm to time_t (ie. epoch sec)
	conv back time_t to tm to str again
	comp both str to detect error
	return time_t(str)
*/
std::time_t	getTimeSecured(std::string str)
{
	std::stringstream	s(str);
	char				dash; 
	unsigned int		year, month, day;

	s >> year >> dash >> month >> dash >> day;
	if (s.fail() || !s.eof())
		throw std::invalid_argument("Invalid date format");

	std::tm		tm;
	memset(&tm, 0, sizeof(tm));
	tm.tm_year = year - 1900;
	tm.tm_mon = month - 1;
	tm.tm_mday = day;

	std::time_t	sec = mktime(&tm);
	if (sec == -1)
		throw std::runtime_error("Failed to convert date to seconds since epoch");

	char	buf[11];
	std::tm	*tm2 = localtime(&sec);
	strftime(buf, sizeof(buf), "%Y-%m-%d", tm2);
	std::string str2(buf);

	std::cout << "src:\t" <<str <<std::endl << "conv:\t" << str2 << std::endl;

	if (str.compare(str2) != 0)
		throw std::invalid_argument("Invalid date format");
	
	return sec;
}

int	main(__attribute__((unused))int ac, char **av)
{
	if (ac != 2)
		std::cout << "YYYY-MM-DD format date please" << std::endl;

	try
	{
		std::time_t	sec = getTimeSecured(av[1]);
		std::cout << sec << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}
