#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name)
{

	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		_grade = bureaucrat._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
}

std::string	Bureaucrat::getName() const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade()
{
	return _grade;
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade();
	return os;
}

Bureaucrat::~Bureaucrat()
{
}
