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

/*	constructors	*/
Contact::Contact (std::string arg1, std::string arg2, std::string arg3, std::string arg4, std::string arg5)
{
	first_name = arg1;
	last_name = arg2;
	nick_name = arg3;
	phone_nb = arg4;
	darkest_secret = arg5;
}

/*	getters	*/
std::string	Contact::get_first_name() {return (first_name);}
std::string	Contact::get_last_name() {return (last_name);}
std::string	Contact::get_nick_name() {return (nick_name);}
std::string	Contact::get_phone_nb() {return (phone_nb);}
std::string	Contact::get_darkest_secret() {return (darkest_secret);}
