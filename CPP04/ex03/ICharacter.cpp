/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:46:28 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/02 14:00:40 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

struct s_AMateriaList* Character::_droppedMateria = NULL;
struct s_AMateriaList* Character::_lastDroppedMateria = NULL;

Character::Character()
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const std::string& name)
	:	_name(name)
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

Character::Character(const Character& src)
	:	_name(src._name + "_copy")
{
	clearMateria();
	for (int i = 0; i < 4; i++)
		if (src._materia[i])
			this->_materia[i] = src._materia[i]->clone();
}

Character::~Character()
{
	clearMateria();
	//use clearDroppedMateria function in main, not in each individual object's destructor since it is static
}

Character&	Character::operator=(const Character &src)
{
	if (this != &src)
	{
		this->_name = src._name;
		clearMateria();
		for (int i = 0; i < 4; i++)
			if (src._materia[i])
				this->_materia[i] = src._materia[i]->clone();
	}
	return *this;
}

const std::string&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << "Nothing was given to " << _name << " to equip!" << std::endl;
		return ;
	}
	int i;
	//check to see if the source has already been equipped!
	for (i = 0; i < 4; i++)
	{
		if (_materia[i] == m)
		{
			std::cout << "Source has already been added to pack!" << std::endl;
			return ;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if (_materia[i] == NULL)
		{
			_materia[i] = m;
			std::cout << _name << " equipped " << m->getType() << " in slot " << i << std::endl;
			break;
		}
	}
	if (i == 4)
		std::cout << _name << "'s pack is at max capacity!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index entered! Please enter a number between 0 and 3" << std::endl;
	else if (_materia[idx] == NULL)
		std::cout << "This materia slot is empty and cannot be unequipped!" << std::endl;
	else
	{
		std::cout << _name << " dropped materia from slot " << idx << std::endl;
		dropMateria(idx);
		_materia[idx] = NULL;
	}
}

void	Character::dropMateria(int idx)
{
	AMateriaList* newNode = new AMateriaList;
	newNode->materia = _materia[idx];
	newNode->next = NULL;
	if (_droppedMateria == NULL)
	{
		_droppedMateria = newNode;
		_lastDroppedMateria = _droppedMateria;
	}
	else
	{
		_lastDroppedMateria->next = newNode;
		_lastDroppedMateria = _lastDroppedMateria->next;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Invalid index entered! Please enter a number between 0 and 3" << std::endl;
	else if (_materia[idx] == NULL)
		std::cout << "There is no materia to use in this slot!" << std::endl;
	else
	{
		std::cout << _name << ": ";
		_materia[idx]->use(target);
		delete _materia[idx];
		_materia[idx] = NULL;
	}
}

void	Character::clearMateria()
{
	for (int i = 0; i < 4; i++)
	{
		if (_materia[i])
		{
			delete _materia[i];
			_materia[i] = NULL;
		}
	}
}

void	Character::clearDroppedMateria()
{
	if (_droppedMateria == NULL)
		return ;
	while (_droppedMateria)
	{
		AMateriaList* tmp = _droppedMateria;
		_droppedMateria = _droppedMateria->next;
		delete tmp->materia;
		delete tmp;
	}
}
