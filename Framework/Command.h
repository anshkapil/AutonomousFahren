/*
 * Command.h
 *
 *  Created on: 27.11.2015
 *      Author: Julia
 */

#include "carState.h"


#ifndef COMMAND_H_
#define COMMAND_H_

#define SENSOR_DATA_OFFSET 10
#define PARKING_OFFSET 110
#define LANE_DETECTION_OFFSET 160
#define OBSTACLE_AVOIDANCE_OFFSET 210

class Command {
private:
	commandType type;
	commandSender sender;
	void* command;
public:
	commandType getCommandType() {};
	commandSender getCommandSender() {};
	void* getCommand() {};
	Command(commandType type, commandSender sender, void* command) {};
	virtual ~Command();
};


#endif /* COMMAND_H_ */
