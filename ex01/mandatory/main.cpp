/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:40:12 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/23 12:22:13 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int	main(void)
{
	Data		ptr;
	uintptr_t	raw;
	Data		*ptrNew;

	std::cout << " ------- using &prt ------- " << std::endl;
	ptr.setAge(34);
	ptr.setName("Alejandro");
	std::cout << "Data age:" << ptr.getAge() << std::endl;
	std::cout << "Data name:"<< ptr.getName() << std::endl;
	std::cout << "ptr address:" << &ptr << std::endl;
	std::cout << std::endl;
	
	std::cout << " ------- check between &prt and raw ------- " << std::endl;
	raw = Serializer::serialize(&ptr);
	std::cout << "ptr address:" << &ptr << std::endl;
	std::cout << "raw address:" << raw << std::endl;
	std::cout << std::endl;

	std::cout << " ------- using newPtr ------- " << std::endl;
	ptrNew = Serializer::deserialize(raw);
	std::cout << "Data age:" << ptrNew->getAge() << std::endl;
	std::cout << "Data name:"<< ptrNew->getName() << std::endl;
	std::cout << "ptr address:" << &ptr << std::endl;
	std::cout << "ptrNew address:" << ptrNew << std::endl;
	return (EXIT_SUCCESS);
	
	
}