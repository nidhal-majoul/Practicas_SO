#!/usr/bin/env bash

# Paso 1: Compilación del cliente
echo "Compilando cliente C++..."
g++ cliente.cpp -o programaC

# Paso 2: Ejecutar el servidor en segundo plano
echo "Lanzando servidor de simulación..."
python3 ServidorCamara.py &
PID_SERVER=$!

# Espera de seguridad para que el servidor abra el puerto
sleep 2

# Paso 3: Ejecutar el cliente 
echo "Ejecutando cliente y descargando datos..."
./programaC

echo "------------------------------------------"
# Paso 4: Finalizar el servidor si sigue abierto
if kill -0 $PID_SERVER 2>/dev/null; then
    echo "Cerrando el servidor..."
    kill -TERM $PID_SERVER
else
    echo "El servidor finalizó su tarea correctamente."
fi

echo "Proceso completado con éxito."