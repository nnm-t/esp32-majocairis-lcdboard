#include "majoca-lcd.h"

void MajocaLCD::init(lgfx::Panel_ILI9342& panel, const uint8_t color_depth, const uint8_t rotation)
{
    _lcd.setPanel(&panel);
    _lcd.init();
    _lcd.setColorDepth(color_depth);
    _lcd.setRotation(rotation);

    _buf.setColorDepth(color_depth);
    _buf.createSprite(640, 48);
    _buf.setSwapBytes(true);
}

void MajocaLCD::drawString(const char* string, int32_t x, int32_t y)
{
    _buf.drawString(string, x, y);
}

void MajocaLCD::drawString(String& string, int32_t x, int32_t y)
{
    _buf.drawString(string, x, y);
}

void MajocaLCD::drawString(String string, int32_t x, int32_t y)
{
    _buf.drawString(string, x, y);
}

void MajocaLCD::drawString(StringSumHelper string, int32_t x, int32_t y)
{
    _buf.drawString(string, x, y);
}

void MajocaLCD::setFont(const lgfx::v0::IFont* font)
{
    _buf.setFont(font);
}

void MajocaLCD::drawRect(const int32_t x, const int32_t y, const int32_t w, const int32_t h)
{
    _buf.drawRect(x, y, w, h);
}

void MajocaLCD::clear()
{
    _buf.clear();
}

void MajocaLCD::writeLCDBuffer()
{
    _lcd.setAddrWindow(0, 0, 320, 96);
    _lcd.pushPixels((lgfx::swap565_t*) _buf.getBuffer(), 640 * 48);
}