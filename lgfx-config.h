#pragma once

#include <Arduino.h>

struct LGFX_Config {
    static constexpr int gpio_wr =  4;
    static constexpr int gpio_rd =  2;
    static constexpr int gpio_rs = 15;
    static constexpr int gpio_d0 = 12;
    static constexpr int gpio_d1 = 13;
    static constexpr int gpio_d2 = 26;
    static constexpr int gpio_d3 = 25;
    static constexpr int gpio_d4 = 17;
    static constexpr int gpio_d5 = 16;
    static constexpr int gpio_d6 = 27;
    static constexpr int gpio_d7 = 14;
};