// how deplify and omqr feels being gay

#include <iostream>
#include <string>
#include <random>

std::string generarRandom(int longitud) {
    const std::string caracteres =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "!@#$%^&*";

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, caracteres.size() - 1);

    std::string resultado;
    for (int i = 0; i < longitud; i++) {
        resultado += caracteres[dist(gen)];
    }

    return resultado;
}

int main() {
    int longitud = 16;

    std::string randomStr = generarRandom(longitud);

    std::cout << "Random generado: " << randomStr << std::endl;

    return 0;
}
