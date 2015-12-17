/*
 * utilities.h
 *
 *  Created on: Dec 11, 2015
 *      Author: Ansh Kapil
 */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef UTILITIES_H_
#define UTILITIES_H_

#include "commandTypes.h"
#include "system.h"


Result getData(Component_type type , struct sensor_data* data);

#endif /* UTILITIES_H_ */
#ifdef __cplusplus
}
#endif
