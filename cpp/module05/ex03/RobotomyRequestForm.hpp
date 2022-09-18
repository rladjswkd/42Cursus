/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:59 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:34:00 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"
class RobotomyRequestForm : public Form
{
private:
	std::string		target;
	
public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(RobotomyRequestForm &other);
	RobotomyRequestForm(std::string target);
	~RobotomyRequestForm(void);
	RobotomyRequestForm	&operator=(RobotomyRequestForm &other);

	void	execute(Bureaucrat const & executor) const;
};

#endif
