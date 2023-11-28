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

# include "contact.hpp"

class PhoneBook
{
		Contact	array[8];
		static int	saved_contact; // shared by all object
	public:
		PhoneBook();
		void search();
		void add();
		Contact *get_contacts();
		void print_contacts_to_file(std::string file_path);
};

#endif
