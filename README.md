# ESP32 HomeKit Native Accessory Gateway

![PlatformIO](https://img.shields.io/badge/Platform-PlatformIO-orange)
![Framework](https://img.shields.io/badge/Framework-Arduino%20%7C%20HomeSpan-blue)
![License](https://img.shields.io/badge/License-MIT-green)
![Status](https://img.shields.io/badge/Status-Tested%20on%20Hardware-success)

## 📖 Descripción General

Este proyecto implementa un controlador IoT nativo para el ecosistema **Apple HomeKit** basado en el SoC **ESP32**. Utilizando la librería **HomeSpan**, el dispositivo actúa como un accesorio certificado (HAP - HomeKit Accessory Protocol) sin necesidad de puentes externos (como Homebridge).

El sistema fue diseñado para controlar cargas de potencia (iluminación) y potencialmente monitorear variables ambientales, permitiendo el control total mediante **Siri** y la app **Casa** en iOS.

### 🎯 Objetivo del Proyecto

Desarrollar una solución domótica robusta, económica y segura, aplicando principios de ingeniería electrónica y sistemas embebidos para resolver la integración de hardware DIY con ecosistemas comerciales cerrados.

---

## ⚙️ Características Técnicas (Key Features)

- **Integración Nativa HAP:** Comunicación directa con dispositivos Apple sin servidores intermedios, reduciendo la latencia.
- **Aprovisionamiento WiFi Dinámico:** Configuración de credenciales de red mediante CLI (Command Line Interface), eliminando el hardcoding de contraseñas.
- **Persistencia de Datos (NVS):** El sistema recuerda el último estado de los actuadores tras cortes de energía.
- **Control por Voz y App:** Soporte completo para comandos de Siri y automatizaciones de Apple Home.
- **Arquitectura Modular:** Código estructurado en C++ separando la lógica de red, hardware y servicios de HomeKit.
- **Feedback de Estado Real:** Sincronización bidireccional; si el dispositivo se activa físicamente, la app se actualiza instantáneamente.

---

## 🛠️ Hardware y Tecnologías

### Componentes

- **Microcontrolador:** ESP32 DevKit V1
- **Seguridad:** Interruptor Termomagnético (ITM) 16A / DZ47 - 63
- **Actuadores:** Módulo Relé de 5V (Optoacoplado para aislamiento galvánico o con conmutación a transistor HW-482) & Contactor Magnético de 15A (LC1D1810)
- **Alimentación:** Fuente regulada 5V/3.3V/2A (DPS3010U / HW131)

### Stack de Software

- **IDE:** PlatformIO (VS Code)
- **Lenguaje:** C++ (Standard 11/17 features)
- **Framework:** Arduino Core for ESP32
- **Librerías Clave:** HomeSpan (HAP Implementation)

---

## 🚀 Instalación y Uso

1.  **Clonar el repositorio:**
    ```bash
    git clone [https://github.com/angel-pascual/ESP32_IOT_SIRI.git](https://github.com/angel-pascual/ESP32_IOT_SIRI.git)
    ```
2.  **Abrir en PlatformIO:**
    Abrir la carpeta del proyecto en VS Code con la extensión PlatformIO instalada.
3.  **Compilar y Subir:**
    Conectar el ESP32 y ejecutar la tarea "Upload".
4.  **Configuración Inicial:**
    - Abrir el Monitor Serie (Baud Rate 115200).
    - Escribir `W` para configurar el WiFi.
    - Escribir `A` para iniciar el emparejamiento con HomeKit.
5.  **Emparejamiento:**
    Escanear el código QR (visible en logs) o ingresar el código manual en la App Casa (Código default: 466-37-726).

---

## 🧠 Competencias Demostradas (Skills)

Este proyecto pone en práctica las siguientes habilidades de ingeniería:

- **Sistemas Embebidos:** Manejo de GPIOs, interrupciones y comunicación Serial.
- **Protocolos IoT:** Entendimiento práctico de WiFi (802.11) y la capa de aplicación HAP.
- **C++ Moderno:** Uso de Clases, Objetos y Punteros para la gestión de servicios HomeKit.
- **Depuración (Debugging):** Uso de logs seriales para traza de errores y validación de estados.
- **Git & Version Control:** Gestión correcta de ramas y exclusión de archivos binarios.

---

## 🤖 Uso de Herramientas de IA

Para el desarrollo de este proyecto, se utilizaron herramientas de IA (LLMs) como soporte para:

- Generación de _boilerplate code_ repetitivo.
- Optimización de sintaxis C++.
- Consultas rápidas sobre documentación de la librería HomeSpan.

**Nota:** Toda la lógica de control, el diseño del circuito y la validación final del hardware fueron realizados y supervisados manualmente para garantizar la fiabilidad del sistema.

---

### Autor

**Angel Luis Pascual Trujillo**
Estudiante de Ingeniería Electrónica
[www.linkedin.com/in/angel-luis-pascual-trujillo-73b5b1337]
