/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:41 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:41 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"
class PresidentialPardonForm : public Form
{
private:
	std::string		target;
public:

	PresidentialPardonForm(void);
	PresidentialPardonForm(PresidentialPardonForm &other);
	PresidentialPardonForm(const std::string target);
	~PresidentialPardonForm(void);
	PresidentialPardonForm	&operator=(PresidentialPardonForm &other);

	void	execute(Bureaucrat const & executor) const;
};
#endif
