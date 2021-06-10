#pragma once

#include <Arduino.h>
#include <BLEDevice.h>
#include <LovyanGFX.hpp>

#include "majoca-param.h"

class BLEPositionCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    MajocaParam& _majoca_param;

public:
    BLEPositionCharacteristicCallbacks(MajocaParam& majoca_param) : _majoca_param(majoca_param)
    {

    }

    void onRead(BLECharacteristic* pCharacteristic) override;

    void onWrite(BLECharacteristic* pCharacteristic) override;
};