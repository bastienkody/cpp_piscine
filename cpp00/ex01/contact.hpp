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

class Contact
{
		std::string first_name;
		std::string last_name;
		std::string nick_name;
		std::string phone_nb;
		std::string darkest_secret;
	public:
		Contact(std::string arg1, std::string arg2, std::string arg3, \
std::string arg4, std::string arg5);
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nick_name();
		std::string get_phone_nb();
		std::string get_darkest_secret();
};

#endif
