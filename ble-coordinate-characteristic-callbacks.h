#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "majoca-param.h"

class BLECoordinateCharacteristicCallbacks : public BLECharacteristicCallbacks
{
protected:
    MajocaParam& _majoca_param;

    uint8_t* toData(const uint32_t x, const uint32_t y);

    const int32_t valueToX(uint8_t* value);
    const int32_t valueToY(uint8_t* value);

public:
    BLECoordinateCharacteristicCallbacks(MajocaParam& majoca_param) : _majoca_param(majoca_param)
    {

    }
};