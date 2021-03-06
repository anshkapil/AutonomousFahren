/*
 * aaa_c_connector.cpp
 *
 *  Created on: Dec 18, 2015
 *      Author: Ansh Kapil
 */

#include <stdio.h>
#include <io.h>
#include "system.h"
#include "alt_types.h"
#include "commandTypes.h"
#include "DataMgr.h"
#include "CommandMgr.h"
#include "utilities.h"

#include <cstdlib>

#include "cppConnector.h"

#ifdef __cplusplus
extern "C" {
#endif

// Inside this "extern C" block, I can define C functions that are able to call C++ code
typedef struct sensor_data sensorData;


void launch() {

	//Command* c1 = (Command*) (0x80000000 |STATE_CMD_MEMORY_BASE);
		printf("Start");

		struct sensor_data data = {0,};
		*pwm_enable = 0;

		init();
		Result res = getData(COMPONENT_ULTRASOUND , &data);

		if(res == RESULT_SUCCESS)
			printf("Sensor 1: %f \n", data.distance_ultrasound[0]);

	//	res = getData(COMPONENT_ACCELEROMETER , &data);
	//	if(res == RESULT_SUCCESS){
	//
	//		printf("AcX = %d\n", data.accelerometerData[0]);
	//		printf("AcY = %d\n", data.accelerometerData[1]);
	//		printf("AcZ = %d\n", data.accelerometerData[2]);
	//
	//		printf("Temp = %f\n", data.temperature);
	//
	//		printf("GyX = %d\n", data.gyroData[0]);
	//		printf("GyY = %d\n", data.gyroData[1]);
	//		printf("GyZ = %d\n", data.gyroData[2]);
	//	}
	//	printf("Done");

		setData(&data);

		commandSender sender = APP_LANE_DETECTION;
		commandType cmdType = TYPE_LIGHTS;
		struct commandLight cl;
		cl.state = STATE_LIGHTS_ON;
		cl.type = TYPE_LIGHTS_HEAD;
		void* commandToSend = (void*)&cl;

		sendCommand(cmdType,sender, commandToSend);

		delay(1000);

		struct Command* command_ptr = readLastCommand(sender);
		commandType type_new = command_ptr->__type;
		commandSender sender_new = command_ptr->__sender;
		void* command_new = command_ptr->__command;
		printf("%d\n", sender_new);

		struct commandLight* cl_new;
		struct commandWheel* cw_new;
		struct commandEmergency* ce_new;
		struct commandParking* cp_new;

		switch(type_new) {
		case TYPE_LIGHTS:
	//		struct commandLight* cl_new;
			cl_new = (struct commandLight*)command_new;
			printf("%d\n", cl_new->state);
			break;
		case TYPE_WHEELS:
	//		struct commandWheel* cw_new;
			cw_new= (struct commandWheel*) command_new;
			break;
		case TYPE_EMERGENCY:
	//		struct commandEmergency* ce_new;
			ce_new = (struct commandEmergency*) command_new;
			break;
		case TYPE_PARKING:
	//		struct commandParking* cp_new;
			cp_new = (struct commandParking*) command_new;
			break;
		default: break;
		}


}

#ifdef __cplusplus
}
#endif

