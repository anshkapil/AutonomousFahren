#include "Command.h"
#include "Utilities.h"
#include "system.h"
#include "carState.h"

void CommandManager::sendCommand(commandType type, void* command) {
	Command currentCommand(type, sender, command);
	size_t offset;
	switch (sender) {
	case 0:
		offset = PARKING_OFFSET;
		break;
	case 1:
		offset = LANE_DETECTION_OFFSET;
		break;
	default:
		offset = 0;
		break;
	}
	Command* command_ptr = (Command*) (0x80000000
			| STATE_CMD_MEMORY_BASE + offset);
	currentCommand = command_ptr;

	lastCommandSender = sender;
}

CommandManager::CommandManager(commandSender sender) {
	this.sender = sender;
}

commandSender CommandManager::getLastCommandSender() {

	return lastCommandSender;
}

Command* CommandManager::readLastCommand() {
	commandSender lastSender = getLastCommandSender();
	size_t offset;
	switch (sender) {
	case 0:
		offset = PARKING_OFFSET;
		break;
	case 1:
		offset = LANE_DETECTION_OFFSET;
		break;
	default:
		offset = 0;
		break;
	}
	Command* command_ptr = (Command*) (0x80000000
			| STATE_CMD_MEMORY_BASE + offset);
	return command_ptr;
}

sensor_data DataManager::getData() {
	sensor_data* data_ptr = (sensor_data*) (0x80000000 | STATE_CMD_MEMORY_BASE);
	sensor_data data = *data_ptr;
	return data;
}

void DataManager::setData(sensor_data data) {
	sensor_data* data_ptr = (sensor_data*) (0x80000000 | STATE_CMD_MEMORY_BASE);
	data = data_ptr;
}

