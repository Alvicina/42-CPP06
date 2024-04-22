/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:18:11 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/22 13:20:43 by alvicina         ###   ########.fr       */
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
	typeConvert(toConvert);
	
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
				std::cout << "float : " << std::numeric_limits<float>::quiet_NaN();
				std::cout << "f" << std::endl;
				std::cout << "double : " << std::numeric_limits<double>::quiet_NaN();
				std::cout << std::endl;
			}
			return (true);
		}
		i++;
	}
	return (false);
}

void	ScalarConverter::typeConvert(const std::string &toConvert)
{
	switch(typeDetect(toConvert))
	{
		case CHAR:
			//charConvert(toConvert);
			break ;
		case INT:
			//intConvert(toConvert);
			break ;
		case FLOAT:
			//floatConvert(toConvert);
			break ;
		case DOUBLE:
			//doubleConvert(toConvert);
			break ;
		case NOTYPE:
			throw invalidArgument();
			break ;
	}
}

ScalarConverter::e_type	ScalarConverter::typeDetect(const std::string &toConvert)
{
	size_t	i =  0;
	size_t	point = 0;
	
	if (toConvert.length() == 1 && isprint(toConvert[0]) && !isdigit(toConvert[0]))
		return (CHAR);
	while (toConvert[i])
	{
		if (toConvert[i] == '.')
			point++;
		else if (!isdigit(toConvert[i]) || point > 1)
			throw invalidArgument();
		else if (!isprint(toConvert[i]))
			throw nonDisplayableCharacters();
		else if (isdigit(toConvert[i]) && i == toConvert.length() - 1)
			return (INT);
		else if (toConvert[i] == 'f' && toConvert.length() - 1 && point <= 1)
			return (FLOAT);
		else if ((isdigit(toConvert[i]) && toConvert.length() - 1 && point == 1)
		|| (i == toConvert.length() - 1 && toConvert[i] == '.'))
			return (DOUBLE);
		i++;
	}
	return(NOTYPE);
}
