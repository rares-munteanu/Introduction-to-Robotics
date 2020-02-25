#ifndef PROGMEM_READ_H
#define PROGMEM_READ_H

#include <Arduino.h>  // for type definitions

//Functions to read any data type from PROGMEM
template <typename T> void PROGMEM_read(const T* sce, T& dest)
{
  memcpy_P(&dest, sce, sizeof(T));
}

template <typename T> T PROGMEM_get(const T* sce)
{
  static T temp;
  memcpy_P(&temp, sce, sizeof(T));
  return temp;
}

#endif
