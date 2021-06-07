#include "ble-message-characteristic-callbacks.h"

void BLEMessageCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    std::string value = pCharacteristic->getValue();

    _majoca_lcd.drawString(String(value.c_str()), 0, 0);
    _majoca_lcd.writeLCDBuffer();
}