/*
 * DataMgr.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Ansh Kapil
 */
#include "commandTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef DATAMGR_H_
#define DATAMGR_H_

struct sensor_data getSensorData();
void setData(struct sensor_data* data);



#endif /* DATAMGR_H_ */
#ifdef __cplusplus
}
#endif
