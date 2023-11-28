/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <bguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:04:46 by bguillau          #+#    #+#             */
/*   Updated: 2023/11/28 15:15:37 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

inline void	print_nl(void) {std::cout << std::endl;}

inline void	print_default(void) {std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";}

inline void	print_upper_str(const std::string& str)
{
	for (unsigned long i = 0; i <= str.size() -1 ; i++)
		std::cout << static_cast<char>(str[i]);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		print_default();
	else
		for (int i = 1; i < argc; i++)
			print_upper_str(argv[i]);
	print_nl();
	return (0);
}
