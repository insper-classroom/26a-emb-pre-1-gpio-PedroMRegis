#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

int main() {
  stdio_init_all();

  const int LED_PIN_VERMELHO = 5;
  const int LED_PIN_ROXO = 8;
  const int LED_PIN_AZUL = 11;
  const int LED_PIN_AMARELO = 15;

  const int BTN_VERMELHO = 28;

  gpio_init(LED_PIN_VERMELHO);
  gpio_set_dir(LED_PIN_VERMELHO, GPIO_OUT);

  gpio_init(LED_PIN_ROXO);
  gpio_set_dir(LED_PIN_ROXO, GPIO_OUT);

  gpio_init(LED_PIN_AZUL);
  gpio_set_dir(LED_PIN_AZUL, GPIO_OUT);

  gpio_init(LED_PIN_AMARELO);
  gpio_set_dir(LED_PIN_AMARELO, GPIO_OUT);

  gpio_init(BTN_VERMELHO);
  gpio_set_dir(BTN_VERMELHO, GPIO_IN);
  gpio_pull_up(BTN_VERMELHO);

  while (true) {
    // Use delay de 300 ms entre os estados!

    if (!gpio_get(BTN_VERMELHO)) {
      sleep_ms(50); 
      while (!gpio_get(BTN_VERMELHO)) {
        sleep_ms(10);
      };
      gpio_put(LED_PIN_VERMELHO, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_VERMELHO, 0);
      gpio_put(LED_PIN_ROXO, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_ROXO, 0);
      gpio_put(LED_PIN_AZUL, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_AZUL, 0);
      gpio_put(LED_PIN_AMARELO, 1);
      sleep_ms(300);
      gpio_put(LED_PIN_AMARELO, 0);

   }
  }
}
