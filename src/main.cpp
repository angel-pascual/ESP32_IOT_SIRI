#include <Arduino.h>
#include <HomeSpan.h>

// --- HARDWARE ---
// Definimos los pines donde se conectarán el Relé (o LED) u otro dispositivo
#define PIN_KT 26
#define PIN_FOCO 25

// --- ESTRUCTURA DEL OBJETO (Servicio)---
// En HomeSpan, no se escriben funciones sueltas. Se crea una "Clase"
// que representa a un dispositivo.
// Basado en la estructura POO.

struct LucesHabitacion : Service::LightBulb
{

  // Puntero para controlar el estado (On/Off)
  SpanCharacteristic *activacion;

  // 1. CONSTRUCTOR: Se ejecuta una sola vez al arrancar
  LucesHabitacion(int pin) : Service::LightBulb()
  {
    power = pin;            // Guardamos el pin
    pinMode(power, OUTPUT); // Lo configuramos como salida

    // Creamos la característica "On" (Encendido/Apagado) de HomeKit
    activacion = new Characteristic::On();
  }

  // 2. EL CEREBRO (Callback): Se ejecuta cuando Siri manda una orden
  boolean update() override
  {

    // Preguntamos: ¿Siri quiere encender (true) o apagar (false)?
    bool deseo = activacion->getNewVal();

    if (deseo == true)
    {
      digitalWrite(power, HIGH);
      Serial.println("Siri dijo: Encendido!");
    }
    else
    {
      digitalWrite(power, LOW);
      Serial.println("Siri dijo: Apagado");
    }

    return true; // Confirmamos a Siri que la orden se cumplió
  }

  // Variable interna para guardar el número de pin
  int power;
};

struct ActuadoresHabitacion : Service::Switch
{
  SpanCharacteristic *potencia;

  ActuadoresHabitacion(int pin) : Service::Switch()
  {
    power = pin;            // Guardamos el pin
    pinMode(power, OUTPUT); // Lo configuramos como salida

    potencia = new Characteristic::On();
  }

  boolean update() override
  {

    bool deseo = potencia->getNewVal();

    if (deseo == true)
    {
      digitalWrite(power, HIGH);
      Serial.println("Siri dijo: Encendido!");
    }
    else
    {
      digitalWrite(power, LOW);
      Serial.println("Siri dijo: Apagado");
    }

    return true; // Confirmamos a Siri que la orden se cumplió
  }

  // Variable interna para guardar el número de pin
  int power;
};

// --- Configuración Inicial ---
void setup()
{
  Serial.begin(115200);

  // Iniciamos HomeSpan
  // Category::Le dice al iPhone que el icono sea el dispositivo asignado
  homeSpan.begin(Category::Bridges, "PLC ESP32", "ESP32-MOD"); // Bridge = HUB

  // Construimos los Accesorios Virtuales
  // Dispositivo #1:
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new Characteristic::Name("Contactor Magnético"); // Nombre en la App Casa
  new Characteristic::Manufacturer("angel-pascual");
  new Characteristic::SerialNumber("123-ABC");
  new Characteristic::Model("Relé-industrial");
  new Characteristic::FirmwareRevision("1.0");

  // Estructura atribuida a cada objeto (Motor del objeto)
  new ActuadoresHabitacion(PIN_KT);

  // Dispositivo #2:
  new SpanAccessory();
  new Service::AccessoryInformation();
  new Characteristic::Identify();
  new Characteristic::Name("Foco LED"); // Nombre en la App Casa
  new Characteristic::Manufacturer("angel-pascual");
  new Characteristic::SerialNumber("789-xyz");
  new Characteristic::Model("ESP32-Pro");
  new Characteristic::FirmwareRevision("1.0");

  new LucesHabitacion(PIN_FOCO);
}

void loop()
{
  // Mantiene encendido el WiFi y escucha a Apple.
  homeSpan.poll();
}