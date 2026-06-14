#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &scf);
	ShrubberyCreationForm	operator=(const ShrubberyCreationForm &scf);
	~ShrubberyCreationForm();

	virtual void	execute(const Bureaucrat &executor);

	class OpenFileException : public std::exception
	{
	public:
		virtual const char*	what() const throw()
		{
			return "Error al abrir el archivo.";
		}
	};

};





#endif
