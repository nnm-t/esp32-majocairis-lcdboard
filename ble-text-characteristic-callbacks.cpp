#include "ble-text-characteristic-callbacks.h"

void BLETextCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    std::string value = pCharacteristic->getValue();

    _majoca_lcd.drawString(String(value.c_str()), _majoca_param.getPosX(), _majoca_param.getPosY());
    _majoca_lcd.writeLCDBuffer();
}