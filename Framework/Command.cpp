/*
 * Command.cpp
 *
 *  Created on: 27.11.2015
 *      Author: Julia
 */

#include "Command.h"

Command::Command(commandType t, commandSender s, void* comm) {
	types = t;
	send = s;
	commands = comm;
}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

commandType Command::getCommandType() {
	return types;
}

commandSender Command::getCommandSender() {
	return send;
}

void* Command::getCommand() {
	return commands;
}
