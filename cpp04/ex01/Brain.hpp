/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:05:53 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/21 18:49:51 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include <cstdlib>

class Brain {
		std::string _ideas[100];
	public:
		Brain();
		Brain(std::string type);
		~Brain();
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		void getIdea() const;
		void getIdea(int nbr) const;
		void setIdeas(std::string type);
};