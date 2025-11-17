/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 17:06:22 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/16 17:24:23 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	srand(time(NULL));
	int	rdmCase = rand() % 3;
	Base	*ret = NULL;
	switch (rdmCase) {
		case 0: {
			ret = new A;
			break;
		}
		case 1: {
			ret = new B;
			break;
		}
		case 2: {
			ret = new C;
			break;
		}
	}
	return ret;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "'A' Type" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "'B' Type" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "'C' Type" << std::endl;
	else
		std::cout << "Unknown Type" << std::endl;
}

void identify(Base& p) {
	try {
		A &test1 = dynamic_cast<A&>(p);
		std::cout << "'A' Type" << std::endl;
		(void)test1;
		return;
	}
	catch (const std::bad_cast &e) {}
	try {
		B &test2 = dynamic_cast<B&>(p);
		std::cout << "'B' Type" << std::endl;
		(void)test2;
		return;
	}
	catch (const std::bad_cast &e) {}
	try {
		C &test3 = dynamic_cast<C&>(p);
		std::cout << "'C' Type" << std::endl;
		(void)test3;
		return;
	}
	catch (const std::bad_cast &e) {}
	std::cout << "Unknown Type" << std::endl;
}

int main() {
	Base *test = generate();
	Base &test2 = *test;
	
	std::cout << "Pointer of ";
	identify(test);
	std::cout << "Reference of ";
	identify(test2);
	std::cout << std::endl;
	delete test;
}