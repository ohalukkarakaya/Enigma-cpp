#include <iostream>

#include "model/include/enigma.h"

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Kullanım: ./enigma <mesaj> --encrypt veya --decrypt" << std::endl;
        return 1;
    }

    // rotor, reflector ve plugboard
    Rotor rotor1("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q'); // Rotor I
    Rotor rotor2("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E'); // Rotor II
    Rotor rotor3("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V'); // Rotor III
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT"); // Reflector B

    // plugboard ayarları
    Plugboard plugboard;
    plugboard.addPlug('A', 'B');
    plugboard.addPlug('C', 'D');

    // enigma makinesini başlat
    Enigma enigma({rotor1, rotor2, rotor3}, reflector, plugboard);

    std::string message = argv[1];
    std::string operation = argv[2];

    // mesajı büyük harflere çevir ve boşlukları '-' ile değiştir
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    std::replace(message.begin(), message.end(), ' ', '-');

    // rotor başlangıç pozisyonlarını ayarla
    enigma.setRotorPositions({0, 0, 0});

    if (operation == "--encrypt")
    {
        std::string encryptedMessage = enigma.encrypt(message);
        std::cout << "Şifreli mesaj: " << encryptedMessage << std::endl;
    }
    else if (operation == "--decrypt")
    {
        std::string decryptedMessage = enigma.encrypt(message);
        std::cout << "Çözülen mesaj: " << decryptedMessage << std::endl;
    }
    else
    {
        std::cerr << "Geçersiz işlem. '--encrypt' veya '--decrypt' kullanın." << std::endl;
        return 1;
    }

    return 0;
}
