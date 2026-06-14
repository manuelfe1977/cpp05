#include "RobotomyRequestForm.hpp"

#include <string>


RobotomyRequestForm::RobotomyRequestForm():AForm("RobotomyRequestForm", 72,45), _target("default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):AForm("RobotomyRequestForm", 72,45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf)
	: AForm(rrf), (rrf._target){}

RobotomyRequestForm	RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf)
{
	if (this != &rrf)
	{
		AForm::operator=(rrf);
		_target = rrf._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget()
{
	return _target;
}

virtual void	execute(const Bureaucrat &executor)
{
	AForm::checkRequirements(executor);

	std::cout << "ZZZZZRRRRRZZZZ" << std::endl;
	if (rand() % 2 == 0)
		std::cout << getTarget() << " ha sido robotomizado satisfactoriamente!!" << std::endl;
	else
		std::cout << " robotomización fallida en " << getTarget() << std::endl;
}
