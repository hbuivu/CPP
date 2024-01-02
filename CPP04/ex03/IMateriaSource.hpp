/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:46:43 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/02 13:46:44 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "AMateria.hpp"

class IMateriaSource
{
public:
	virtual ~IMateriaSource(){};

	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(const std::string& type) = 0;
};

class MateriaSource : public IMateriaSource
{
private:
	AMateria*	_learnedMateria[4]; //create an array of 4 AMateria* in stack
	int			_numLearnedMateria;
public:
	MateriaSource();
	MateriaSource(const MateriaSource& src);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& src);

	void		learnMateria(AMateria* src);
	AMateria*	createMateria(const std::string& type);
};

#endif

/* NOTES:
if using new to AMateria **, learnedMateria would only hold the pointer to the first element of the array */