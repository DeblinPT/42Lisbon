/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adimas-d <adimas-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:28:35 by adimas-d          #+#    #+#             */
/*   Updated: 2025/04/07 17:00:34 by adimas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
		std::string const _name;
		bool	_signed;
		int const _sign_grade;
		int const _exec_grade;
	protected:
		AForm();
		AForm(std::string name);
		AForm(std::string name, int sign_grade, int exec_grade);
		AForm(AForm const &copy);
	public:
		virtual ~AForm() = 0;
		AForm &operator=(AForm const &other);
		std::string getName();
		int getSignGrade();
		int getExecGrade();
		bool isSigned();
		void beSigned(Bureaucrat &worker);
		void execute(Bureaucrat const & executor) const;
		virtual void executeForm() const = 0;
	
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

	class FormNotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class AlreadySigned : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, AForm &form);