#pragma once

#include <Arduino.h>
#include <BLEDevice.h>
#include <LovyanGFX.hpp>

#include "majoca-lcd.h"
#include "majoca-param.h"

class BLERectCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    MajocaLCD& _majoca_lcd;
    MajocaParam& _majoca_param;

public:
    BLERectCharacteristicCallbacks(MajocaLCD& majoca_lcd, MajocaParam& majoca_param) : _majoca_lcd(majoca_lcd), _majoca_param(majoca_param)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};