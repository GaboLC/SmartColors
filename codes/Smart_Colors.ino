// librerias \\

#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <RTCZero.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "runmean.h"

// variables hsv \\

float saturacion, valor;
int tono;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_1X); // 101MS

//Display Oled

#define OLED_RESET 3
Adafruit_SSD1306 display(OLED_RESET);

// Variables identificacion de color \\

String color = "Ningun color         escaneado";
int ROJO, VERDE, AZUL;

// Variables RTC

// Cambiar estos valores para fijar el tiempo actual \\
byte seconds = 0;
byte minutes = 0;
byte hours = 0;

/* Cambiar estos valores para fijar la fecha inicial */
const byte day = 1;
const byte month = 1;
const byte year = 1;

// variables cambio hora \\

int estado_hora = 0, estado_minuto = 0, estado_segundo = 0, estado_dia = 0, estado_mes = 0, estado_year = 0;

RTCZero rtc; // Se crea un objeto RTC

// Botones \\

const int Button_Menu = 2;
const int Button_accion = 4;

// variables menu \\

int modo = 0;
const int N = 9;

// algoritmo runmean \\

#define NVALUES 10

TrunMean runMean(NVALUES);

void setup() {

  SerialUSB.begin(9600);

  tcs.begin();

  tcs.setInterrupt(true);

  display.clearDisplay();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);

  display.display();
  display.clearDisplay();

  /* Reloj */

  rtc.begin(); //Inicializa el RTC

  /* Define la hora */

  rtc.setTime(hours, minutes, estado_segundo);
  rtc.setDate(day, month, year);

  pinMode(Button_accion, INPUT);
  pinMode(Button_Menu, INPUT);

}

void loop() {

  if (digitalRead(Button_Menu) == LOW) { //cambio de pantalla \\

    modo++;
    modo = modo % N;

    while (digitalRead(2) == LOW) {
    }
  }

  switch (modo) { // switch para cada pantalla \\

    case 1: // Reloj \\

      // Fecha \\

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(40, 2);
      print2digits(rtc.getDay());
      display.print("/");
      print2digits(rtc.getMonth());
      display.print("/");
      print2digits(rtc.getYear());
      display.print(" ");

      //hora

      if (rtc.getHours() >= 0 && rtc.getHours() <= 24) {

        if (rtc.getHours() >= 1 && rtc.getHours() <= 12) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          print2digits(rtc.getHours());
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("AM");

          display.display();
          display.clearDisplay();

        }

        else if (rtc.getHours() == 13) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("01");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 14) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("02");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 15) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("03");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 16) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("04");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 17) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("05");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 18) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("06");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 19) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("07");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 20) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("08");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 21) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("09");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 22) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("10");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }
        else if (rtc.getHours() == 23) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("11");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("PM");

          display.display();
          display.clearDisplay();

        }


        else if (rtc.getHours() == 00) {

          display.setTextSize(4);
          display.setCursor(5, 20);
          display.print("12");
          display.print(":");
          print2digits(rtc.getMinutes());

          display.setTextSize(2);
          display.setCursor(52, 50);
          print2digits(rtc.getSeconds());

          display.setTextSize(1);
          display.setCursor(115, 2);
          //display.setTextColor(BLACK, WHITE);
          display.print("AM");

          display.display();
          display.clearDisplay();

        }

      }

      /*


        //Debug clock

        // Muestra la fecha
        SerialUSB.println(" ");
        print2digits(rtc.getDay());
        SerialUSB.print("/");
        print2digits(rtc.getMonth());
        SerialUSB.print("/");
        print2digits(rtc.getYear());
        SerialUSB.println(" ");

        // ...Y el tiempo
        print2digits(rtc.getHours());
        SerialUSB.print(":");
        print2digits(rtc.getMinutes());
        SerialUSB.print(":");
        print2digits(rtc.getSeconds());
        SerialUSB.println(" ");

      */

      break;

    case 2: // Color Mode \\

      display.display();
      display.clearDisplay();

      display.setCursor(0, 0);
      display.println("El color escanado es:");
      display.setCursor(0, 10);
      display.println(color);
      display.setCursor(0, 30);
      display.println("valor RGB es: ");
      display.setCursor(0, 40);
      display.print("R: "); display.print((int)ROJO); display.print(" G: "); display.print((int)VERDE); display.print(" B: "); display.print((int)AZUL);

      if (digitalRead(Button_accion) == LOW) {

        uint16_t clear, red, green, blue, colorTemp, lux; // Variables de recoleccion de datos \\

        tcs.setInterrupt(false);      // prende el LED \\

        delay(60);  // Toma 60 ms para leer

        tcs.getRawData(&red, &green, &blue, &clear); //recolecta los Rawdata \\

        tcs.setInterrupt(true);  // Apaga el LED \\

        // Conversion de valores RGB raw a RGB estandar \\

        uint32_t sum = clear;
        float rojo, verde, azul;
        rojo = red; rojo /= sum;
        verde = green; verde /= sum;
        azul = blue; azul /= sum;
        rojo *= 256; verde *= 256; azul *= 256;
        ROJO = rojo; VERDE = verde; AZUL = azul;

        //colorTemp = tcs.calculateColorTemperature(rojo, verde, azul); // calcula la temperatura del color \\

        //lux = tcs.calculateLux(rojo, verde, azul); // calcula la luminosidad \\

        // Convertir de RGB a HSV

        //primer paso
        float r = rojo / 255.0, g = verde / 255.0, b = azul / 255.0;

        //segundo paso
        float cMax = max(max(r, g), b);
        float cMin = min(min(r, g), b);

        //tercer paso
        float delta = cMax - cMin;
        int16_t tono;

        //calculo de tono (h)
        if (delta > 0) {

          if (cMax == r) {
            tono = 60 * (fmod(((g - b) / delta), 6));
          }

          else if (cMax == g) {
            tono = 60 * (((b - r) / delta) + 2);
          }

          else if (cMax == b) {
            tono = 60 * (((r - g) / delta) + 4);
          }

        }

        else {
          tono = 0;
        }


        //calculo de saturación (s)
        if (cMax != 0) {

          saturacion = delta / cMax;

        }

        else if (cMax == 0) {

          saturacion = 0;

        }


        //calculo del valor (V)
        valor = cMax;                  // variabes HSV = tono, saturacion, valor

        // Determinar el color \\

        if (tono >= 0 && tono <= 360) {

          if (tono >= 0 && tono <= 15) { //rojo

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);
            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Rojo");
            color = "Rojo";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();

          }
          else if (tono >= 16 && tono <= 44) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);
            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Naranja");
            color = "Naranja";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }
          else if (tono >= 45 && tono <= 89) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);
            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Amarillo");
            color = "Amarillo";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }
          else if (tono >= 90 && tono <= 149) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);
            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Verde");
            color = "verde";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }
          else if (tono >= 150 && tono <= 224) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);
            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Cyan");
            color = "Cyan";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }
          else if (tono >= 225 && tono <= 269) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);
            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Azul");
            color = "Azul";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }
          else if (tono >= 270 && tono <= 230) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);

            display.setCursor(0, 0);
            display.println("El color escaneado es:");
            display.setCursor(0, 10);
            display.println("Magenta");
            color = "Magenta";
            display.setCursor(0, 30);
            display.println("valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }
          else if (tono >= 231 && tono <= 360) {

            display.display();
            display.clearDisplay();

            display.setTextSize(1);
            display.setTextColor(WHITE);

            display.setCursor(0, 0);
            display.println("El color escaneado es: ");
            display.setCursor(0, 10);
            display.println("Violeta");
            color = "Violeta";
            display.setCursor(0, 30);
            display.println("Valor RGB es: ");
            display.setCursor(0, 40);
            display.print("R: "); display.print((int)rojo); display.print(" G: "); display.print((int)verde); display.print(" B: "); display.print((int)azul);

            display.display();

            delay(5000);

            display.display();
            display.clearDisplay();
          }

        }
        else {

          display.display();
          display.clearDisplay();

          display.setCursor(0, 0);
          display.println("Error");

          display.display();

          delay(5000);

          display.display();
          display.clearDisplay();
        }

        /*

          //Debug

          SerialUSB.println(digitalRead(2));

          SerialUSB.println(" ");
          SerialUSB.println("----------------------------------------");
          SerialUSB.println(" ");


          SerialUSB.print("Valores RGB crudos: "); SerialUSB.print("C: "); SerialUSB.print(clear);
          SerialUSB.print(" - R:"); SerialUSB.print(red);
          SerialUSB.print(" - G: "); SerialUSB.print(green);
          SerialUSB.print(" - B: "); SerialUSB.print(blue);
          SerialUSB.println(" ");
          SerialUSB.println(" ");

          SerialUSB.print("Valor Hexadecimal: "); SerialUSB.print((int)rojo, HEX); SerialUSB.print((int)verde, HEX); SerialUSB.print((int)azul, HEX);
          SerialUSB.println(" ");
          SerialUSB.println(" ");

          SerialUSB.print("Valores RGB convertidos: "); SerialUSB.print((int)rojo); SerialUSB.print(" "); SerialUSB.print((int)verde); SerialUSB.print(" "); SerialUSB.print((int)azul);

          SerialUSB.println(" ");
          SerialUSB.println(" ");

          SerialUSB.print("Valores HSV: "); SerialUSB.print("H: "); SerialUSB.print(tono); SerialUSB.print(" - S: "); SerialUSB.print(saturacion); SerialUSB.print("- V: "); SerialUSB.print(valor);

          SerialUSB.println(" ");
          SerialUSB.println(" ");

          SerialUSB.print("Temperatura del color: "); SerialUSB.print(colorTemp, DEC);

          SerialUSB.println(" ");
          SerialUSB.println(" ");

          SerialUSB.print("Lux: "); SerialUSB.print(lux, DEC);

          SerialUSB.println(" ");
          SerialUSB.println(" ");

        */
      }

      break;

    case 3: // horas config \\

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(8, 2);

      display.print("Configuracion hora");

      if (estado_hora <= 9) {

        display.display();
        display.clearDisplay();

        display.drawRect(2, 15, 50, 1, WHITE); // (posicion X, posicion Y, Tamaño X, tamaño Y) \\

        //display.display();
        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print("0"); display.print(estado_hora);
        display.print(":");

      }
      else {

        display.display();
        display.clearDisplay();

        display.drawRect(2, 15, 50, 1, WHITE); // (posicion X, posicion Y, Tamaño X, tamaño Y) \\

        //display.display();
        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print(estado_hora);
        display.print(":");

      }
      if (estado_minuto <= 9) {

        display.print("0");  display.print(estado_minuto);

      }
      else {

        display.print(estado_minuto);

      }
      if (estado_segundo <= 9) {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print("0"); display.print(estado_segundo);

      }
      else {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print(estado_segundo);

      }

      if (digitalRead(Button_accion) == LOW) {


        estado_hora++;
        estado_hora =  estado_hora % 24;

        rtc.setHours(estado_hora);

        delay(10);

      }

      break;

    case 4: // minutos config \\ 

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(8, 2);

      display.print("Configuracion hora");

      if (estado_hora <= 9) {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print("0"); display.print(estado_hora);
        display.print(":");

      }
      else {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print(estado_hora);
        display.print(":");

      }
      if (estado_minuto <= 9) {

        display.drawRect(74, 15, 50, 1, WHITE);
        display.print("0");  display.print(estado_minuto);

      }
      else {

        display.drawRect(74, 15, 50, 1, WHITE);
        display.print(estado_minuto);

      }
      if (estado_segundo <= 9) {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print("0"); display.print(estado_segundo);

      }
      else {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print(estado_segundo);

      }


      if (digitalRead(Button_accion) == LOW) {


        estado_minuto++;
        estado_minuto =  estado_minuto % 60;

        rtc.setMinutes(estado_minuto);

        delay(10);

      }

      break;

    case 5: // Seconds config \\

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(8, 2);

      display.print("Configuracion hora");

      if (estado_hora <= 9) {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print("0"); display.print(estado_hora);
        display.print(":");

      }
      else {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print(estado_hora);
        display.print(":");

      }
      if (estado_minuto <= 9) {

        display.print("0");  display.print(estado_minuto);

      }
      else {

        display.print(estado_minuto);

      }
      if (estado_segundo <= 9) {

        display.drawRect(49, 48, 28, 1, WHITE);
        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print("0"); display.print(estado_segundo);

      }
      else {

        display.drawRect(49, 48, 28, 1, WHITE);
        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print(estado_segundo);

      }


      if (digitalRead(Button_accion) == LOW) {


        estado_segundo++;
        estado_segundo =  estado_segundo % 60;

        rtc.setSeconds(estado_segundo);

        delay(10);

      }

      break;

    case 6: // Day config \\

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(5, 2);

      display.print("Configuracion fecha");

      if (estado_dia <= 9) {

        display.display();
        display.clearDisplay();

        display.drawRect(2, 15, 50, 1, WHITE);
        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print("0"); display.print(estado_dia);
        display.print("/");

      }
      else {

        display.display();
        display.clearDisplay();

        display.drawRect(2, 15, 50, 1, WHITE);
        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print(estado_dia);
        display.print("/");

      }
      if (estado_mes <= 9) {

        display.print("0");  display.print(estado_mes);

      }
      else {

        display.print(estado_mes);

      }
      if (estado_year <= 9) {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print("0"); display.print(estado_year);

      }
      else {


        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print(estado_year);

      }

      if (digitalRead(Button_accion) == LOW) {


        estado_dia++;
        estado_dia =  estado_dia % 32;

        rtc.setDate(estado_dia, estado_mes, estado_year);

        delay(10);

      }

      break;

    case 7: // Month config \\

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(5, 2);

      display.print("Configuracion fecha");

      if (estado_dia <= 9) {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print("0"); display.print(estado_dia);
        display.print("/");

      }
      else {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print(estado_dia);
        display.print("/");

      }
      if (estado_mes <= 9) {

        display.drawRect(74, 15, 50, 1, WHITE);
        display.print("0");  display.print(estado_mes);

      }
      else {

        display.drawRect(74, 15, 50, 1, WHITE);
        display.print(estado_mes);

      }
      if (estado_year <= 9) {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print("0"); display.print(estado_year);

      }
      else {

        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print(estado_year);

      }

      if (digitalRead(Button_accion) == LOW) {


        estado_mes++;
        estado_mes =  estado_mes % 13;

        rtc.setDate(estado_dia, estado_mes, estado_year);

        delay(10);

      }

      break;

    case 8: // Year config \\

      display.setTextSize(1);
      display.setTextColor(WHITE);

      display.setCursor(5, 2);

      display.print("Configuracion fecha");

      if (estado_dia <= 9) {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print("0"); display.print(estado_dia);
        display.print("/");

      }
      else {

        display.display();
        display.clearDisplay();

        display.setTextSize(4);
        display.setCursor(5, 20);
        display.print(estado_dia);
        display.print("/");

      }
      if (estado_mes <= 9) {

        display.print("0");  display.print(estado_mes);

      }
      else {

        display.print(estado_mes);

      }
      if (estado_year <= 9) {

        display.drawRect(49, 48, 28, 1, WHITE);
        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print("0"); display.print(estado_year);

      }
      else {

        display.drawRect(49, 48, 28, 1, WHITE);
        display.setTextSize(2);
        display.setCursor(52, 50);
        display.print(estado_year);

      }

      if (digitalRead(Button_accion) == LOW) {


        estado_year++;
        estado_year %= 31;

        rtc.setDate(estado_dia, estado_mes, estado_year);

        delay(10);

      }

      break;

  }

}


void print2digits(int number) {
  if (number < 10) {
    display.print("0"); // Muestra un 0 delante del numero si < 10 \\
    //SerialUSB.print("0");
  }

  display.print(number);
  //SerialUSB.print(number);
}
