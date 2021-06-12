#include "ble-position-characteristic-callbacks.h"

void BLEPositionCharacteristicCallbacks::onRead(BLECharacteristic* pCharacteristic)
{
    const int32_t x = _majoca_param.getPosX();
    const int32_t y = _majoca_param.getPosY();
    uint8_t* data = toData(x, y);
    pCharacteristic->setValue(data, sizeof(data));
}

void BLEPositionCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    const int32_t x = valueToX(value);
    const int32_t y = valueToY(value);
    _majoca_param.setPosX(x);
    _majoca_param.setPosY(y);
}