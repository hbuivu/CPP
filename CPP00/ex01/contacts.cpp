/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:19 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/13 12:08:19 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contacts.hpp"

//returns true if only white spaces, false if there 
bool	OnlyWhiteSpace(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (false);
	}
	return (true);
}

Contact::Contact()
	:	p_index(-1)
{
}

Contact::~Contact()
{
}

std::string	Contact::GetInput(std::string str)
{
	std::string	input = "";

	while (!std::cin.good() || input.empty() || OnlyWhiteSpace(input))
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nClosing your PhoneBook...\n";
			std::exit(1);
		}
		else if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input invalid. Please enter a valid option." << std::endl;
		}
		else if (input.empty() || OnlyWhiteSpace(input))
			std::cout << "The field is empty. All fields must be filled." << std::endl;
	}
	return (input);
}

void	Contact::NewContact(int i)
{
	std::cout << "All fields must be filled." << std::endl;
	_firstName = this->GetInput("First name: ");
	_lastName = this->GetInput("Last name: ");
	_nickname = this->GetInput("Nickname: ");
	_phoneNumber = this->GetInput("Phone number: ");
	_secret = this->GetInput("Secret: ");
	p_index = i;
	std::cout << "Contact successfully added!" << std::endl;
}

void	Contact::printContact(std::string m_str) const
{
	if (m_str.length() > 10)
		std::cout << "|" << std::setw(10) << m_str.substr(0,9) + ".";
	else
		std::cout << "|" << std::setw(10) << m_str; 
}

void	Contact::ViewContact() const
{
	std::cout << "|" << std::setw(10) << p_index; 
	printContact(_firstName);
	printContact(_lastName);
	printContact(_nickname);
	std::cout << "|\n";
	
}

void	Contact::DisplayContact() const
{
	std::cout << "First name:   " << _firstName << "\n";
	std::cout << "Last name:    " << _lastName << "\n";
	std::cout << "Nickname:     " << _nickname << "\n";
	std::cout << "Phone number: " << _phoneNumber << "\n";
	std::cout << "Secret:       " << _secret << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/* NOTES:
setw -> sets the width parameter of the stream out or in to exactly n.
string substr (size_t pos = 0, size_t len = npos) const;
*/

