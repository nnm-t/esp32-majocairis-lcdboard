#pragma once

#include <Arduino.h>
#include <BLEDevice.h>
#include <LovyanGFX.hpp>

#include "majoca-lcd.h"

class BLETextDatumCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    MajocaLCD& _majoca_lcd;

    uint8_t _datum = TL_DATUM;

public:
    BLETextDatumCharacteristicCallbacks(MajocaLCD& majoca_lcd) : _majoca_lcd(majoca_lcd)
    {

    }

    void onRead(BLECharacteristic* pCharacteristic) override;

    void onWrite(BLECharacteristic* pCharacteristic) override;

};