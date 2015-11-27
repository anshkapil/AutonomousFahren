/*
 * Command.cpp
 *
 *  Created on: 27.11.2015
 *      Author: Julia
 */

#include "Command.h"

Command::Command(commandType type, commandSender sender, void* command) {
	this.type = type;
	this.sender = sender;
	this.command = command;
}

Command::~Command() {
	// TODO Auto-generated destructor stub
}

commandType Command::getCommandType() {
	return type;
}

commandSender Command::getCommandSender() {
	return sender;
}

void* Command::getCommand() {
	return command;
}
