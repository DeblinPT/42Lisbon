/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:48 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/19 16:46:51 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal *a = new Animal;
	//a->makeSound();
	srand(time(NULL));	
	Dog *b = new Dog();
	std::cout << std::endl;
	Cat *c = new Cat();
	std::cout << std::endl;
	Brain *brain = new Brain();
	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		b->getIdea(42);
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		c->getIdea(42);
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		brain->getIdea(42);
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		b->getIdea();
	}
	std::cout << std::endl;
	for (int i = 0; i < 5; i++) {
		c->getIdea();
	}
	std::cout << std::endl;
		for (int i = 0; i < 5; i++) {
		brain->getIdea();
	}
	std::cout << std::endl;

	b->getIdea(101);
	c->getIdea(-101);
	brain->getIdea(0);
	std::cout << std::endl;

	delete b;
	std::cout << std::endl;
	delete c;
	std::cout << std::endl;
	delete brain;
	std::cout << std::endl;

	return 0;
}
