/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:01:53 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/23 12:27:35 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	private:
		int			_age;
		std::string	_name;

	public:
		Data();
		~Data();
		Data(const Data &a);
		Data& operator=(const Data &a);
		void		setAge(int age);
		void		setName(const std::string &name);
		int			getAge(void);
		std::string	getName(void);	
};

/*
typedef struct s_data
{
	int			age;
	std::string	name;	
} Data;
*/
#endif