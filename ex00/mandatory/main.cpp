/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:29:46 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/22 10:50:09 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	std::string toConvert;
	
	if (argc != 2)
	{
		std::cerr << "Please enter 2 arguments only" << std::endl;
		return (EXIT_FAILURE);
	}
	toConvert = argv[1];
	try
	{
		ScalarConverter::convert(toConvert);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}