/*
 * CommandMgr.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Ansh Kapil
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef COMMANDMGR_H_
#define COMMANDMGR_H_

#include "Command.h"

struct CommandMgr {

	commandSender s;
};

void sendCommand(commandType type, commandSender sender, void* command);
commandSender getLastCommandSender();
struct Command* readLastCommand(commandSender sender);

#endif /* COMMANDMGR_H_ */

#ifdef __cplusplus
}
#endif
