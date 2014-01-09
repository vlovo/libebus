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

#ifndef LIBEBUS_COMMAD_HPP_
#define LIBEBUS_COMMAD_HPP_

#include <string>
#include <vector>

namespace libebus
{


typedef std::vector<std::string> cmd_t;
typedef cmd_t::const_iterator cmdCI_t;

typedef std::vector<cmd_t> cmdDB_t;
typedef cmdDB_t::const_iterator cmdDBCI_t;

class Command
{

public:
	Command();
	~Command();

	void addCommand(cmd_t& command);
	void printCommands() const;

	std::size_t size() const;

	cmd_t const& operator[](std::size_t index) const
	{
	    return m_cmdDB[index];
	}

private:
	cmdDB_t m_cmdDB;

	void printCommand(const cmd_t& command) const;
	
};


} //namespace

#endif //LIBEBUS_COMMAD_HPP_