# Práctica 3 – Procesamiento de datos de una cámara térmica (C++)

## Descripción del proyecto

Este proyecto implementa un sistema distribuido en C++ y Python que procesa datos térmicos simulados. El servidor (Python) genera una matriz de temperaturas, la transmite mediante sockets TCP/IP y el cliente (C++) la recibe, la almacena en estructuras dinámicas y genera un archivo de resultados para su posterior análisis.

Además, se incluye un script en Bash que automatiza la compilación del código C++, la ejecución del servidor en segundo plano y la sincronización de la conexión.

## Estructura del proyecto

El repositorio contiene los siguientes archivos:

* **ServidorCamara.py** → Simulador de la cámara térmica en Python (Servidor).
* **progrC.cpp** → Código fuente del programa receptor en C++ (Cliente).
* **datos_temperaturas.txt** → Archivo generado con las lecturas recibidas.
* **script.sh** → Script Bash para ejecutar el sistema automáticamente.
* **informe.pdf** → Informe detallado con el análisis de los resultados.

## Funcionamiento del programa

El sistema realiza las siguientes tareas de forma coordinada:

1. **Generación de datos:** El servidor crea una secuencia de 768 lecturas (matriz 32x24).
2. **Transmisión de red:** Los datos se empaquetan en formato binario (IEEE 754) y se envían vía TCP.
3. **Recepción en C++:** El cliente recibe los bytes y los reconstruye en tipo `float`.
4. **Almacenamiento:** Los datos se guardan en un `std::vector<float>` de forma dinámica.
5. **Persistencia:** Se genera el archivo `datos_temperaturas.txt` con el volcado de la memoria.

Un paquete se considera **VÁLIDO** si:
* El tamaño total recibido es de exactamente **3072 bytes** (768 datos x 4 bytes).



## Compilación del programa

Para compilar el programa cliente:

```bash
g++ progrC.cpp -o programaC
