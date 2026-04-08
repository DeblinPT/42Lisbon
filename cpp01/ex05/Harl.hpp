/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:06:09 by adimas-d          #+#    #+#             */
/*   Updated: 2025/02/03 20:12:45 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class harl {
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		void complain(std::string level);
};

#endif