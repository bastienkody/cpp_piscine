/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <bguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:33:34 by bguillau          #+#    #+#             */
/*   Updated: 2023/11/28 18:33:36 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

/*	getters	*/
std::string	Contact::get_first_name() const {return (this->_first_name);}
std::string	Contact::get_last_name() const {return (_last_name);}
std::string	Contact::get_nick_name() const {return (_nick_name);}
std::string	Contact::get_phone_nb() const {return (_phone_nb);}
std::string	Contact::get_darkest_secret() const {return (_darkest_secret);}

/*	setters	*/
void Contact::set_first_name()
{
	do 
	{
		std::cout << "First name: \t";
		std::getline(std::cin, this->_first_name);
	}
	while (this->_first_name.size() == 0 && std::cout << EMPTY_STR << std::endl);
}

void Contact::set_last_name()
{
	do 
	{
		std::cout << "Last name: \t";
		std::getline(std::cin, this->_last_name);
	}
	while (this->_last_name.size() == 0 && std::cout << EMPTY_STR << std::endl);
}

void Contact::set_nick_name()
{
	do 
	{
		std::cout << "Nick name: \t";
		std::getline(std::cin, this->_nick_name);
	}
	while (this->_nick_name.size() == 0 && std::cout << EMPTY_STR << std::endl);
}

void Contact::set_phone_nb()
{
	do 
	{
		std::cout << "Phone number: \t";
		std::getline(std::cin, this->_phone_nb);
	}
	while (this->_phone_nb.size() == 0 && std::cout << EMPTY_STR << std::endl);
}

void Contact::set_darkest_secret()
{
	do 
	{
		std::cout << "Darkest secret: \t";
		std::getline(std::cin, this->_darkest_secret);
	}
	while (this->_darkest_secret.size() == 0 && std::cout << EMPTY_STR << std::endl);
}

/*	display	*/
void	Contact::full_display() const
{
	std::cout << "First name:\t " << this->_first_name << std::endl;
	std::cout << "Last name:\t " << this->_last_name << std::endl;
	std::cout << "Nick name:\t " << this->_nick_name << std::endl;
	std::cout << "Phone number:\t " << this->_phone_nb << std::endl;
	std::cout << "Darkest secret:\t " << this->_darkest_secret << std::endl;
	std::cout << LINE_SEP << std::endl;
}
