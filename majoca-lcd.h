#pragma once

#include <Arduino.h>
#include <LovyanGFX.hpp>

#include "lgfx-config.h"

class MajocaLCD
{

    lgfx::LGFX_PARALLEL<LGFX_Config>& _lcd;
    lgfx::LGFX_Sprite& _buf;
public:
    MajocaLCD(lgfx::LGFX_PARALLEL<LGFX_Config>& lcd, lgfx::LGFX_Sprite& buf) : _lcd(lcd), _buf(buf)
    {

    }

    void init(lgfx::Panel_ILI9342& panel, const uint8_t color_depth = 16, const uint8_t rotation = 0);

    void drawString(const char* string, int32_t x, int32_t y);
    void drawString(String& string, int32_t x, int32_t y);
    void drawString(String string, int32_t x, int32_t y);
    void drawString(StringSumHelper string, int32_t x, int32_t y);

    void setTextDatum(const uint8_t datum);
    void setFont(const lgfx::v0::IFont* font);

    void drawRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h);
    void fillRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h);

    void drawCircle(const int32_t, const int32_t y, const int32_t r);
    void fillCircle(const int32_t, const int32_t y, const int32_t r);

    void fillScreen(const uint32_t color);

    void clear();

    void writeLCDBuffer();
};