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

#include "hmc5883l.h"

HMC5883L::HMC5883L()
{
    deviceAddress = HMC5883L_ADDRESS;
}

void HMC5883L::begin(void)
{

    //I2Cdev::writeByte(MPU6050_DEFAULT_ADDRESS, 0x6a, 0x00);

    //I2Cdev::writeByte(MPU6050_DEFAULT_ADDRESS, 0x37, 0x02);

    delay(10);

    I2Cdev::writeByte(deviceAddress, REGISTER_A, 0x70);
    I2Cdev::writeByte(deviceAddress, REGISTER_B,  0xA0);
    I2Cdev::writeByte(deviceAddress, MODE_REGISTER, 0x00);
}


void HMC5883L::GetData(int16_t* cx, int16_t* cy, int16_t* cz)
{
    I2Cdev::readBytes(deviceAddress, X_MSB, 6, buffer,100);

    *cx = (((int16_t)buffer[0]) << 8) | buffer[1];
    *cz = (((int16_t)buffer[2]) << 8) | buffer[3];
    *cy = (((int16_t)buffer[4]) << 8) | buffer[5];

}


uint16_t HMC5883L::AngleCalculation(void) // 0-360°
{
    GetData(&compass_x,&compass_y,&compass_z);

    angle = atan2((double)compass_y,(double)compass_x)*(180/3.14159265)+180;

    return (uint16_t)angle;
}
