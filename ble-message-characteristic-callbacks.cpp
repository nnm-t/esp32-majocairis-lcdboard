#include "ble-message-characteristic-callbacks.h"

void BLEMessageCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    std::string value = pCharacteristic->getValue();

    _buffer.drawString(String(value.c_str()), 0, 0);
}