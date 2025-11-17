/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:35 by adimas-d          #+#    #+#             */
/*   Updated: 2025/03/27 17:49:35 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
		std::string const _name;
		bool	_signed;
		int const _sign_grade;
		int const _exec_grade;
	public:
		Form();
		Form(std::string name);
		Form(std::string name, int sign_grade, int exec_grade);
		Form(Form const &copy);
		~Form();
		Form &operator=(Form const &other);
		std::string getName();
		int getSignGrade();
		int getExecGrade();
		bool isSigned();
		void beSigned(Bureaucrat &worker);
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form &form);