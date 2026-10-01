 
# Arduino_7SegmentDisplay_Controller

## Descripción
Este proyecto proporciona una guía completa para controlar un display de 7 segmentos utilizando una placa Arduino. Los displays de 7 segmentos son componentes esenciales en muchos dispositivos electrónicos, permitiendo la visualización de números y algunos caracteres alfanuméricos. Este repositorio incluye el código necesario, esquemas de conexión y ejemplos prácticos para aprender y desarrollar proyectos que incorporen este tipo de dispositivos.

El propósito principal de este proyecto es ayudar tanto a principiantes como a usuarios avanzados a implementar este componente de forma rápida y efectiva, ya sea en proyectos educativos o aplicaciones reales como relojes digitales, contadores, o termómetros.

---

## Características
- **Control flexible**: Compatible con displays de cátodo común y ánodo común.
- **Modularidad**: Fácil de integrar con otros sensores o módulos (como botones, potenciómetros, o controladores 74HC595).
- **Ejemplos prácticos**: Incluye múltiples demostraciones listas para cargar en tu Arduino.
- **Código reutilizable**: Diseñado para ser adaptable a proyectos más complejos con múltiples displays o funciones avanzadas.

---

## Requisitos
### Hardware:
- **Placa Arduino**: Compatible con Arduino UNO, Mega, Nano, etc.
- **Display de 7 segmentos**: Cátodo común o ánodo común.
- **Resistencias**: 330Ω para proteger los pines del Arduino.
- **Cables de conexión**: Jumper (macho-macho o macho-hembra).
- **Protoboard**: Para realizar las conexiones de forma ordenada.

### Software:
- **Arduino IDE**: Descárgalo desde [Arduino IDE](https://www.arduino.cc/en/software).
- **Librerías opcionales**:
  - `ShiftRegister74HC595.h` si utilizas controladores de desplazamiento para manejar múltiples displays.

---

## Instalación
1. **Clona este repositorio**:
   ```bash
   git clone https://github.com/usuario/Arduino_7SegmentDisplay_Controller.git
   ```
2. **Abre el archivo del código**:
   - Abre el archivo `.ino` en el IDE de Arduino.
3. **Configura los pines**:
   - Asegúrate de que los pines definidos en el código coincidan con tu esquema de conexión.
4. **Carga el código**:
   - Conecta tu Arduino a la computadora y utiliza el botón "Subir" en el IDE de Arduino.

---

## Esquema de Conexión
El siguiente esquema describe cómo conectar un display de 7 segmentos de **cátodo común** al Arduino. Consulta también el archivo `diagram.png` para un diagrama más detallado.

| Segmento | Pin del Display | Pin de Arduino | Resistencia |
|----------|------------------|----------------|-------------|
| A        | 1                | D2             | 330Ω        |
| B        | 2                | D3             | 330Ω        |
| C        | 4                | D4             | 330Ω        |
| D        | 5                | D5             | 330Ω        |
| E        | 6                | D6             | 330Ω        |
| F        | 7                | D7             | 330Ω        |
| G        | 8                | D8             | 330Ω        |
| DP (opcional) | 9            | D9             | 330Ω        |

> **Nota**: Si utilizas un display de ánodo común, conecta el pin común al voltaje positivo (5V) en lugar de tierra (GND).

---

## Uso
### Pasos básicos:
1. Conecta el hardware siguiendo el esquema de conexión anterior.
2. Carga el código proporcionado en el repositorio a tu Arduino.
3. Observa cómo el display de 7 segmentos muestra números en secuencia del 0 al 9.

### Personalización:
- Modifica el código para cambiar los patrones o valores mostrados.
- Integra sensores, botones u otros dispositivos para añadir interacción al proyecto.

---

## Ejemplos de Uso
### 1. Contador Secuencial
El display muestra números del 0 al 9 en un bucle continuo con un retraso de 1 segundo entre cada número. Este ejemplo es perfecto para aprender cómo activar cada segmento del display.

### 2. Contador con Botón
Conecta un botón al Arduino y utiliza el código para incrementar manualmente el número mostrado en el display cada vez que presiones el botón.

### 3. Termómetro Básico
Conecta un sensor de temperatura como el LM35 y muestra la temperatura medida directamente en el display.

### 4. Reloj Digital
Usa un módulo RTC (Real Time Clock) como el DS3231 para mostrar la hora actual en tiempo real.

---

## Recursos Adicionales
- [Documentación de Arduino](https://www.arduino.cc/)
- [Guía de Displays de 7 Segmentos](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds)
- [Controlador 74HC595](https://www.arduino.cc/en/Tutorial/ShiftOut)
- [Configuración de Pines en Arduino](https://www.arduino.cc/en/Reference/PinMode)

---

## Contribuciones
¡Contribuir es bienvenido! Si deseas proponer nuevas características, mejorar el código o corregir errores, abre un _pull request_ o crea un _issue_ en este repositorio.

---

## Licencia
Este proyecto está licenciado bajo la Licencia MIT. Consulta el archivo `LICENSE` para más detalles. 