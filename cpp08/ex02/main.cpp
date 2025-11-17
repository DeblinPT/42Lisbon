/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 13:28:34 by adimas-d          #+#    #+#             */
/*   Updated: 2025/05/16 21:30:33 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
	
		std::cout << "Size: " << mstack.size() << std::endl;
		std::cout << "Top: " << mstack.top() << std::endl;
	
		mstack.pop();
	
		std::cout << "Size: " << mstack.size() << std::endl;
	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
	
		MutantStack<int> lala(mstack);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		int i = 0;
		while (it != ite)
		{
			std::cout << "mstack[" << i << "]: " << *it << std::endl;
			++it;
			i++;
		}
		it = lala.begin();
		ite = lala.end();
		i = 0;
		while (it != ite)
		{
			std::cout << "Copy[" << i << "]: " << *it << std::endl;
			++it;
			i++;
		}
	}
	{
		std::list<int> compare;

		compare.push_back(5);
		compare.push_back(17);

		std::cout << "Size: " << compare.size() << std::endl;
		std::cout << "Top: " << compare.back() << std::endl;
	
		compare.pop_back();
	
		std::cout << "Size: " << compare.size() << std::endl;
	
		compare.push_back(3);
		compare.push_back(5);
		compare.push_back(737);
		compare.push_back(0);
	
		std::list<int>::iterator it = compare.begin();
		std::list<int>::iterator ite = compare.end();
		int i = 0;
		while (it != ite)
		{
			std::cout << "mstack[" << i << "]: " << *it << std::endl;
			i++;
			it++;
		}

	}
	return 0;
}