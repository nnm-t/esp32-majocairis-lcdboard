#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "ble-color-characteristic-callbacks.h"

class BLEForegroundCharacteristicCallbacks : public BLEColorCharacteristicCallbacks
{
public:
    BLEForegroundCharacteristicCallbacks(MajocaParam& majoca_param) : BLEColorCharacteristicCallbacks(majoca_param)
    {

    }

    void onRead(BLECharacteristic* pCharacteristic) override;

    void onWrite(BLECharacteristic* pCharacteristic) override;
};