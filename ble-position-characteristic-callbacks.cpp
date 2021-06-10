#include "ble-position-characteristic-callbacks.h"

void BLEPositionCharacteristicCallbacks::onRead(BLECharacteristic* pCharacteristic)
{
    const int32_t x = _majoca_param.getPosX();
    const int32_t y = _majoca_param.getPosY();
    uint8_t data[] = {
        static_cast<uint8_t>((x >> 8) & 0xFF),
        static_cast<uint8_t>(x & 0xFF),
        static_cast<uint8_t>((y >> 8) & 0xFF),
        static_cast<uint8_t>(y & 0xFF)
    };
    pCharacteristic->setValue(data, sizeof(data));
}

void BLEPositionCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    const int32_t x = (value[0] << 8) + value[1];
    const int32_t y = (value[2] << 8) + value[3];
    _majoca_param.setPosX(x);
    _majoca_param.setPosY(y);
}