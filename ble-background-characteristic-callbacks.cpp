#include "ble-background-characteristic-callbacks.h"

void BLEBackgroundCharacteristicCallbacks::onRead(BLECharacteristic* pCharacteristic)
{
    uint32_t color = _majoca_param.getBackground();
    pCharacteristic->setValue(color);
}

void BLEBackgroundCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    const uint32_t color = valueToColor32(value);
    _majoca_param.setBackground(color);
}