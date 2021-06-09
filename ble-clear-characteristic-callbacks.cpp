#include "ble-clear-characteristic-callbacks.h"

void BLEClearCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    _majoca_lcd.clear();
    _majoca_lcd.writeLCDBuffer();
}