#pragma once
#include <stdint.h>

const char* to_string(uint64_t value);
const char* to_string(int64_t value);
const char* to_hex_string(uint64_t value);
const char* to_hex_string(uint32_t value);
const char* to_hex_string(uint16_t value);
const char* to_hex_string(uint8_t value);
const char* to_string(double value, uint8_t decimalPlaces);
const char* to_string(double value);