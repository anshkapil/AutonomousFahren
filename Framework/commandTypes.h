/*
 * commandTypes.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Ansh Kapil
 */


#ifdef __cplusplus
extern "C" {
#endif

#ifndef COMMANDTYPES_H_
#define COMMANDTYPES_H_

#include"head.h"
#include"alt_types.h"


typedef enum Component{
	COMPONENT_ULTRASOUND,
	COMPONENT_ACCELEROMETER,
	COMPONENT_GYRO,
	COMPONENT_TEMPERATURE
} Component_type;

typedef enum car_state{
	CAR_STATE_READY,
	CAR_STATE_LANE_DETECTION,
	CAR_STATE_PARKING,
	CAR_STATE_BUSY,
	CAR_STATE_EMERGENCY
} car_state;

struct sensor_data{
	float distance_ultrasound[NUMBER_OF_ULTRA_SOUND_DEVICES];
	float accelerometerData[3];
	float gyroData[3];
	float temperature;

};

typedef enum command_Sender{
	APP_LANE_DETECTION,
	APP_PARKING
}commandSender;

typedef enum lightType{
	TYPE_LIGHTS_HEAD,
	TYPE_LIGHTS_SIGNAL_RIGHT,
	TYPE_LIGHTS_SIGNAL_LEFT,
	TYPE_LIGHTS_BRAKE
}lightType;

typedef enum light_State{
	STATE_LIGHTS_ON,
	STATE_LIGHTS_OFF,
	STATE_LIGHTS_BLINKING
}lightState;


typedef enum command_Type{

	TYPE_WHEELS,
	TYPE_LIGHTS,
	TYPE_EMERGENCY,
	TYPE_PARKING

} commandType;


struct commandParking {
	float x;
	float y;
};

struct commandLight{
	lightType type;
	lightState state;

};

struct commandWheel{
	float angle;
	float speed;

};

struct commandEmergency {
	int isEmergency;
};

typedef enum route_command{
	TURN_STRAIGHT,
	TURN_RIGHT,
	TURN_LEFT,
	PARK
} route_command;

struct route_planner{

// Can be a function with params as a list of commands

};

typedef enum result{
	RESULT_FAILURE,
	RESULT_SUCCESS
} Result;

#endif /* COMMANDTYPES_H_ */


#ifdef __cplusplus
}
#endif
