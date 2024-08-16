#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int PIN_R = 4;
const int PIN_G = 6;
const int BTN_PIN_R = 28;
const int BTN_PIN_G = 26;

int main() {
  stdio_init_all();

  gpio_init(PIN_R);
  gpio_set_dir(PIN_R, GPIO_OUT);

  gpio_init(PIN_G);
  gpio_set_dir(PIN_G, GPIO_OUT);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  while (true) {
    if(!gpio_get(BTN_PIN_G)){
      int status = !gpio_get(PIN_G);
      gpio_put(PIN_G, status);
      while (!gpio_get(BTN_PIN_G)){
      }
    }
    if(!gpio_get(BTN_PIN_R)){
      int status = !gpio_get(PIN_R);
      gpio_put(PIN_R, status);
      while (!gpio_get(BTN_PIN_R)){
      }
    }
  }
}
