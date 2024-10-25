
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
		this->_target = src._target;
	return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const
{
	return(this->_target);
}

void ShrubberyCreationForm::action(void) const
{
	std::string filename;
	filename = this->_target + "_shrubbery.txt";

	std::ofstream file((this->_target + "_shrubbery.txt").c_str());

	file << "     ccee88oo" << std::endl;
	file << "  C8O8O8Q8PoOb o8oo" << std::endl;
	file << " dOB69QO8PdUOpugoO9bD" << std::endl;
	file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
	file << "    6OuU  /p u gcoUodpP" << std::endl;
	file << "      |||//  /douUP" << std::endl;
	file << "        ||/////" << std::endl;
	file << "         ||||/ " << std::endl;
	file << "         |||||" << std::endl;
	file << "         |||||" << std::endl;
	file << "   .....//|||||..." << std::endl;
	file << " tree by: David Moore" << std::endl;
	file.close();
}
