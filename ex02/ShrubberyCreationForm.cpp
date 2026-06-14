#include "ShrubberyCreationForm.hpp"

#include <string>


ShrubberyCreationForm::ShrubberyCreationForm():AForm("ShrubberyCreationForm", 145,137), _target("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):AForm("ShrubberyCreationForm", 145,137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf)
	: AForm(src), (scf._target){}

ShrubberyCreationForm	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf)
{
	if (this != &scf)
	{
		AForm::operator=(scf);
		_target = scf._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

virtual void	ShrubberyCreationForm::execute(const Bureaucrat &executor)
{
	AForm::checkRequirements(executor);

	std::ofstream outFile((_target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "     @  \n";
		outFile << "    @ @  \n";
		outFile << "   @@ @@  \n";
		outFile << "  @@@ @@@ \n";
		outFile << " @@@@ @@@@ \n";
		outFile << "    | |     \n";
		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileException();
}
