/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:17:48 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/20 16:48:46 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* a = new Dog();
	std::cout << std::endl;
	const Animal* b = new Cat();
	std::cout << std::endl;
	const WrongAnimal* c = new WrongAnimal();
	std::cout << std::endl;
	const WrongAnimal* d = new WrongCat();
	std::cout << std::endl;

	std::cout << a->getType() << " " << std::endl;
	std::cout << b->getType() << " " << std::endl;
	std::cout << d->getType() << " " << std::endl;
	std::cout << std::endl;

	a->makeSound(); //will output the cat sound!
	b->makeSound();
	meta->makeSound();
	c->makeSound();
	d->makeSound();
	std::cout << std::endl;

	delete meta;
	std::cout << std::endl;
	delete a;
	std::cout << std::endl;
	delete b;
	std::cout << std::endl;
	delete c;
	std::cout << std::endl;
	delete d;

return 0;
}