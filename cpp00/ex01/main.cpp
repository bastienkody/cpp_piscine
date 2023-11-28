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

int	main(void)
{
	Contact Bastos ("bastien", "guillaume", "kody", "+33", "love bash");

	std::cout << Bastos.get_first_name() << " has a secret : " ;
	std::cout << Bastos.get_darkest_secret () << std::endl ;
}
