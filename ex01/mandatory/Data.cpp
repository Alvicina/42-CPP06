/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:23:03 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/23 12:30:42 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Data::Data()
{
	//std::cout << "Data default constructor called" << std::endl;
}

Data::~Data()
{
	//std::cout << "Data destructor called" << std::endl;
}

Data::Data(const Data &a)
{
	std::cout << "Data copy constructor called" << std::endl;
	*this = a;
}

Data&	Data::operator=(const Data &a)
{
	if (this != &a)
	{
		_age = a._age;
		_name = a._name;
	}
	return (*this);
}

void	Data::setAge(int age)
{
	_age = age;
}

void	Data::setName(const std::string &name)
{
	_name = name;
}

int		Data::getAge(void)
{
	return (_age);
}

std::string	Data::getName(void)
{
	return (_name);
}

