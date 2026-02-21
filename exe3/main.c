#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>



const int RED_BUTTON = 28;
const int GREEN_BUTTON = 26;

const int RED_LED = 4;
const int GREEN_LED = 6;

int main() {
  stdio_init_all();

  gpio_init(RED_BUTTON);
  gpio_set_dir(RED_BUTTON, GPIO_IN);
  gpio_pull_up(RED_BUTTON);

  gpio_init(GREEN_BUTTON);
  gpio_set_dir(GREEN_BUTTON, GPIO_IN);
  gpio_pull_up(GREEN_BUTTON);

  gpio_init(RED_LED);
  gpio_set_dir(RED_LED, GPIO_OUT);

  gpio_init(GREEN_LED);
  gpio_set_dir(GREEN_LED, GPIO_OUT);

  int red_led_state = 0;
  int green_led_state = 0;

  while(true) {
    
    if (!gpio_get(RED_BUTTON)){
      if (red_led_state == 0){
        red_led_state = 1;
      }
      else{
        red_led_state = 0;
      }

      gpio_put(RED_LED,red_led_state);
      while(!gpio_get(RED_BUTTON)) {
      };
    }
    
    if (!gpio_get(GREEN_BUTTON)){
      if (green_led_state == 0){
        green_led_state = 1;
      }
      else{
        green_led_state = 0;
      }

      gpio_put(GREEN_LED,green_led_state);
      while(!gpio_get(GREEN_BUTTON)) {
      };
    }
  }


}