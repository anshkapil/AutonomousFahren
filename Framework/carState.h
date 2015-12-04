#include "head.h"

#define PWM_ENABLE 10

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

typedef enum {
	LIGHTS_HEAD,
	LIGHTS_SIGNAL_RIGHT,
	LIGHTS_SIGNAL_LEFT,
	LIGHTS_BRAKE
}lightType;

typedef enum {
	LIGHTS_ON,
	LIGHTS_OFF,
	LIGHTS_BLINKING
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
	bool isEmergency;
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



