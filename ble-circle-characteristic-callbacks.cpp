#include "ble-circle-characteristic-callbacks.h"

void BLECircleCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    const int32_t radius = value[0] << 8 + value[1];
    
    _majoca_lcd.drawCircle(_majoca_param.getPosX(), _majoca_param.getPosY(), radius);
    _majoca_lcd.writeLCDBuffer();
}