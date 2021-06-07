#include <LovyanGFX.hpp>
#include <BLEDevice.h>

#include "majoca-lcd.h"
#include "ble-message-characteristic-callbacks.h"

namespace {
    lgfx::LGFX_PARALLEL<LGFX_Config> lcd;
    lgfx::Panel_ILI9342 panel;
    lgfx::LGFX_Sprite buf;

    MajocaLCD majoca_lcd(lcd, buf);
    BLEMessageCharacteristicCallbacks callbacks(majoca_lcd);
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

    majoca_lcd.init(panel);

    BLEDevice::init("ESP32 Majocairis");
    BLEServer* pServer = BLEDevice::createServer();
    BLEService* pService = pServer->createService(BLEUUID(static_cast<uint16_t>(0x6400)));
    BLECharacteristic* pCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6401)), BLECharacteristic::PROPERTY_WRITE);
    pCharacteristic->setCallbacks(&callbacks);

    pService->start();

    BLEAdvertising* pAdvertising = pServer->getAdvertising();
    BLEAdvertisementData advertisement_data;
    advertisement_data.setName("ESP32 Majocairis");
    pAdvertising->setAdvertisementData(advertisement_data);
    pAdvertising->setScanResponse(true);
    pAdvertising->setMinPreferred(0x06);
    pAdvertising->setMinPreferred(0x12);
    pAdvertising->start();

    majoca_lcd.setFont(&fonts::efontJA_24);

    String mac_address(BLEDevice::getAddress().toString().c_str());

    majoca_lcd.drawString("MAC=" + mac_address, 0, 0);
    majoca_lcd.writeLCDBuffer();
}

void loop()
{

}