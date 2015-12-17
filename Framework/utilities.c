#include "utilities.h"

Result getData(Component_type type , struct sensor_data* data)
{
	int i;
	Result res = RESULT_FAILURE;
	if(type == COMPONENT_ULTRASOUND)
		{
			while(*pHc_sr04 != 0xff);

			// Fire all ultrasound sensors
			*pHc_sr04 = 0xff;	// 0xff: All sensors are activated and sending data

			while(*pHc_sr04 != 0xff);

			for (i = 0; i < NUMBER_OF_ULTRA_SOUND_DEVICES; i++)
			{
				data->distance_ultrasound[i] =  MeasureDistance(i);
			}
			res = RESULT_SUCCESS;
		}

	if(type == COMPONENT_ACCELEROMETER)
	{
		char cBuff[32];
		I2CRead(MPU_SLAVE_ADDRESS, 0x3B, 14, cBuff);

		data->accelerometerData[0] =(float)((cBuff[0] << 8) | (cBuff[1] & 0xff));
		data->accelerometerData[1] =(float)((cBuff[2] << 8) | (cBuff[3] & 0xff));
		data->accelerometerData[2] =(float)((cBuff[4] << 8) | (cBuff[5] & 0xff));

		data->temperature = (float)(((cBuff[6] << 8) | (cBuff[7] & 0xff))/340 + 36.53);

		data->gyroData[0] =(float)((cBuff[8] << 8) | (cBuff[9] & 0xff));
		data->gyroData[1] =(float)((cBuff[10] << 8) | (cBuff[11] & 0xff));
		data->gyroData[2] =(float)((cBuff[12] << 8) | (cBuff[13] & 0xff));

		res = RESULT_SUCCESS;
	}

	return res;

}




