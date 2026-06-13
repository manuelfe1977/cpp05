#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	const std::string _target;
public:
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &scf);
	ShrubberyCreationForm	operator=(const ShrubberyCreationForm &scf);
	~ShrubberyCreationForm();

	virtual void	execute(const Bureaucrat &executor);
};





#endif
