#include <iostream>
#include <limits>

int	main(void)
{
	std::cout << "CHAR MIN:\t" << static_cast<int>(std::numeric_limits<char>::min()) << std::endl;
	std::cout << "CHAR MAX:\t" << static_cast<int>(std::numeric_limits<char>::max()) << std::endl;

	std::cout << "INT MIN:\t" << std::numeric_limits<int>::min() << std::endl;
	std::cout << "INT MAX:\t" << std::numeric_limits<int>::max() << std::endl;

	std::cout << "FLOAT MIN:\t" << std::fixed << -std::numeric_limits<float>::max() << std::endl;
	std::cout << "FLOAT MAX:\t" << std::fixed << std::numeric_limits<float>::max() << std::endl;
	std::cout << "FLOAT INF:\t" << std::numeric_limits<float>::has_infinity << std::endl;
	std::cout << "FLOAT NAN:\t" << std::numeric_limits<float>::has_quiet_NaN << std::endl;

	std::cout << "DOUBL MIN:\t" << std::fixed << -std::numeric_limits<double>::max() << std::endl;
	std::cout << "DOUBL MAX:\t" << std::fixed << std::numeric_limits<double>::max() << std::endl;
	std::cout << "DOUBL INF:\t" << std::numeric_limits<double>::has_infinity << std::endl;
	std::cout << "DOUBL NAN:\t" << std::numeric_limits<double>::has_quiet_NaN << std::endl;
}
