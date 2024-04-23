/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:12 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/23 12:06:57 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main(void)
{
	Data		ptr;
	uintptr_t	raw;
	Data		*ptrNew;

	std::cout << " ------- using &prt ------- " << std::endl;
	ptr.age = 34;
	ptr.name = "Alejandro";
	std::cout << "Data age:" << ptr.age << std::endl;
	std::cout << "Data name:"<< ptr.name << std::endl;
	std::cout << "ptr address:" << &ptr << std::endl;
	std::cout << std::endl;
	
	std::cout << " ------- check between &prt and raw ------- " << std::endl;
	raw = Serializer::serialize(&ptr);
	std::cout << "ptr address:" << &ptr << std::endl;
	std::cout << "raw address:" << raw << std::endl;
	std::cout << std::endl;

	std::cout << " ------- using newPtr ------- " << std::endl;
	ptrNew = Serializer::deserialize(raw);
	std::cout << "Data age:" << ptrNew->age << std::endl;
	std::cout << "Data name:"<< ptrNew->name << std::endl;
	std::cout << "ptr address:" << &ptr << std::endl;
	std::cout << "ptrNew address:" << ptrNew << std::endl;
	return (EXIT_SUCCESS);
	
	
}