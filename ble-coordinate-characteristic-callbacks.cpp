#include "ble-coordinate-characteristic-callbacks.h"

uint8_t* BLECoordinateCharacteristicCallbacks::toData(const uint32_t x, const uint32_t y)
{
    uint8_t data[] = {
        static_cast<uint8_t>((x >> 8) & 0xFF),
        static_cast<uint8_t>(x & 0xFF),
        static_cast<uint8_t>((y >> 8) & 0xFF),
        static_cast<uint8_t>(y & 0xFF)
    };
    return data;
}

const int32_t BLECoordinateCharacteristicCallbacks::valueToX(uint8_t* value)
{
    return (value[0] << 8) + value[1];
}

const int32_t BLECoordinateCharacteristicCallbacks::valueToY(uint8_t* value)
{
    return (value[2] << 8) + value[3];
}