#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "contacts.hpp"

class PhoneBook
{
private:
	Contact m_contact[8];
	// int		m_contactCount;
	int	PrintContacts() const;
public:
	PhoneBook();
	~PhoneBook();
	void	Intro() const;
	void	AddContact();
	void	SearchContacts() const;
};
#endif
