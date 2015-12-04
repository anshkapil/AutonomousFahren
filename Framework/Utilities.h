#include "Command.h"
#include "carState.h"

commandSender lastCommandSender;

class CommandManager {
private:
	commandSender sender;
public:
	void sendCommand(commandType type, void* command);
	CommandManager(commandSender sender);

	commandSender getLastCommandSender();

	Command* readLastCommand();
};

class DataManager {
public:
	sensor_data getData();

	void setData(sensor_data data);
};
