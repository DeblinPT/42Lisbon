/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:02:39 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/16 21:03:50 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <iostream>

template<class T>
class MutantStack : public std::stack<T> {
		typedef std::stack<T> _stack;
	public:
		typedef typename std::stack<T>::container_type::iterator	iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator	reverse_iterator;

		iterator begin() {
			return (_stack::c.begin());
		};
		iterator end() {
			return (_stack::c.end());
		};
		reverse_iterator rbegin() {
			return (_stack::c.rbegin());
		};
		reverse_iterator rend() {
			return (_stack::c.rend());
		};

		MutantStack() {
			std::cout << "Deafult constructor called" << std::endl;
		};

		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {
			std::cout << "Copy constructor called" << std::endl;
		};

		MutantStack &operator=(const MutantStack &other) {
			std::cout << "Assignment operator called" << std::endl;
			if (this != &other)
				_stack::c = other.c;
			return *this;
		};

		~MutantStack() {
			std::cout << "Destructor called" << std::endl;
		};
};