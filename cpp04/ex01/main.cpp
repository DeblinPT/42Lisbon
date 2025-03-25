/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:48 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/24 15:20:12 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	Dog basic;
	{
		Dog tmp = basic;
	}
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;

	std::cout << "----------------------------------------------------------" << std::endl;

	Animal *a[6] = {};
	std::cout << std::endl;

	for (int i = 0; i < 6; i ++) {
		if (i < 3) {
			a[i] = new Dog;
			std::cout << std::endl;
		}
		if (i >= 3) {
			a[i] = new Cat;
			std::cout << std::endl;
		}
	}
	for (int i = 0; i < 6; i++)
		a[i]->makeSound();

	std::cout << std::endl;
	for (int i = 0; i < 6; i++) {
		delete a[i];
		std::cout << std::endl;
	}
	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << std::endl;
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
	brain->setIdeas("Ah e tal e cenas!!!");
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