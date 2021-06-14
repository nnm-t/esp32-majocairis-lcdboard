#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "majoca-lcd.h"
#include "ble-coordinate-characteristic-callbacks.h"

class BLEFillRectCharacteristicCallbacks : public BLECoordinateCharacteristicCallbacks
{
    MajocaLCD& _majoca_lcd;

public:
    BLEFillRectCharacteristicCallbacks(MajocaLCD& majoca_lcd, MajocaParam& majoca_param) : BLECoordinateCharacteristicCallbacks(majoca_param), _majoca_lcd(majoca_lcd)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};