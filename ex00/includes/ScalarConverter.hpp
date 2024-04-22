/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:18:06 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/22 18:34:50 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>

class ScalarConverter
{
	enum	e_type
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NOTYPE,
	};
	
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &a);
		ScalarConverter& operator=(const ScalarConverter &a);
		~ScalarConverter();
	public:
		static	void	convert(const std::string &toConvert);
		static	bool	isPseudoLiterals(const std::string &toConvert);	
		static	void	typeConvert(const std::string &toConvert);
		static	e_type	typeDetect(const std::string &toConvert);
		static	void	charConvert(const std::string &toConvert);
		static	void	intConvert(const std::string &toConvert);
		static	void	floatConvert(const std::string &toConvert);
		static	void	doubleConvert(const std::string &toConvert);
		static 	int		getDecimals(const std::string &toConvert, size_t pos);
	
	class nonDisplayableCharacters : public std::exception
	{
		public:
			virtual const char* what() const throw();
			
	};
	class invalidArgument : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class errorConversion : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

#endif