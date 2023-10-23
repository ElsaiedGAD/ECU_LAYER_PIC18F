/* 
 * File:   ecu_led.h
 * Author: Elsaied Ahmed Gad 
 *
 * Created on 10. September 2023, 12:48
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/*Section : includes !!!! */

#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "led_config.h" 

/*Section : Macros Declaration !!!! */

#define LEDOFF    0X00 
#define LEDON     0x01 

/*Section : Macros Functions !!!! */

/*Section : Data TYPES Declaration !!!! */
typedef enum {
    LED_OFF ,
    LED_ON
            
}led_status_t ;

typedef struct {
    uint_8 port_name : 4 ;
    uint_8 pin  : 1 ;
    uint_8 LedStatus : 3 ;
    
}led_t;
/*Section : Function Declaration !!!! */

STD_ReturnType ecu_led_intitalize (const led_t * led) ;
STD_ReturnType ecu_led_on (const led_t * led) ;
STD_ReturnType ecu_led_off(const led_t * led) ;
STD_ReturnType ecu_led_toggle (const led_t * led) ;


#endif	/* ECU_LED_H */

