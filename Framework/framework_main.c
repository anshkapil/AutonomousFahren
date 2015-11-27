#include <stdio.h>
#include <io.h>
#include "head.h"
#include "carState.h"
#include "system.h"
#include "alt_types.h"

typedef struct sensor_data sensor_data;

void init(Component_type type){

	if(type == COMPONENT_ULTRASOUND){
		pHc_sr04 = (volatile unsigned int*)(HC_SR04_0_BASE | 0x80000000);
		pUltraSoundArray = (volatile unsigned int*)(ULTRA_SOUND_0_READING_ADDR | 0x80000000);
	}

	if(type == COMPONENT_ACCELEROMETER || type == COMPONENT_GYRO)
	{
	    pI2C = (volatile unsigned char*)(I2C_SLAVE_ADDR);
	    pI2CReg = (volatile unsigned char*)(I2C_REG_ADDR);
	    pI2CRegWriteData = (volatile unsigned char*)(I2C_REG_WRITE_DATA);
	    pI2CDataLen = (volatile unsigned char*)(I2C_DATALENGTH_ADDR);
	    pI2CCmd = (volatile unsigned char*)(I2C_CMD_ADDR);
	    pI2CDataAvailable = (volatile unsigned char*)(I2C_DATA_AVAILABLE_ADDR);

		I2CWrite(MPU_SLAVE_ADDRESS, 0x6b, 0x0); // Enabling the sensor

	}


}

void I2CWrite(unsigned char I2CAddr, unsigned char RegAddr, unsigned char data)
{
	*pI2C = I2CAddr; // FIrst write which I2C module is being addressed. MPU or HMC
	*pI2CReg = RegAddr; // write the address of register to which you want to write
	*pI2CRegWriteData = data; // write the data
	*pI2CDataLen = 1; // currently only 1 is supported for write access
	*pI2CCmd = (I2C_WRITE_CMD_MASK | I2C_START_CMD_MASK); // give write+start command
}

void I2CRead(unsigned char I2CAddr, unsigned char RegAddr, unsigned int len, char* cBuff)
{
	unsigned int i = 0;

	*pI2C = I2CAddr; //FIrst write which I2C module is being addressed. MPU or HMC
	*pI2CReg = RegAddr; // give the address of register from which you want to read in burst fashion
	*pI2CDataLen = len; // number of bytes you want to read
	*pI2CCmd = (I2C_READ_CMD_MASK | I2C_START_CMD_MASK); // give read+start command

	/*The CPU is free to do its work until the following flag is set. The HW module will do a burst access and read the number of requested bytes
	 * from the slow I2C slave and keep it onchip in a FIFO. Once the flag is set, the data can be read from the FIFO rapidly*/
	while((*pI2CDataAvailable != 0x1));

	for (i = 0; i < len; i++)
	{
		cBuff[i] = *pI2C;
	}

	return;
}


float MeasureDistance(unsigned int i)
{
	float x = (float)pUltraSoundArray[i] * 330000/ALT_CPU_FREQ;
	return x/2.0f ;
}

void delay (volatile unsigned int del)
{
	while (del != 0)
	{
		del --;
	}
}

int getData(Component_type type , sensor_data* data)
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
typedef enum
{
	true,
	false
} bool_t;

int main()
{
	printf("Start");

	sensor_data data = {0,};
	pwm_enable = (volatile unsigned int*)(0x80000000 | PWM_ENABLE);
	*pwm_enable = 0;

	init(COMPONENT_ULTRASOUND);
	Result res = getData(COMPONENT_ULTRASOUND , &data);

	if(res == RESULT_SUCCESS)
		printf("Sensor 1: %f \n", data.distance_ultrasound[0]);

	init(COMPONENT_ACCELEROMETER);
	res = getData(COMPONENT_ACCELEROMETER , &data);
	if(res == RESULT_SUCCESS){

		printf("AcX = %d\n", data.accelerometerData[0]);
		printf("AcY = %d\n", data.accelerometerData[1]);
		printf("AcZ = %d\n", data.accelerometerData[2]);

		printf("Temp = %f\n", data.temperature);

		printf("GyX = %d\n", data.gyroData[0]);
		printf("GyY = %d\n", data.gyroData[1]);
		printf("GyZ = %d\n", data.gyroData[2]);
	}
	printf("Done");
	return 0;
}
