#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>


class Bureaucrat
{
private:
	const	std::string _name;
	unsigned int	_grade;
public:

	Bureaucrat(const std::string name, const unsigned int grade);
	Bureaucrat(const Bureaucrat& src);
	Bureaucrat	&operator=(const Bureaucrat &bureaucrat);
	std::string	getName() const;
	unsigned int	getGrade();
	void	incrementGrade();
	void	decrementGrade();
	~Bureaucrat();

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
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &src);

#endif
