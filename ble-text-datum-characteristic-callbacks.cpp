#include "ble-text-datum-characteristic-callbacks.h"

void BLETextDatumCharacteristicCallbacks::onRead(BLECharacteristic* pCharacteristic)
{
	pCharacteristic->setValue(&_datum, sizeof(_datum));
}

void BLETextDatumCharacteristicCallbacks::onWrite(BLECharacteristic* pCharacteristic)
{
	uint8_t* value = pCharacteristic->getData();
	_datum = value[0];
}