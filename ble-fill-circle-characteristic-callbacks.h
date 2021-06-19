#pragma once

#include <Arduino.h>

#include "ble-coordinate-characteristic-callbacks.h"
#include "majoca-lcd.h"

class BLEFillCircleCharacteristicCallbacks : public BLECoordinateCharacteristicCallbacks
{
    MajocaLCD& _majoca_lcd;
public:
    BLEFillCircleCharacteristicCallbacks(MajocaLCD& majoca_lcd, MajocaParam& majoca_param) : BLECoordinateCharacteristicCallbacks(majoca_param), _majoca_lcd(majoca_lcd)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};