#ifndef FORM_HPP
#define FORM_HPP


#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeRequiredToSign;
	const unsigned int	_gradeRequiredToExecute;

public:
	Form(const std::string &name, const unsigned int &gradeRequiredToSign, const unsigned int &gradeRequiredToExecute);
	Form(const Form &form);
	Form	&operator=(const Form &form);
	~Form();
	std::string		getName();
	bool			getIsSigned();
	unsigned int	getGradeRequiredToSign();
	unsigned int	getGradeRequiredToExecute();
	void			beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw()
		{
			return "El grado es demasiado alto (máximo es 1).";
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw()
		{
			return "El grado es demasiado bajo (mínimo es 150).";
		}
	};
	class FormAlreadySignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw()
		{
			return "Formulario ya firmado con anterioridad.";
		}
	};
};

std::ostream	&operator<<(std::ostream &os, Form &form);

#endif
