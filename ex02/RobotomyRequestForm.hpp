#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &rrf);
	RobotomyRequestForm	operator=(const RobotomyRequestForm &rrf);
	~RobotomyRequestForm();

	virtual void	execute(const Bureaucrat &executor);
};





#endif
