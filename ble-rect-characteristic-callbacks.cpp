#include "ble-rect-characteristic-callbacks.h"

void BLERectCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    // 上位2bytes: 幅
    // 下位2bytes: 高さ
    uint8_t* data = pCharacteristic->getData();
    int32_t width = static_cast<int32_t>(data[0]) << 8 + data[1];
    int32_t height = static_cast<int32_t>(data[2]) << 8 + data[3];

    _majoca_lcd.drawRect(_majoca_param.getPosX(), _majoca_param.getPosY(), width, height);
    _majoca_lcd.writeLCDBuffer();
}