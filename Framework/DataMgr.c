/*
 * DataMgr.cpp
 *
 *  Created on: Dec 11, 2015
 *      Author: Ansh Kapil
 */

#include "DataMgr.h"
#include "system.h"
#include "commandTypes.h"


struct sensor_data getSensorData() {
	struct sensor_data* data_ptr = (struct sensor_data*) (0x80000000 | STATE_CMD_MEMORY_BASE);
	struct sensor_data data = *data_ptr;
	return data;
}

void setData(struct sensor_data* data) {
	struct sensor_data* data_ptr = (struct sensor_data*) (0x80000000 | STATE_CMD_MEMORY_BASE);
	data = data_ptr;
}
