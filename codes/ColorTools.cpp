/*

#include "Arduino.h"
#include "ColorTools.h"
#include <Adafruit_TCS34725.h>

void ColorTools::ScanColors(){

  uint16_t clear, red, green, blue, colorTemp, lux; // Variables de recoleccion de datos \\

        tcs.setInterrupt(false);      // prende el LED \\

        delay(60);  // Toma 60 ms para leer

        tcs.getRawData(&red, &green, &blue, &clear); //recolecta los Rawdata \\

        tcs.setInterrupt(true);  // Apaga el LED \\
  
}
*/
