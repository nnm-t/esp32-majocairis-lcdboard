#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "majoca-lcd.h"

#include "ble-color-characteristic-callbacks.h"

class BLEFillScreenCharacteristicCallbacks : public BLEColorCharacteristicCallbacks
{
    MajocaLCD& _majoca_lcd;

public:
    BLEFillScreenCharacteristicCallbacks(MajocaLCD& majoca_lcd, MajocaParam& majoca_param) : BLEColorCharacteristicCallbacks(majoca_param), _majoca_lcd(majoca_lcd)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};