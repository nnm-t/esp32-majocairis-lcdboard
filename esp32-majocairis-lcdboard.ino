#include <LovyanGFX.hpp>
#include <BLEDevice.h>

#include "ble-text-characteristic-callbacks.h"
#include "ble-background-characteristic-callbacks.h"
#include "ble-foreground-characteristic-callbacks.h"
#include "ble-rect-characteristic-callbacks.h"
#include "ble-fill-rect-characteristic-callbacks.h"
#include "ble-fill-screen-characteristic-callbacks.h"
#include "ble-clear-characteristic-callbacks.h"
#include "ble-position-characteristic-callbacks.h"

namespace {
    lgfx::LGFX_PARALLEL<LGFX_Config> lcd;
    lgfx::Panel_ILI9342 panel;
    lgfx::LGFX_Sprite buf;

    MajocaLCD majoca_lcd(lcd, buf);
    MajocaParam majoca_param;

    BLEPositionCharacteristicCallbacks positionCallbacks(majoca_param);
    BLEForegroundCharacteristicCallbacks foregroundCallbacks(majoca_param);
    BLEBackgroundCharacteristicCallbacks backgroundCallbacks(majoca_param);
    BLETextCharacteristicCallbacks textCallbacks(majoca_lcd, majoca_param);
    BLERectCharacteristicCallbacks rectCallbacks(majoca_lcd, majoca_param);
    BLEFillRectCharacteristicCallbacks fillRectCallbacks(majoca_lcd, majoca_param);
    BLEFillScreenCharacteristicCallbacks fillScreenCallbacks(majoca_lcd, majoca_param);
    BLEClearCharacteristicCallbacks clearCallbacks(majoca_lcd);

    BLEDescriptor positionDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor foregroundDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor backgroundDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor textDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor rectDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor fillRectDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor fillScreenDesceriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
    BLEDescriptor clearDescriptor(BLEUUID(static_cast<uint16_t>(0x2901)));
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
    BLEService* pService = pServer->createService(BLEUUID(static_cast<uint16_t>(0x6400)), 31);

    // 始点座標
    BLECharacteristic* pPositionCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6401)), BLECharacteristic::PROPERTY_WRITE);
    pPositionCharacteristic->setCallbacks(&positionCallbacks);
    positionDescriptor.setValue("Position");
    pPositionCharacteristic->addDescriptor(&positionDescriptor);
    // 色
    BLECharacteristic* pForegroundCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6402)), BLECharacteristic::PROPERTY_WRITE);
    pForegroundCharacteristic->setCallbacks(&foregroundCallbacks);
    foregroundDescriptor.setValue("Foreground");
    pForegroundCharacteristic->addDescriptor(&foregroundDescriptor);
    // 背景色
    BLECharacteristic* pBackgroundCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6403)), BLECharacteristic::PROPERTY_WRITE);
    pBackgroundCharacteristic->setCallbacks(&backgroundCallbacks);
    backgroundDescriptor.setValue("Background");
    pBackgroundCharacteristic->addDescriptor(&backgroundDescriptor);

    // 文字列
    BLECharacteristic* pTextCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6411)), BLECharacteristic::PROPERTY_WRITE);
    pTextCharacteristic->setCallbacks(&textCallbacks);
    textDescriptor.setValue("Text");
    pTextCharacteristic->addDescriptor(&textDescriptor);
    // 文字列原点
    BLECharacteristic* pTextDatumCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6412)), BLECharacteristic::PROPERTY_WRITE);

    // 四角 (サイズ)
    BLECharacteristic* pRectCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6421)), BLECharacteristic::PROPERTY_WRITE);
    pRectCharacteristic->setCallbacks(&rectCallbacks);
    rectDescriptor.setValue("Rect");
    pRectCharacteristic->addDescriptor(&rectDescriptor);
    // 塗りつぶし四角 (サイズ)
    BLECharacteristic* pFillRectCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6422)), BLECharacteristic::PROPERTY_WRITE);
    pFillRectCharacteristic->setCallbacks(&fillRectCallbacks);
    fillRectDescriptor.setValue("Fill Rect");
    pFillRectCharacteristic->addDescriptor(&fillRectDescriptor);
    // 円 (半径)
    BLECharacteristic* pCircleCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6423)), BLECharacteristic::PROPERTY_WRITE);
    // 円 (終点半径)
    BLECharacteristic* pFillCircleCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x6424)), BLECharacteristic::PROPERTY_WRITE);

    // 背景塗りつぶし (色)
    BLECharacteristic* pFillScreenCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x64F1)), BLECharacteristic::PROPERTY_WRITE);
    pFillScreenCharacteristic->setCallbacks(&fillScreenCallbacks);
    fillScreenDesceriptor.setValue("Fill Screen");
    pFillScreenCharacteristic->addDescriptor(&fillScreenDesceriptor);
    // スクロール
    BLECharacteristic* pScrollCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x64F2)), BLECharacteristic::PROPERTY_WRITE);
    // 消去
    BLECharacteristic* pClearCharacteristic = pService->createCharacteristic(BLEUUID(static_cast<uint16_t>(0x64FF)), BLECharacteristic::PROPERTY_WRITE);
    pClearCharacteristic->setCallbacks(&clearCallbacks);
    clearDescriptor.setValue("Clear");
    pClearCharacteristic->addDescriptor(&clearDescriptor);

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

    String esp_chip_model(ESP.getChipModel());
    String esp_frequency(ESP.getCpuFreqMHz(), DEC);
    String esp_flash_size(ESP.getFlashChipSize() / 1024, DEC);
    majoca_lcd.drawString(esp_chip_model + " / " + esp_frequency + "MHz / " + esp_flash_size + "KB", 0, 24);

    majoca_lcd.writeLCDBuffer();
}

void loop()
{

}