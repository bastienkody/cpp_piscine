/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <bguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 19:07:07 by bguillau          #+#    #+#             */
/*   Updated: 2023/11/28 19:07:09 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::_contacts_nb = 0;

void	PhoneBook::run()
{
	std::string	user_input("");

	std::cout << PHONEBOOK_INTRO << std::endl;
	while (user_input.compare("EXIT"))
	{
		std::cout << USER_CHOICES << std::endl;
		getline(std::cin, user_input);
		if (std::cin.eof())
		{
			std::cout << EOF_FOUND << std::endl;
			break ;
		}
		else if (user_input.compare("ADD") == 0)
		{
			if (!add())
				break ;
		}
		else if (user_input.compare("SEARCH") == 0)
		{
			if (!search())
				break ;
		}
	}
}

int	PhoneBook::add()
{
	const int	index = this->_contacts_nb % 8;
	(this->_contacts_nb)++;

	std::cout << LINE_SEP << std::endl;
	std::cout << NEW_CONTACT_INTRO << std::endl;

	if (! this->_array[index].set_first_name() || \
		! this->_array[index].set_last_name() || \
		! this->_array[index].set_nick_name() || \
		! this->_array[index].set_phone_nb() || \
		! this->_array[index].set_darkest_secret() )
		return (0);

	std::cout << "Contact sucessfully saved !" << std::endl;
	std::cout << LINE_SEP << std::endl;
	return (1);
}

int	PhoneBook::search() const
{
	std::string	user_input("");
	int			intput;
	const int	max_index = _contacts_nb <= 8 ? _contacts_nb : 8;

	if (this->_contacts_nb == 0)
		return ((std::cout << NO_CONTACT << std::endl << LINE_SEP << std::endl), 1);
	search_display();
	do
	{
		std::cout << CHOOSE_CONTACT << std::endl;
		getline(std::cin, user_input);
		if (std::cin.eof())
			return (std::cout << EOF_FOUND << std::endl, 0);
		intput = atoi(user_input.c_str());
	}
	while (user_input.size() != 1 || !(intput > 0 && intput <= max_index));
	_array[intput - 1].full_display();
	return (1);
}

std::string	trunc_str(std::string str)
{
	return (str.size() <= 10 ? str : str.substr(0, 9) + ".");
}

void	PhoneBook::search_display() const
{
	const char	p = '|';
	const int	max_index = _contacts_nb <= 8 ? _contacts_nb : 8;

	for (int i = 0; i < max_index; i++)
	{
		std::cout << std::setw(10) << i + 1 << p;
		std::cout << std::setw(10) << trunc_str(this->_array[i].get_first_name()) << p;
		std::cout << std::setw(10) << trunc_str(this->_array[i].get_last_name()) << p;
		std::cout << std::setw(10) << trunc_str(this->_array[i].get_nick_name()) << std::endl;
		std::cout << LINE_SEP << std::endl;
	}
}
