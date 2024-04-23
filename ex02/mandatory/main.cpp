/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvicina <alvicina@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:39:23 by alvicina          #+#    #+#             */
/*   Updated: 2024/04/23 18:07:27 by alvicina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*std::srand(time(nullptr));*/ //TODO: para que coja como base/semilla para 
//generar numeros aleaotorios la hora actual. 
//Si no ponemos eso, podria coger siempre la misma semilla por lo que p
//odria salir la misma secuencia todo el rato.

/*randomNumber = rand() % (2 - 0 + 1) + 1;*/ 
//para definir rango de numeros pseudoaleatorios -> (maximo - minimo + 1) + minimo

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast <A &>(p);
		std::cout << "A" << std::endl;
		(void) a;
		return ;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << std::endl;
	}
	try
	{
		B &b = dynamic_cast <B &>(p);
		std::cout << "B" << std::endl;
		(void) b;
		return ;
	}
	catch(const std::exception& e)
	{
		//std::cerr << e.what() << std::endl;
	}
	try
	{
		C &c = dynamic_cast <C &>(p);
		std::cout << "C" << std::endl;
		(void) c;
		return ;
	}
	catch (const std::exception& e)
	{
		//std::cerr << e.what() << std::endl;
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unkown" << std::endl;
}

Base*	generate(void)
{
	int	randomNumber;
	
	randomNumber = rand() % ((1 - 0 + 1) + 1);
	switch (randomNumber)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);	
	}
	return (NULL);
}

int		main(void)
{
	Base	*p;
	
	std::srand(time(NULL)); 
	p = generate();
	std::cout << "*p = "; 
	identify(p); 
	std::cout << std::endl;
	std::cout << "&p = "; 
	identify(*p); 
	std::cout << std::endl;
	delete p;
	//system ("leaks RealType");
	return (EXIT_SUCCESS);
}