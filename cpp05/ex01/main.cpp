/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 17:16:27 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/27 17:59:40 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void) {
	Bureaucrat pessoa1;
	std::cout << std::endl;

	Bureaucrat pessoa2("Eu", 1);
	std::cout << std::endl;

	Bureaucrat pessoa3("Tu");
	std::cout << std::endl;

	Bureaucrat pessoa4(pessoa1);
	std::cout << std::endl;

	Form form1;
	std::cout << std::endl;

	Form form2("Papelada");
	std::cout << std::endl;

	Form form3("Mais papelada", 5, 5);
	std::cout << std::endl;

	Form form4 = form1;
	std::cout << std::endl;	

	std::cout << "--------------------------------------------------------------------------" << std::endl << std::endl;

	std::cout << pessoa1 << std::endl;
	std::cout << pessoa2 << std::endl;
	std::cout << pessoa3 << std::endl;
	std::cout << pessoa4 << std::endl;
	std::cout << std::endl;
	std::cout << form1 << std::endl;
	std::cout << form2 << std::endl;
	std::cout << form3 << std::endl;
	std::cout << form4 << std::endl;
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl << std::endl;

	pessoa1.signForm(form1);
	pessoa2.signForm(form2);
	pessoa3.signForm(form3);
	pessoa2.signForm(form3);
	pessoa4.signForm(form4);
	pessoa2.signForm(form4);
	std::cout << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl << std::endl;

	return 0;
}