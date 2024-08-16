#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN = 28;
const int PIN_R = 5;
const int PIN_P = 8;
const int PIN_B = 11;
const int PIN_Y = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN);
  gpio_set_dir(BTN, GPIO_IN);
  gpio_pull_up(BTN);
  
  gpio_init(PIN_R);
  gpio_set_dir(PIN_R, GPIO_OUT);

  gpio_init(PIN_P);
  gpio_set_dir(PIN_P, GPIO_OUT);

  gpio_init(PIN_B);
  gpio_set_dir(PIN_B, GPIO_OUT);

  gpio_init(PIN_Y);
  gpio_set_dir(PIN_Y, GPIO_OUT);

  while (true) {
    if(!gpio_get(BTN)){
      gpio_put(PIN_R,1);
      sleep_ms(300);
      gpio_put(PIN_R,0);
      gpio_put(PIN_P,1);
      sleep_ms(300);
      gpio_put(PIN_P,0);
      gpio_put(PIN_B,1);
      sleep_ms(300);
      gpio_put(PIN_B,0);
      gpio_put(PIN_Y,1);
      sleep_ms(300);
      gpio_put(PIN_Y,0);
    }
    // Use delay de 300 ms entre os estados!
  }
}
