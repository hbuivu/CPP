/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:29 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/13 12:08:29 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::string	_firstName;
	std::string _lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_secret;
	void		printContact(std::string m_str) const;
public:
	int			p_index;
	Contact();
	~Contact();
	std::string	GetInput(std::string str);
	void		NewContact(int i);
	void		ViewContact() const;
	void		DisplayContact() const;
};

bool	OnlyWhiteSpace(std::string str);

#endif