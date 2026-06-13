#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	const std::string _target;
public:
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &ppf);
	PresidentialPardonForm	operator=(const PresidentialPardonForm &ppf);
	~PresidentialPardonForm();

	virtual void	execute(const Bureaucrat &executor);
};





#endif
