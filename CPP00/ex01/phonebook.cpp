#include "phonebook.hpp"

//std::ws allows us to ignore any leading white space in cin
PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::Intro() const
{
	std::string	name = "";

	while (!std::cin.good() || name.empty())
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
			//clear error state of stream
			std::cin.clear();
			//ignores 1. up to n number (max streamsize) or 2. until the delimiter (\n)
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else if (name.empty())
			std::cout << "The field is empty.\n";
	}
	std::cout << "Creating " << name << "'s PhoneBook...\n";
	std::cout << "...\n";
	std::cout << "Choose an option:\nADD\nSEARCH\nEXIT" << std::endl;
}

void	PhoneBook::AddContact()
{
	//static ints are automatically init to 0
	static unsigned int	i; 
	unsigned int		index = i % 8;

	this->m_contact[index].NewContact(index);
	// if (this->m_contact[index].m_valid == false)
	// 	std::exit(1);
	i++;
}

int	PhoneBook::PrintContacts() const
{	
	if (this->m_contact[0].m_index == -1)
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
		if (this->m_contact[i].m_index > -1)
			this->m_contact[i].ViewContact();
	return (1);
}

void	PhoneBook::SearchContacts() const
{
	int	index = -1;

	if (!PhoneBook::PrintContacts())
		return ;
	// while (index < 0 || index >= 8 || !std::cin.good() || this->m_contact[index].m_index < 0 )
	// {
		std::cout << "Please enter an index number to see contact details: " << std::flush;
		std::cin >> index;
		if (std::cin.eof())
		{
			std::cout << "\nClosing your PhoneBook...\n";
			std::exit(1);
		}
		else if (index < 0 || index >= 8 ||
				!std::cin.good() || this->m_contact[index].m_index < 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			// std::cout << "Input invalid. Please enter a valid option." << std::endl;
			std::cout << "Input invalid." << std::endl;
		}
		else
			this->m_contact[index].DisplayContact();

	// }
}






