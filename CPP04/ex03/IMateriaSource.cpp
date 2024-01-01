#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
	:	_numLearnedMateria(0)
{
	for (int i = 0; i < 4; i++)
		_learnedMateria[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
	:	_numLearnedMateria(src._numLearnedMateria)
{
	for (int i = 0; i < _numLearnedMateria; i++)
		this->_learnedMateria[i] = src._learnedMateria[i]->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _numLearnedMateria; i++)
		delete _learnedMateria[i];
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& src)
{
	if (this != &src)
	{
		for (int i = 0; i < this->_numLearnedMateria; i++)
		{
			delete this->_learnedMateria[i];
			this->_learnedMateria[i] = NULL;
		}
		for (int i = 0; i < src._numLearnedMateria; i++)
			this->_learnedMateria[i] = src._learnedMateria[i]->clone();
	}
	return *this;
}

void	MateriaSource::learnMateria(AMateria* src)
{
	if (_numLearnedMateria == 4)
	{
		std::cout << "max Materia has been learned" << std::endl;
		return ;
	}
	_learnedMateria[_numLearnedMateria] = src->clone();
	_numLearnedMateria++;
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	int i = 0;
	while (i < _numLearnedMateria)
	{
		if (_learnedMateria[i]->getType() == type)
			break ;
		i++;
	}
	if (i == _numLearnedMateria)
		return (NULL);
	AMateria *newMateria = _learnedMateria[i]->clone();
	return (newMateria);
}