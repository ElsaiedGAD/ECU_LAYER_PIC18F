/* 
 * File:   ecu_led.h
 * Author: Elsaied Ahmed Gad 
 *
 * Created on 10. September 2023, 12:48
 */

#include "ecu_led.h" 


/* section : functions definitions (Implementation )*/


/**
 * @breif : intialize the assigned pin to be output and turn the led to be off 
 * @param : led pointer to the led module configuration 
 * @return : the status of the function 
 *          E_OK means the function runs successfully 
 */
STD_ReturnType ecu_led_intitalize (const led_t * led) {
    STD_ReturnType ret = E_OK ;
  
    
    if (NULL == led){
        ret = E_NOT_OK ;
    
    }
    else{
          pin_config_t pin_obj = {.PORT = led->port_name ,
                            .PIN = led->pin , 
                            .DIRECTION = output , 
                            .LOGIC = led->LedStatus} ;
          
        ret = gpio_pin_intialize (&pin_obj);
  
    }

    return  ret ; 
}
/**
 * @breif    : function to assign pin high means logic 1 and 5 v  led on 
 * @param    : led pointer to the led module configuration 
 * * @return : the status of the function 
 *             E_OK means the function runs successfully 
 */ 
STD_ReturnType ecu_led_on (const led_t * led) {
    STD_ReturnType ret = E_OK ; 
    if (NULL == led){
        ret = E_NOT_OK ;
    
    }
    else{
          pin_config_t pin_obj = {.PORT = led->port_name ,
                            .PIN = led->pin , 
                            .DIRECTION = output , 
                            .LOGIC = led->LedStatus} ;
          
        ret = gpio_pin_write_logic (&pin_obj ,high ) ;
  
    }

    
    return  ret ; 
}
/**
 * @breif    : function to assign pin high means logic 0 and 0 v  led off
 * @param    : led pointer to the led module configuration 
 * * @return : the status of the function 
 *             E_OK means the function runs successfully 
 */
STD_ReturnType ecu_led_off(const led_t * led) {
    STD_ReturnType ret = E_OK ; 
       if (NULL == led){
        ret = E_NOT_OK ;
    
    }
    else{
          pin_config_t pin_obj = {.PORT = led->port_name ,
                            .PIN = led->pin , 
                            .DIRECTION = output , 
                            .LOGIC = led->LedStatus} ;
          
        ret = gpio_pin_write_logic (&pin_obj ,low ) ;
  
    }

    
    return  ret ; 
}
/**
 * @breif    : function to toggle the pin from low to high or from high to low to turn on or off the led 
 * @param    : led pointer to the led module configuration 
 * * @return : the status of the function 
 *             E_OK means the function runs successfully 
 */
STD_ReturnType ecu_led_toggle (const led_t * led) {
    STD_ReturnType ret = E_OK ; 
       if (NULL == led){
        ret = E_NOT_OK ;
    
    }
    else{
          pin_config_t pin_obj = {.PORT = led->port_name ,
                            .PIN = led->pin , 
                            .DIRECTION = output , 
                            .LOGIC = led->LedStatus} ;
          
        ret = gpio_pin_toggle_logic (&pin_obj) ;
  
    }

    
    return  ret ; 
}