/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:13:18 by hbui-vu           #+#    #+#             */
/*   Updated: 2023/12/14 16:13:18 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

# include <string>
# include <sys/stat.h>
# include <iostream>
# include <fstream>
# include <sstream>

class Sed
{
private:
	std::string	_infile;
	std::string _outfile;
	std::string	_find;
	std::string	_replace;
	Sed();
public:
	Sed(std::string infile, std::string find, std::string replace);
	~Sed();

	void	replace();
};

#endif