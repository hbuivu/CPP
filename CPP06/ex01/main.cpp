/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui-vu <hbui-vu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:41:07 by hbui-vu           #+#    #+#             */
/*   Updated: 2024/01/15 13:33:05 by hbui-vu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main()
{
	Data *data = new Data;
	data->info = "some data\n";
	uintptr_t serAddress = Serializer::serialize(data);
	std::cout << "serialized address: " << serAddress << "\n";
	Data * desAddress = Serializer::deserialize(serAddress);
	std::cout	<< "data address: " << data << "\n"
				<< "desAddress:   " << desAddress << "\n";
	std::cout << data->info;
	data->info = "hello\n";
	std::cout << data->info;
	delete data;
}