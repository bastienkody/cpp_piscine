/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <bguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:20:53 by bguillau          #+#    #+#             */
/*   Updated: 2023/11/28 18:20:56 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>

#define NEW_CONTACT_INTRO "New phonebook contact entry. Please fill in all the \
following fields (empty strings are not accepted)"
#define LINE_SEP "-------------------------------------------------------------\
----------------------------------------"
#define EMPTY_STR "empty string are not accepted!"

class Contact
{
	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nick_name;
		std::string _phone_nb;
		std::string _darkest_secret;
	public:
		std::string	get_first_name() const;
		std::string	get_last_name() const;
		std::string	get_nick_name() const;
		std::string	get_phone_nb() const;
		std::string	get_darkest_secret() const;
		void		set_first_name();
		void		set_last_name();
		void		set_nick_name();
		void		set_phone_nb();
		void		set_darkest_secret();
		void		full_display();
		void		sort_display();
};

#endif
