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

/*	constructor	*/
PhoneBook::PhoneBook ()
{
	for (int i = 0; i < 8, i++)
		array[i] = NULL;
}
