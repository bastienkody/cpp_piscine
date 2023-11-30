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

#include "phonebook.hpp"

/*	static init	*/
int	PhoneBook::_contacts_nb = 0;

void	PhoneBook::add()
{
	int	index;

	// if more than 8 contact, replace oldest (not always first!)
	index = (this->_contacts_nb % 7);
	std::cout << "Index of current:" << index << std::endl;

	// one more contact
	(this->_contacts_nb)++;
	std::cout << "Contact nb (incl cur) :" << this->_contacts_nb << std::endl;

	std::cout << LINE_SEP << std::endl;
	std::cout << NEW_CONTACT_INTRO << std::endl;
	std::cout << LINE_SEP << std::endl;

	this->_array[index].set_first_name();
	std::cout << LINE_SEP << std::endl;
	this->_array[index].set_last_name();
	std::cout << LINE_SEP << std::endl;
	this->_array[index].set_nick_name();
	std::cout << LINE_SEP << std::endl;
	this->_array[index].set_phone_nb();
	std::cout << LINE_SEP << std::endl;
	this->_array[index].set_darkest_secret();
	std::cout << LINE_SEP << std::endl;

	// no need to add the object in the array ?

	std::cout << "Contact sucessfully saved !" << std::endl;
	std::cout << LINE_SEP << std::endl;
}

void	PhoneBook::run()
{
	std::string	user_input("");

	while (user_input.compare("EXIT"))
	{
		// display user choices
		getline(std::cin, user_input);
		if (user_input.compare("ADD"))
			add();
		else if (user_input.compare("SEARCH"))
			search();
	}
}

void	PhoneBook::search() const
{
	// write a short_display() in class Contact
	// display it for all contacts that have a name with size() > 0
	// ask for the index
	// check index (only digit, > 0 and < nb_contact - 1)
	// if index ko : rpint bad index + re prompt user input
	// index ok : display_full contact[index] and return
}