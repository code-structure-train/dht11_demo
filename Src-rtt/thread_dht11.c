#include <entry.h>
#include "stm32f4xx_hal.h"
#include "LCD.h"
#include "dht11.h"

rt_thread_t dht11_thread = RT_NULL;

extern DHT11_Dev dht11;

void dht11_thread_entry(void* parameter)
{
  char rh[40];
  char temp[40];
  while(1) {    
    DHT11_Read(&dht11);
    sprintf(rh,   "RH  : %d.%d%%", dht11.humidity, dht11.hum_float);
    sprintf(temp, "TEMP: %d.%d ", dht11.temparature, dht11.temp_float);
    LCD_Puts(0,0,rh);
    LCD_Puts(0,1,temp);
    rt_thread_delay(10);
  }
}
