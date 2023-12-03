/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <bguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:57:52 by bguillau          #+#    #+#             */
/*   Updated: 2023/11/28 18:57:55 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
#include <iomanip>
#include <cstdlib>

#define PHONEBOOK_INTRO "Welcome to the Phonebook!"
#define USER_CHOICES "Commands: EXIT (to quit), ADD (new contact), SEARCH (a \
contact)"
#define NO_CONTACT "No contact to display, use ADD to fill the Phonebook"
#define CHOOSE_CONTACT "Choose a contact to fully display (via its index, only \
1 digit accepted)"
#define EOF_FOUND "Unexpected EOF found, program exiting ..."

class PhoneBook
{
		Contact		_array[8];
		static int	_contacts_nb;
	public:
		int		add();
		int		search() const;
		void	search_display() const;
		void	run();
};

#endif
