#include "ble-fill-rect-characteristic-callbacks.h"

void BLEFillRectCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    int32_t width = valueToX(value);
    int32_t height = valueToY(value);

    _majoca_lcd.fillRect(_majoca_param.getPosX(), _majoca_param.getPosY(), width, height);
    _majoca_lcd.writeLCDBuffer();
}