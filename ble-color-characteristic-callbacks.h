#pragma once

#include <Arduino.h>
#include <BLEDevice.h>

#include "majoca-param.h"

class BLEColorCharacteristicCallbacks : public BLECharacteristicCallbacks
{
protected:
    MajocaParam& _majoca_param;

    const uint32_t valueToColor32(uint8_t* value);

public:
    BLEColorCharacteristicCallbacks(MajocaParam& majoca_param) : _majoca_param(majoca_param)
    {

    }
};