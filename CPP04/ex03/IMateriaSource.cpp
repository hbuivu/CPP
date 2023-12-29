#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
	:	_learnedMateria(new AMateria* [5]), //or initialize a list of 4 spaces??
		_numLearnedMateria(0)
{
}

MateriaSource::MateriaSource(const MateriaSource& src)
	:	_learnedMateria(new AMateria *[5]),
		_numLearnedMateria(src._numLearnedMateria)
{
	//copy over stuff		
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i++; i < _numLearnedMateria)
		delete _learnedMateria[i];
	delete[] _learnedMateria;
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
	while (i++ < _numLearnedMateria)
		if (_learnedMateria[i]->getType() == type)
			break ;
	if (i == _numLearnedMateria)
		return (NULL);
	AMateria *newMateria = _learnedMateria[i]->clone();
	return (newMateria);
}