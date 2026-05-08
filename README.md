# Práctica 3 – Procesamiento de datos de una cámara térmica (C++)

## Descripción del proyecto

Este proyecto implementa un sistema distribuido en C++ y Python diseñado para procesar datos térmicos simulados. El servidor (Python) emula el funcionamiento de una cámara térmica generando una matriz de temperaturas y transmitiéndola mediante sockets TCP/IP. El cliente (C++) actúa como receptor, almacenando la información en estructuras dinámicas, procesando los bytes y generando un archivo de resultados.

Además, se incluye un script en Bash que automatiza la compilación del código C++, la ejecución sincronizada del servidor en segundo plano y la gestión de la conexión de red.

## Estructura del proyecto

El repositorio contiene los siguientes archivos:

* **ServidorCamara.py** → Simulador de la cámara térmica en Python (Servidor)
* **progrC.cpp** → Código fuente del programa receptor en C++ (Cliente)
* **datos_temperaturas.txt** → Archivo generado con los resultados de las lecturas
* **script.sh** → Script Bash para ejecutar el sistema automáticamente
* **informe.pdf** → Informe explicativo con el análisis de la práctica

## Funcionamiento del programa

El programa realiza las siguientes tareas de forma coordinada:

1. **Establece conexión:** El cliente conecta al servidor mediante sockets TCP/IP en el puerto 12345
2. **Recepción de flujo binario:** El programa C++ recibe los datos como bytes crudos
3. **Conversión de datos:** Transforma los bytes recibidos en tipo `float` (32 bits) siguiendo el estándar IEEE 754
4. **Almacenamiento dinámico:** Guarda las lecturas en un `std::vector<float>` conforme llegan por la red
5. **Genera el archivo datos_temperaturas.txt:** Realiza el volcado de la memoria al disco duro

Un paquete de datos se considera **VÁLIDO** si:
* El tamaño total recibido es de exactamente **3072 bytes** (correspondiente a 768 lecturas de 4 bytes cada una).

## Compilación del programa

Para compilar el programa cliente:
`g++ progrC.cpp -o programaC`

## Ejecución del programa

Ejecutar directamente (requiere servidor activo):
`./programaC`

## Ejecución mediante script Bash

1. **Dar permisos de ejecución:**
`chmod +x script.sh`

2. **Ejecutar el script:**
`./script.sh`

El script realiza:
* **Compilación** automática del código fuente C++
* **Ejecución del servidor** Python en segundo plano (simulando el sensor)
* **Espera de sincronización** de 2 segundos para asegurar la apertura del puerto
* **Ejecución del cliente** C++ para capturar la telemetría
* **Finalización controlada** de todos los procesos activos al terminar

## Archivo de entrada

Al ser un sistema distribuido, la entrada es un flujo de red generado por **ServidorCamara.py**:
* **Formato:** Stream binario de números de punto flotante
* **Resolución:** 768 puntos de lectura (matriz de 32x24)

## Archivo de salida

El programa genera:
**datos_temperaturas.txt**

## Requisitos del sistema

Sistema operativo Linux, Compilador compatible con C++ (g++ recomendado), Intérprete de Python 3.x, Bash disponible en el sistema o WSL instalado en el sistema.

---
*Grado en Tecnologías Digitales para la Empresa*
