#include <LovyanGFX.hpp>

namespace {
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

    lgfx::LGFX_PARALLEL<LGFX_Config> lcd;
    lgfx::Panel_ILI9342 panel;

    lgfx::LGFX_Sprite buf;
}

void setup()
{
    panel.freq_write = 16000000;
    panel.len_dummy_read_pixel = 8;

    panel.spi_cs = 33;
    panel.spi_dc = -1;
    panel.gpio_rst = 32;

    panel.gpio_bl = -1;
    panel.pwm_ch_bl = -1;
    panel.backlight_level = true;

    panel.memory_width = 320;
    panel.memory_height = 240;

    panel.panel_width = 320;
    panel.panel_height = 96;

    panel.offset_x = 0;
    panel.offset_y = 144;

    panel.rotation = 0;
    panel.offset_rotation = 0;

    lcd.setPanel(&panel);
    lcd.init();
    lcd.setColorDepth(16);
    lcd.setRotation(0);

    buf.setColorDepth(16);
    buf.createSprite(640, 48);
    buf.setSwapBytes(true);

    buf.setFont(&fonts::efontJA_16);
    buf.drawString("hello world", 0, 0);
    buf.drawString("こんにちは世界", 320, 0);
}

void loop()
{
    writeLcdBuffer();
}

void writeLcdBuffer()
{
    lcd.setAddrWindow(0, 0, 320, 96);
    lcd.pushPixels((lgfx::swap565_t*) buf.getBuffer(), 640 * 48);
}