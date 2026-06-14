#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>


class RobotomyRequestForm : public AForm
{
private:
	const std::string _target;
public:
	RobotomyRequestForm(const std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &rrf);
	RobotomyRequestForm	operator=(const RobotomyRequestForm &rrf);
	~RobotomyRequestForm();
	std::string getTarget();
	virtual void	execute(const Bureaucrat &executor);
};





#endif
