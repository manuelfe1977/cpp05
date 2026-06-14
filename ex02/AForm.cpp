#include "AForm.hpp"


AForm::AForm(const std::string &name,
			const unsigned int &gradeRequiredToSign,
			const unsigned int &gradeRequiredToExecute)
			 : _name(name),
			 _isSigned(false),
			 _gradeRequiredToSign(gradeRequiredToSign),
			 _gradeRequiredToExecute(gradeRequiredToExecute)
{
	if (gradeRequiredToSign < 1)
		throw Form::GradeTooHighException();
	if (gradeRequiredToSign > 150)
		throw Form::GradeTooLowException();
	if (gradeRequiredToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeRequiredToExecute > 150)
		throw Form::GradeTooLowException();
}

AForm::AForm(const Form &form) :
			_name(form._name),
			_isSigned(form._isSigned),
			_gradeRequiredToSign(form._gradeRequiredToSign),
			_gradeRequiredToExecute(form._gradeRequiredToExecute)
			{}

AForm	&AForm::operator=(const Form &form)
{
	if (this != &form)
		_isSigned = form._isSigned;
	return *this;
}

AForm::~AForm(){}

std::string	AForm::getName()
{
	return _name;
}

bool	AForm::getIsSigned()
{
	return _isSigned;
}

unsigned int	AForm::getGradeRequiredToSign()
{
	return _gradeRequiredToSign;
}

unsigned int	AForm::getGradeRequiredToExecute()
{
	return _gradeRequiredToExecute;
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeRequiredToSign && !_isSigned)
		_isSigned = true;
	else if (_isSigned)
		throw Form::FormAlreadySignedException();
	else
		throw Form::GradeTooLowException();
}

void	checkRequirements(const Bureaucrat &executor) const
{
	if (!_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > _gradeRequiredToExecute)
		throw AForm::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, Form &form)
{
	os << "Form name " << form.getName();
	if (form.getIsSigned())
		os << " signed ";
	else
		os << " not signed ";
	os << "grade to sign " << form.getGradeRequiredToSign();
	os << " grade to execute " << form.getGradeRequiredToExecute();
	return os;
}
