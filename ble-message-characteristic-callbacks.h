#pragma once

#include <Arduino.h>
#include <BLEDevice.h>
#include <LovyanGFX.hpp>

class BLEMessageCharacteristicCallbacks: public BLECharacteristicCallbacks {
    lgfx::LGFX_Sprite& _buffer;

public:
    BLEMessageCharacteristicCallbacks(lgfx::LGFX_Sprite& buffer) : _buffer(buffer)
    {

    }

    void onWrite(BLECharacteristic* pCharacteristic) override;
};