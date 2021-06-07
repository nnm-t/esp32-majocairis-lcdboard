#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "majoca-lcd.h"

class BLEMessageCharacteristicCallbacks: public BLECharacteristicCallbacks {
    MajocaLCD& _majoca_lcd;

public:
    BLEMessageCharacteristicCallbacks(MajocaLCD& majoca_lcd) : _majoca_lcd(majoca_lcd)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};