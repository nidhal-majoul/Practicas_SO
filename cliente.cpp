#include <iostream>
#include <vector>
#include <arpa/inet.h>
#include <unistd.h>
#include <fstream>
#include <cstring>

using namespace std;

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        return 1;
    }

    vector<float> temperaturas;
    float buffer; // Variable de 4 bytes para recibir cada float
    
    // Recibimos los datos. recv devolverá 4 bytes cada vez.
    while (recv(sockfd, &buffer, sizeof(buffer), 0) > 0) {
        temperaturas.push_back(buffer);
    }

    // Guardado y muestra de datos
    ofstream archivo("datos_temperaturas.txt");
    for (float t : temperaturas) {
        archivo << t << endl;
        cout << t << endl; // Un número por línea
    }
    archivo.close();

    close(sockfd);
    return 0;
}
