/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:44 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/15 17:35:08 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	PhoneBook::_PrintName(std::string name) const
{
	std::cout << "Initiating PhoneBook...\n";
	int	len = name.length() + 12;
	for (int i = 0; i < len; i++)
		std::cout << "-";
	std::cout << "\n";
	std::cout << name << "'s PhoneBook\n";
	for (int i = 0; i < len; i++)
		std::cout << "-";
	std::cout << "\n";
	std::cout << "Choose an option:\nADD\nSEARCH\nEXIT" << std::endl;
}

int	PhoneBook::_PrintContacts() const
{	
	if (_contact[0].p_index == -1)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return (0);
	}
	std::cout << "|" << std::setw(10) << "INDEX";
	std::cout << "|" << std::setw(10) << "FIRST NAME";
	std::cout << "|" << std::setw(10) << "LAST NAME";
	std::cout << "|" << std::setw(10) << "NICKNAME";
	std::cout << "|\n";
	for (int i = 0; i < 8; i++)
		if (_contact[i].p_index > -1)
			_contact[i].ViewContact();
	return (1);
}

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}


void	PhoneBook::Intro() const
{
	std::string	name = "";

	while (!std::cin.good() || name.empty() || OnlyWhiteSpace(name))
	{
		std::cout << "Please enter your first name: " << std::flush;
		std::getline(std::cin, name);
		if (std::cin.eof())
		{
			std::cout << "\nClosing your PhoneBook...\n";
			std::exit(1);
		}
		else if (!std::cin.good())
		{
			std::cout << "An error has occurred. Press enter to continue..." << std::flush;
			std::cin.clear(); //clear error state of stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignores 1. up to n number (max streamsize) or 2. until the delimiter (\n). basically restart cin
		}
		else if (name.empty() || OnlyWhiteSpace(name))
			std::cout << "The field is empty.\n";
	}
	PhoneBook::_PrintName(name);
}

void	PhoneBook::AddContact()
{
	static unsigned int	i; //static int are automatically init to 0
	unsigned int		index = i % 8;

	_contact[index].NewContact(index);
	i++;
}


void	PhoneBook::SearchContacts() const
{
	int	index = -1;

	if (!PhoneBook::_PrintContacts())
		return ;
	while (index < 0 || index >= 8 || _contact[index].p_index < 0)
	{
		std::cout << "Please enter an index number to see contact details: " << std::flush;
		std::cin >> index;
		if (std::cin.eof())
		{
			std::cout << "\nClosing your PhoneBook...\n";
			std::exit(1);
		}
		else if (!std::cin.good())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Input invalid." << std::endl;
		}
		else if (index < 0 || index >= 8 || _contact[index].p_index < 0)
			std::cout << "Index invalid" << std::endl;
	}
	_contact[index].DisplayContact();
}

/* NOTES:
std::ws allows us to ignore any leading white space in cin
*/






