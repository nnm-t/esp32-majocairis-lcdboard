#include "ble-rect-characteristic-callbacks.h"

void BLERectCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    // 上位2bytes: 幅
    // 下位2bytes: 高さ
    uint8_t* value = pCharacteristic->getData();
    int32_t width = valueToX(value);
    int32_t height = valueToY(value);

    _majoca_lcd.drawRect(_majoca_param.getPosX(), _majoca_param.getPosY(), width, height);
    _majoca_lcd.writeLCDBuffer();
}