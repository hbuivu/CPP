/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:08:59 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/13 12:40:31 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include "contacts.hpp"

class PhoneBook
{
private:
	Contact	_contact[8];
	void	_PrintName(std::string name) const;
	int		_PrintContacts() const;
public:
	PhoneBook();
	~PhoneBook();
	
	void	Intro() const;
	void	AddContact();
	void	SearchContacts() const;
};
#endif
