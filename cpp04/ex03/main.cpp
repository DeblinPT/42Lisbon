/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 20:26:56 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/24 15:49:43 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main() {
/*
	Character basic("eu");
	IMateriaSource* ice = new MateriaSource();
	ice->learnMateria(new Ice());
	basic.equip(ice->createMateria("ice"));
	{
		Character tmp = basic;
	}
	delete ice;
*/
	IMateriaSource* ice = new MateriaSource();
	std::cout << std::endl;
	IMateriaSource* cure = new MateriaSource();
	std::cout << std::endl;
	ice->learnMateria(new Ice());
	std::cout << std::endl;
	cure->learnMateria(new Cure());
	std::cout << std::endl;

	ICharacter* me = new Character("me");
	std::cout << std::endl;

	AMateria* tmp;

	AMateria* trash[4];
	for (int i = 0; i < 4; i++) {
		trash[i] = NULL;
	}
	
	tmp = cure->createMateria("ice");
	trash[0] = tmp;
	me->equip(tmp);
	std::cout << std::endl;

	tmp = cure->createMateria("cure");
	trash[1] = tmp;
	me->equip(tmp);
	std::cout << std::endl;

	tmp = ice->createMateria("ice");
	trash[2] = tmp;
	me->equip(tmp);
	std::cout << std::endl;

	tmp = ice->createMateria("ice");
	trash[3] = tmp;
	me->equip(tmp);
	std::cout << std::endl;

	tmp = ice->createMateria("ice");
	me->equip(tmp);
	std::cout << std::endl;

	ICharacter* bob = new Character("bob");
	std::cout << std::endl;
	me->use(0, *bob);
	me->use(0, *bob);
	me->use(2, *bob);
	me->unequip(1);
	
	delete bob;
	std::cout << std::endl;
	delete me;
	std::cout << std::endl;
	delete ice;
	std::cout << std::endl;
	delete cure;
	std::cout << std::endl;
	for (int i = 0; i < 4; i++) {
		if (trash[i])
			delete trash[i];
	}

	return 0;
}