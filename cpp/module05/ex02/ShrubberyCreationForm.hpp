/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyepark <gyepark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 02:33:45 by gyepark           #+#    #+#             */
/*   Updated: 2022/09/19 02:33:46 by gyepark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include "Form.hpp"
#include <fstream>
class ShrubberyCreationForm : public Form
{
private:
	std::string		target;
	
public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(ShrubberyCreationForm &other);
	ShrubberyCreationForm(const std::string target);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator=(ShrubberyCreationForm &other);

	void	execute(Bureaucrat const & executor) const;
};
#endif
