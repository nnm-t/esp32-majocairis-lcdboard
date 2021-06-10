#pragma once

#include <Arduino.h>
#include <LovyanGFX.hpp>

class MajocaParam
{
    int32_t _pos_x = 0;
    int32_t _pos_y = 0;

public:
    MajocaParam()
    {

    }

    const int32_t getPosX();

    const int32_t getPosY();

    void setPosX(const int32_t x);

    void setPosY(const int32_t y);
};