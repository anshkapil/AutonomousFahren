/*
 * Command.h
 *
 *  Created on: 27.11.2015
 *      Author: Julia
 */

#include "commandTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef COMMAND_H_
#define COMMAND_H_

#define SENSOR_DATA_OFFSET 10
#define PARKING_OFFSET 110
#define LANE_DETECTION_OFFSET 160
#define OBSTACLE_AVOIDANCE_OFFSET 210


struct Command {
	commandType __type;
	commandSender __sender;
	void* __command;
};



#endif /* COMMAND_H_ */
#ifdef __cplusplus
}
#endif
