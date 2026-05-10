import socket
import struct

HOST = '127.0.0.1'
PORT = 12345

# Generamos 768 temperaturas. 
# float() para  que el tipo de dato sea el correcto.
data_array = [float(i % 256) for i in range(768)]

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
    server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server_socket.bind((HOST, PORT))
    server_socket.listen()
    print(f"Servidor listo. Enviando temperaturas en formato float...")

    conn, addr = server_socket.accept()
    with conn:
        # '768f' significa: empaqueta 768 números como floats (4 bytes cada uno)
        # Esto suma un total de 3072 bytes enviados.
        data_bytes = struct.pack('768f', *data_array)
        conn.sendall(data_bytes)
        print("Lecturas enviadas con éxito.")