#include "Form.hpp"


Form::Form(const std::string &name,
			const unsigned int &gradeRequiredToSign,
			const unsigned int &gradeRequiredToExecute)
			 : _name(name),
			 _gradeRequiredToExecute(gradeRequiredToExecute),
			 _gradeRequiredToSign(gradeRequiredToSign),
			 _isSigned(false)
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

Form::Form(const Form &form) :
			_name(form._name),
			_gradeRequiredToExecute(form._gradeRequiredToExecute),
			_gradeRequiredToSign(form._gradeRequiredToSign),
			_isSigned(form._isSigned){}

Form	&Form::operator=(const Form &form)
{
	if (this != &form)
		_isSigned = form._isSigned;
	return *this;
}

Form::~Form(){}

std::string	Form::getName()
{
	return _name;
}

bool	Form::getIsSigned()
{
	return _isSigned;
}

unsigned int	Form::getGradeRequiredToSign()
{
	return _gradeRequiredToSign;
}

unsigned int	Form::getGradeRequiredToExecute()
{
	return _gradeRequiredToExecute;
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeRequiredToSign && !_isSigned)
		_isSigned = true;
	else if (_isSigned)
		throw Form::FormAlreadySignedException();
	else
		throw Form::GradeTooLowException();
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
