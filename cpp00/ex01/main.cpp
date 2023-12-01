/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguillau <bguillau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:41:20 by bguillau          #+#    #+#             */
/*   Updated: 2023/11/28 18:41:23 by bguillau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	//Contact contactos[3];

	//for (int i = 0; i < 3; i++)
	//	contactos[i].full_display();

	PhoneBook ph_book;

	ph_book.run();
}
