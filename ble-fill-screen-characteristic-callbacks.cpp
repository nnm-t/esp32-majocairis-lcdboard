#include "ble-fill-screen-characteristic-callbacks.h"

void BLEFillScreenCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
    uint8_t* value = pCharacteristic->getData();
    _majoca_lcd.fillScreen(valueToColor32(value));
}