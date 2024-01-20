void	parseDatabase(std::string Database)
{
	
	std::ifstream infile(Database);
	if (!infile.is_open())
		throw Exception;
	std::string line;
	std::getline(infile, line);
	if (line != "date,exchange_rate")
		throw Exception;
	while (std::getline(infile, line))
	{
		std::tm date = {0};
		std::istringstream ss(line);
		char dash1, dash2, comma;
		double exchangeRate;
		ss	>> date.tm_year >> dash1 >> date.tm_mon >> dash2
			>> date.tm_mday >> comma >> exchangeRate;
		//ss.fail() - did extraction fail
		//ss.get() != EOF - are there still extra characters in string line
		if (ss.fail() || ss.get() != EOF ||
			dash1 != '-' ||dash2 != '-' || comma != ',' ||
			exchangeRate < 0 || exchangeRate > INT_MAX)
			throw Exception;
		//adjust year and month to match data requirements in struct
		date.tm_year -= 1900; //year range starts from 1900
		date.tm_mon -= 1 //month range 0-11
		if (std::mktime(&date) == -1)
			throw Exception;
		if (database.find(date) != database.end()) //if a copy is found already
			throw Exception;
		database[date] = exchangeRate;
	}
}

void	parseInput(std::string Input)
{
	std::ifstream infile(Input);
	if (!infile.is_open())
		throw Exception;
	std::string line;
	std::getline(infile, line);
	if (line != "date | value")
		throw Exception;
	while (std::getline(infile, line))
	{
		std::tm date = {0};
		std::istringstream ss(line);
		char dash1, dash2, pipe; //istringstream ignores leading white spaces
		double value;
		ss	>> date.tm_year >> dash1 >> date.tm_mon >> dash2
			>> date.tm_mday >> pipe >> value;
		if (ss.fail() || ss.get() != EOF ||
			dash1 != '-' ||dash2 != '-' || pipe != '|' ||
			value < 0 || value > 1000)
			throw Exception;
		//adjust year and month to match data requirements in struct
		date.tm_year -= 1900; //year range starts from 1900
		date.tm_mon -= 1 //month range 0-11
		if (std::mktime(&date) == -1)
			throw Exception;
		//make a class
		if (date < _database.begin() || date > database.end()) //somethign like this
			throw Exception
		if(_database.find(data) != _database.end())
			//print out result
		else
			//use while loop to iterate over database to check when date becomes bigger than input date
			//is it possible to match year and month too?
	}
}
