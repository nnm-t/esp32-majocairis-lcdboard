#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "ble-coordinate-characteristic-callbacks.h"

class BLEPositionCharacteristicCallbacks : public BLECoordinateCharacteristicCallbacks
{
public:
    BLEPositionCharacteristicCallbacks(MajocaParam& majoca_param) : BLECoordinateCharacteristicCallbacks(majoca_param)
    {

    }

    void onRead(BLECharacteristic* pCharacteristic) override;

    void onWrite(BLECharacteristic* pCharacteristic) override;
};