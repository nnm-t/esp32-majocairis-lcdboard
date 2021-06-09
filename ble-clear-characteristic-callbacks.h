#pragma once

#include <Arduino.h>
#include <BLEDevice.h>
#include <LovyanGFX.hpp>

#include "majoca-lcd.h"

class BLEClearCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    MajocaLCD& _majoca_lcd;

public:
    BLEClearCharacteristicCallbacks(MajocaLCD& majoca_lcd) : _majoca_lcd(majoca_lcd)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};