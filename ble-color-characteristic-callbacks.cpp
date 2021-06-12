#include "ble-color-characteristic-callbacks.h"

const uint32_t BLEColorCharacteristicCallbacks::valueToColor32(uint8_t* value)
{
    return (value[0] << 16) + (value[1] << 8) + value[2];
}