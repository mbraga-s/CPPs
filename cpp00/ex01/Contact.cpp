
#include "Contact.hpp"

Contact::Contact(void)
{
	this->nbr_contacts++;
}

Contact::~Contact(void)
{
	return;
}

int	Contact::nbr_contacts = -8;

void	Contact::add_new(void)
{
	std::string	nbr;

	std::cout << "Input the contact's first name:" << std::endl;
	std::getline(std::cin, this->_first_name);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Input the contact's last name:" << std::endl;
	std::getline(std::cin, this->_last_name);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Input the contact's nickname:" << std::endl;
	std::getline(std::cin, this->_nickname);
	if (std::cin.eof() == 1)
		return ;
	std::cout << "Input the contact's number:" << std::endl;
	std::getline(std::cin, nbr);
	if (std::cin.eof() == 1)
		return ;
	this->_number = check_nbr(nbr);
	std::cout << "Input the contact's darkest secret:" << std::endl;
	std::getline(std::cin, this->_secret);
	if (std::cin.eof() == 1)
		return ;
}

std::string	Contact::check_nbr(std::string nbr) const
{
	int	flag;

	flag = 0;
	for (int i = 0; i < nbr.length(); i++)
	{
		if (!isdigit(nbr[i]))
			flag = 1;
	}
	if (flag)
	{
		std::cout << "Only numeric characters are allowed." << std::endl;
		std::cout << "Please retry:" << std::endl;
		std::getline(std::cin, nbr);
		if (std::cin.eof() == 1)
			exit;
		nbr = check_nbr(nbr);
	}
	return(nbr);
}

std::string	Contact::get_fname(void) const
{
	return(this->_first_name);
}

std::string	Contact::get_lname(void) const
{
	return(this->_last_name);
}

std::string	Contact::get_nname(void) const
{
	return(this->_nickname);
}

std::string	Contact::get_nbr(void) const
{
	return(this->_number);
}

std::string	Contact::get_secret(void) const
{
	return(this->_secret);
}
