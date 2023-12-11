#include "phonebook.hpp"

int main(void)
{
	PhoneBook pb;
	std::string cmd = "";

	pb.Intro();
	while (cmd.compare("EXIT") != 0)
	{
		std::cout << "What would you like to do? " << std::flush;
		std::getline(std::cin, cmd); 
		if (std::cin.eof())
		{
			std::cout << "\nClosing your PhoneBook...\n";
			std::exit(1);
		}
		if (cmd.compare("ADD") == 0)
			pb.AddContact();
		else if (cmd.compare("SEARCH") == 0)
			pb.SearchContacts();
		else if (cmd.compare("EXIT") != 0)
			std::cout << "Sorry, this option is invalid.\n";
		else if (!std::cin.good())
		{
			std::cout << "An error has occurred. Press enter to continue..." << std::flush;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	std::cout << "Closing your PhoneBook. Bye Bye!" << std::endl;
	return (0);
}