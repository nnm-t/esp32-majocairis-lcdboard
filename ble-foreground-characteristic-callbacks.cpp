#include "ble-foreground-characteristic-callbacks.h"

void BLEForegroundCharacteristicCallbacks::onRead(BLECharacteristic *pCharacteristic)
{
    uint32_t color = _majoca_param.getForeground();
    pCharacteristic->setValue(color);
}

void BLEForegroundCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    const uint32_t color = valueToColor32(value);

    _majoca_param.setForeground(color);
}