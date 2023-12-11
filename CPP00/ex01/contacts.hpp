#ifndef CONTACTS_HPP
# define CONTACTS_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cstdlib>
# include <iomanip>


class Contact
{
private:
	std::string	m_firstName;
	std::string m_lastName;
	std::string	m_nickname;
	std::string	m_phoneNumber;
	std::string	m_secret;
	// bool		m_valid;
	void		printContact(std::string m_str) const;
public:
	int			m_index;
	Contact();
	~Contact();
	std::string	GetInput(std::string str);
	void		NewContact(int i);
	void		ViewContact() const;
	void		DisplayContact() const;
};

#endif