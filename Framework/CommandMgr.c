/*
 * CommandMgr.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: Ansh Kapil
 */

#include "CommandMgr.h"
#include "commandTypes.h"
#include "system.h"

#define SENSOR_DATA_OFFSET 10
#define PARKING_OFFSET 110
#define LANE_DETECTION_OFFSET 160
#define OBSTACLE_AVOIDANCE_OFFSET 210

commandSender lastCommandSender;

void sendCommand(commandType type, commandSender sender, void* command) {
	struct Command* currentCommand;
	currentCommand-> __type = type;
	currentCommand->__sender = sender;
	currentCommand->__command = command;
	int offset;
	switch (sender) {
	case APP_PARKING:
		offset = PARKING_OFFSET;
		break;
	case APP_LANE_DETECTION:
		offset = LANE_DETECTION_OFFSET;
		break;
	default:
		offset = 0;
		break;
	}
	struct Command* command_ptr = (struct Command*) (0x80000000
			| STATE_CMD_MEMORY_BASE + offset);
	currentCommand = command_ptr;

	lastCommandSender = sender;
}


struct Command* readLastCommand(commandSender sender) {

	int offset;
	switch (sender) {
	case APP_LANE_DETECTION:
		offset = LANE_DETECTION_OFFSET;
		break;
	case APP_PARKING:
		offset = PARKING_OFFSET;
		break;
	default:
		offset = 0;
		break;
	}
	struct Command* command_ptr = (struct Command*) (0x80000000
			| STATE_CMD_MEMORY_BASE + offset);
	return command_ptr;
}
