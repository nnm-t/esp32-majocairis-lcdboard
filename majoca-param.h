#pragma once

#include <Arduino.h>
#include <LovyanGFX.hpp>

class MajocaParam
{
    int32_t _pos_x = 0;
    int32_t _pos_y = 0;

    uint32_t _background = 0x000000;
    uint32_t _foreground = 0xFFFFFF;

public:
    MajocaParam()
    {

    }

    const int32_t getPosX();

    const int32_t getPosY();

    const uint32_t getBackground();

    const uint32_t getForeground();

    void setPosX(const int32_t x);

    void setPosY(const int32_t y);

    void setBackground(const uint32_t color);

    void setForeground(const uint32_t color);
};