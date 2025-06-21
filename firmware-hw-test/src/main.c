// ###### - Imports - ###### 
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

// ###### - GPIOs config - ###### 
#define PIN_D01         GPIO_NUM_7
#define PIN_D02         GPIO_NUM_0
#define PIN_D03         GPIO_NUM_3
#define PIN_LP_UART_RXD GPIO_NUM_10
#define PIN_LP_UART_TXD GPIO_NUM_11

#define PIN_GPIO_Q1     GPIO_NUM_18
#define PIN_GPIO_Q2     GPIO_NUM_10

#define PIN_S1_sym      GPIO_NUM_23
#define PIN_S2_sym      GPIO_NUM_1
#define PIN_S3_sym      GPIO_NUM_6

#define PIN_GPIO_S1     GPIO_NUM_19
#define PIN_GPIO_S2     GPIO_NUM_12
#define PIN_GPIO_S3     GPIO_NUM_5
#define PIN_S_set       GPIO_NUM_7

#define PIN_RGB_R       GPIO_NUM_22
#define PIN_RGB_G       GPIO_NUM_21
#define PIN_RGB_B       GPIO_NUM_20


// ###### - Main loop - ###### 
void app_main(void)
{
    // Configure the GPIOs
    gpio_reset_pin(PIN_S1_sym);
    gpio_reset_pin(PIN_S2_sym);
    gpio_reset_pin(PIN_S3_sym);
    gpio_set_direction(PIN_S1_sym, GPIO_MODE_INPUT);
    gpio_set_direction(PIN_S2_sym, GPIO_MODE_INPUT);
    gpio_set_direction(PIN_S3_sym, GPIO_MODE_INPUT);


    gpio_reset_pin(PIN_GPIO_Q1);
    gpio_reset_pin(PIN_GPIO_Q2);
    gpio_reset_pin(PIN_RGB_R);
    gpio_reset_pin(PIN_RGB_G);
    gpio_reset_pin(PIN_RGB_B);
    gpio_set_direction(PIN_GPIO_Q1, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_GPIO_Q2, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_RGB_R, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_RGB_G, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN_RGB_B, GPIO_MODE_OUTPUT);


    gpio_set_level(PIN_RGB_R, 0);
    gpio_set_level(PIN_RGB_G, 0);
    gpio_set_level(PIN_RGB_B, 0);
    gpio_set_level(PIN_GPIO_Q1, 1);
    gpio_set_level(PIN_GPIO_Q2, 1);

    vTaskDelay(1000);

    while (1) {
        if(gpio_get_level(PIN_S1_sym)){
            gpio_set_level(PIN_GPIO_Q1, 1);
        }else{
            gpio_set_level(PIN_GPIO_Q1, 0);
        }

        if(gpio_get_level(PIN_S2_sym)){
            gpio_set_level(PIN_GPIO_Q2, 1);
        }else{
            gpio_set_level(PIN_GPIO_Q2, 0);
        }

        if(gpio_get_level(PIN_S3_sym)){
            gpio_set_level(PIN_RGB_R, 1);
            gpio_set_level(PIN_RGB_G, 1);
            gpio_set_level(PIN_RGB_B, 1);
        }else{
            gpio_set_level(PIN_RGB_R, 0);
            gpio_set_level(PIN_RGB_G, 0);
            gpio_set_level(PIN_RGB_B, 0);
        }

    }
}
