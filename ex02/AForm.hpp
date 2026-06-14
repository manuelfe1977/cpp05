#ifndef AFORM_HPP
#define AFORM_HPP


#include <ostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_gradeRequiredToSign;
	const unsigned int	_gradeRequiredToExecute;

public:
	AForm(const std::string &name, const unsigned int &gradeRequiredToSign, const unsigned int &gradeRequiredToExecute);
	AForm(const Form &form);
	AForm			&operator=(const Form &form);
	~AForm();
	std::string		getName();
	bool			getIsSigned();
	unsigned int	getGradeRequiredToSign();
	unsigned int	getGradeRequiredToExecute();
	void			beSigned(Bureaucrat &bureaucrat);
	void			checkRequirements(const Bureaucrat &executor) const;
	virtual void	execute(const Bureaucrat &executor) const = 0;

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
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw()
		{
			return "El formulario no está firmado.";
		}
	};
};

std::ostream	&operator<<(std::ostream &os, Form &form);

#endif
