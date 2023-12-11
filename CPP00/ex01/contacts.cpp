#include "contacts.hpp"

Contact::Contact()
{
	m_index = -1;
}

Contact::~Contact()
{
}

std::string	Contact::GetInput(std::string str)
{
	std::string	input = "";

	while (!std::cin.good() || input.empty())
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
		else if (input.empty())
			std::cout << "The field is empty. All fields must be filled." << std::endl;
	}
	return (input);
}

void	Contact::NewContact(int i)
{
	std::cin.ignore();
	std::cout << "All fields must be filled." << std::endl;
	// this->m_valid = true;
	this->m_firstName = this->GetInput("First name: ");
	this->m_lastName = this->GetInput("Last name: ");
	this->m_nickname = this->GetInput("Nickname: ");
	this->m_phoneNumber = this->GetInput("Phone number: ");
	this->m_secret = this->GetInput("Secret: ");
	this->m_index = i;
	// if (this->m_valid == true)
	std::cout << "Contact successfully added!" << std::endl;
}

void	Contact::printContact(std::string m_str) const
{
	if (m_str.length() > 10)
		std::cout << "|" << std::setw(10) << m_str.substr(0,9) + ".";
	else
		std::cout << "|" << std::setw(10) << m_str; 
}

//index, first name, last name, nickname, must be 10 characters long, trunc with .
void	Contact::ViewContact() const
{
	std::cout << "|" << std::setw(10) << this->m_index; 
	printContact(this->m_firstName);
	printContact(this->m_lastName);
	printContact(this->m_nickname);
	std::cout << "|\n";
	
}

void	Contact::DisplayContact() const
{
	std::cout << "First name: " << this->m_firstName << "\n";
	std::cout << "Last name: " << this->m_lastName << "\n";
	std::cout << "Nickname: " << this->m_nickname << "\n";
	std::cout << "Phone number: " << this->m_phoneNumber << "\n";
	std::cout << "Secret: " << this->m_secret << std::endl;
}

