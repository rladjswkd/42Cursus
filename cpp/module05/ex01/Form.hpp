/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:28 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:29 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form
{
private:
	const std::string	name;
	bool				isSigned;
	const int			gradeSign;
	const int			gradeExec;
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
public:

	Form(void);
	Form(Form &);
	Form(std::string name, int gradeSign, int gradeExec);
	~Form(void);
	Form	&operator=(Form &);

	std::string	getName(void) const;
	bool		getIsSigned(void) const;
	int			getGradeSign(void) const;
	int			getGradeExec(void) const;

	void		beSigned(const Bureaucrat &bureaucrat);
};
#endif
