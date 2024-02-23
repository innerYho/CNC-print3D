#include <Arduino.h>
// Compiar y pegar todas las líneas en src/main.cpp despues de crear un projecto para probar los motores
//  Prueba Shield ramp CNC, driver, motor de paso y arduino uno
//  Vídeo 3/17 https://www.youtube.com/watch?v=eRcqiVBZPQM&list=PLnwu2s7SIakR-0Gs5vAO_1sfWDOy9mBE0&index=3
//  tool Board Arduino uno

// Como usar una fuente de poder / voltaje AC-DC
// https://www.youtube.com/watch?v=yp_LRDPkP-Y

#define x_paso 2 // Define el pin de step para motor de eje X    //x stp 2
#define x_dire 5 // Define el pin de Dir para motor de eje X    //x dir 5
#define x_habi 8 // Define el pin Enable para motor de eje X

#define y_paso 3 // y stp 3
#define y_dire 6 // y dir 6
#define y_habi 8 // y lim 10

#define z_paso 4 // z stp 4
#define z_dire 7 // z dir 7
#define z_habi 8 // z lim 11
// int giro[] = {0, 0, 0};

// #define E0_paso 26
// #define E0_dire 28
// #define E0_habi 24

// #define E1_paso 36
// #define E1_dire 34
// #define E1_habi 30
int retardo = 3000; // Número menor el giro es más rápido
int tiempo = 500;   // Vueltas: durante cuanto tiempo da el giro

void setup()
{
    pinMode(x_paso, OUTPUT);
    pinMode(x_dire, OUTPUT);
    pinMode(x_habi, OUTPUT);
    pinMode(y_paso, OUTPUT);
    pinMode(y_dire, OUTPUT);
    pinMode(y_habi, OUTPUT);
    pinMode(z_paso, OUTPUT);
    pinMode(z_dire, OUTPUT);
    pinMode(z_habi, OUTPUT);
    // pinMode(E0_paso, OUTPUT); pinMode(E0_dire, OUTPUT); pinMode(E0_habi, OUTPUT);
    // pinMode(E1_paso, OUTPUT); pinMode(E1_dire, OUTPUT); pinMode(E1_habi, OUTPUT);
}

void giro(int paso_, int dire_, int habi_)
{
    digitalWrite(habi_, LOW); // Habilita el Driver
    digitalWrite(dire_, LOW); // Dirección de giro 1
    for (int i = 0; i < tiempo; i++)
    { // da pasos por un tiempo
        digitalWrite(paso_, HIGH);
        delayMicroseconds(retardo);
        digitalWrite(paso_, LOW);
        delayMicroseconds(retardo);
    }
    digitalWrite(dire_, HIGH); // Dirección de giro 2
    for (int i = 0; i < tiempo; i++)
    { // da pasos por un tiempo
        digitalWrite(paso_, HIGH);
        delayMicroseconds(retardo);
        digitalWrite(paso_, LOW);
        delayMicroseconds(retardo);
    }
    digitalWrite(habi_, HIGH); // Quita la habilitación del driver
    delay(1000);
}

void loop()
{
    giro(x_paso, x_dire, x_habi);
    giro(y_paso, y_dire, y_habi);
    giro(z_paso, z_dire, z_habi);
    // giro(E0_paso, E0_dire, E0_habi);
    // giro(E1_paso, E1_dire, E1_habi);
}