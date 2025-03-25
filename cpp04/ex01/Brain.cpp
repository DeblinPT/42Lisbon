/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:05:34 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/24 15:17:32 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <fstream>

Brain::Brain() {
	setIdeas("I have many default ideas!!!!!");
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(std::string type) {
	setIdeas(type);
	std::cout << "Brain constructor for " << type << " was called" << std::endl;
};

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
};

Brain::Brain(const Brain &copy) {
	*this = copy;
	std::cout << "Brain copy constructor called" << std::endl;
};

Brain &Brain::operator=(const Brain &copy) {
	if (this != &copy){
		for(int i = 0; i < 100; i++)
			this->_ideas[i] = copy._ideas[i];
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return (*this);
};
void Brain::getIdea() const {
	int range = 100;
	int num = rand() % range;
	std::cout << this->_ideas[num] << std::endl;
};

void Brain::getIdea(int nbr) const {
	if (nbr > 0 && nbr < 101)
		std::cout << this->_ideas[nbr - 1] << std::endl;
	else
		std::cout << "This animal doesn't have that many ideas!" << std::endl;
};

void Brain::setIdeas(std::string type) {
	int i = 0;
	if (type == "Cat") {
		std::ifstream fs("Cat Ideas.cpp");
		for (std::string line; getline(fs, line); ) {
			_ideas[i++] = line;
		}
		fs.close();
	}
	else if (type == "Dog"){
		std::ifstream fs("Dog Ideas.cpp");
		for (std::string line; getline(fs, line); ) {
			_ideas[i++] = line;
		}
		fs.close();
	}
	else {
		for (int i = 0; i < 100 ; i++)
			_ideas[i] = type;
	}
};
