#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "ble-color-characteristic-callbacks.h"

class BLEBackgroundCharacteristicCallbacks : public BLEColorCharacteristicCallbacks
{
public:
    BLEBackgroundCharacteristicCallbacks(MajocaParam& majoca_param) : BLEColorCharacteristicCallbacks(majoca_param)
    {

    }

    void onRead(BLECharacteristic* pCharacteristic) override;

    void onWrite(BLECharacteristic* pCharacteristic) override;
};