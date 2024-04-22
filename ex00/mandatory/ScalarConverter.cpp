/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:18:11 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/22 11:47:44 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &a)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = a;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &a)
{
	(void) a;
	return (*this);
}

const char* ScalarConverter::nonDisplayableCharacters::what() const throw()
{
	return ("Not displayable");
}

const char* ScalarConverter::invalidArgument::what() const throw()
{
	return ("Invalid Argument");
}

void	ScalarConverter::convert(const std::string &toConvert)
{
	if (isPseudoLiterals(toConvert) == true)
		return ;
	return;
}

bool	ScalarConverter::isPseudoLiterals(const std::string &toConvert)
{
	std::string	list[] = {"inf", "+inf", "-inf", "inff",
	"+inff", "-inff", "nan", "nanf"};
	
	std::string	sign = "";
	size_t		i = 0;

	while (i < 8)
	{
		if (toConvert == list[i])
		{
			std::cout << "char : impossible" << std::endl;
			std::cout << "int  : impossible" << std::endl;
			if (i < 6)
			{
				if (list[i][0] == '-')
					sign = "-";
				std::cout << "float : " + sign << std::numeric_limits<float>::infinity();
				std::cout << "f" << std::endl;
				std::cout << "double : " + sign << std::numeric_limits<double>::infinity();
				std::cout << std::endl;
			}
			else
			{
				std::cout << 
			}
		}
		i++;
	}
}
