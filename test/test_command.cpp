/*
 * Copyright (C) Roland Jax 2014 <roland.jax@liwest.at>
 *
 * This file is part of libebus.
 *
 * libebus is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libebus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libebus. If not, see http://www.gnu.org/licenses/.
 */

#include "libebus.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace libebus;

// will be part of cfg csv class
void readCSV(std::istream& is, Command& command){
	std::string line;
	
	// read lines
	while (std::getline(is, line)) {
		std::vector<std::string> row;
		std::string column;
		int count;

		count = 0;
		
		std::istringstream stream(line);
		
		// walk through columns
		while (std::getline(stream, column, ';')) {
			row.push_back(column);
			count++;
		}
		
		command.addCommand(row);
	}
}



int main(){
	Command command;
	
	std::fstream file("test/command.csv", std::ios::in);

	if(file.is_open()) {
		readCSV(file, command);
		file.close();

		command.printCommands();
		std::cout << command[2][9] << std::endl;
		
	} else {
		std::cout << "File not found!\n";
		return -1;
		
	}

	return 0;
}

