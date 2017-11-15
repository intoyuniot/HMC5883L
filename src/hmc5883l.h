/*
 ******************************************************************************

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation, either
 version 3 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, see <http://www.gnu.org/licenses/>.

 This library is HMC5883L electronic compass module

 ******************************************************************************
 */

#ifndef HMC5883L_H_
#define HMC5883L_H_

#include "I2Cdev.h"
#include "Arduino.h"
#include <math.h>

#define HMC5883L_ADDRESS  0x3c >> 1

#define REGISTER_A				0x00
#define REGISTER_B				0x01
#define MODE_REGISTER			0x02
#define X_MSB					0x03
#define X_LSB					0x04
#define Z_MSB					0x05
#define Z_LSB					0x06
#define Y_MSB					0x07
#define Y_LSB					0x08
#define STATUS_REGISTER			0x09
#define DISCERN_REGISTER_A		0x10
#define DISCERN_REGISTER_B		0x11
#define DISCERN_REGISTER_C		0x12




class HMC5883L
{
    public:

        HMC5883L();

        void begin(void);

        void GetData(int16_t* cx, int16_t* cy, int16_t* cz);

        uint16_t AngleCalculation(void);

    private:

        uint8_t deviceAddress;
        uint8_t buffer[6];
        int16_t compass_x;
        int16_t compass_y;
        int16_t compass_z;

        double angle;

};

#endif
