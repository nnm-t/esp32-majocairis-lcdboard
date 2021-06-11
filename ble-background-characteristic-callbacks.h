#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "majoca-param.h"

class BLEBackgroundCharacteristicCallbacks : public BLECharacteristicCallbacks
{
    MajocaParam& _majoca_param;
public:
    BLEBackgroundCharacteristicCallbacks(MajocaParam& majoca_param) : _majoca_param(majoca_param)
    {

    }

    void onRead(BLECharacteristic* pCharacteristic) override;

    void onWrite(BLECharacteristic* pCharacteristic) override;
};