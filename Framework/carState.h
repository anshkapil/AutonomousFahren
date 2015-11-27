#include "head.h"

#define PWM_ENABLE 10

typedef enum Component{
	COMPONENT_ULTRASOUND,
	COMPONENT_ACCELEROMETER,
	COMPONENT_GYRO,
	COMPONENT_TEMPERATURE
} Component_type;

enum car_state{
	CAR_STATE_READY,
	CAR_STATE_LANE_DETECTION,
	CAR_STATE_PARKING,
	CAR_STATE_BUSY,
	CAR_STATE_EMERGENCY
};

struct sensor_data{
	float distance_ultrasound[NUMBER_OF_ULTRA_SOUND_DEVICES];
	float accelerometerData[3];
	float gyroData[3];
	float temperature;

};

typedef enum {
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

typedef enum {

	WHEELS,
	LIGHTS,
	EMERGENCY

}commandType;


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

void (*message)(commandSender sender,commandType type , void *params);


enum route_command{
	TURN_STRAIGHT,
	TURN_RIGHT,
	TURN_LEFT,
	PARK
};

struct route_planner{

// Can be a function with params as a list of commands

};



typedef enum result{
	RESULT_FAILURE,
	RESULT_SUCCESS
} Result;
