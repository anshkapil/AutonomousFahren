
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

};

struct message{




};


enum route_command{
	TURN_STRAIGHT,
	TURN_RIGHT,
	TURN_LEFT,
	PARK
};

struct route_planner{



};


typedef enum result{
	RESULT_FAILURE,
	RESULT_SUCCESS
} Result;
