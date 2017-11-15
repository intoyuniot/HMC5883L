 #include <hmc5883l.h>

 HMC5883L hmc5883l;

 int16_t cx_tmp,cy_tmp,cz_tmp;

 void setup()
 {
    Wire.begin();
    delay(500);
    hmc5883l.begin();
 }

void loop()
{
    hmc5883l.GetData(&cx_tmp,&cy_tmp,&cz_tmp);
    delay(1000);
}
