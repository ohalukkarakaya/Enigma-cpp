#include <iostream>

#include "development/include/print_usage.h"
#include "model/include/enigma.h"

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printUsage();
        return 1;
    }

    std::string message = argv[1];
    std::string operation = argv[2];

    std::vector<int> rotorPositions = {0, 0, 0};
    std::vector<int> ringSettings = {0, 0, 0};
    std::vector<std::pair<char, char>> plugboardSettings;

    for (int i = 3; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "--rotors" && i + 1 < argc) {
            std::string rotorsArg = argv[++i];
            sscanf(rotorsArg.c_str(), "%d,%d,%d", &rotorPositions[0], &rotorPositions[1], &rotorPositions[2]);
        } else if (arg == "--ring" && i + 1 < argc) {
            std::string ringArg = argv[++i];
            sscanf(ringArg.c_str(), "%d,%d,%d", &ringSettings[0], &ringSettings[1], &ringSettings[2]);
        } else if (arg == "--plugboard" && i + 1 < argc) {
            std::string plugArg = argv[++i];
            for (size_t j = 0; j < plugArg.size(); j += 3) {
                if (j + 1 < plugArg.size() && plugArg[j + 2] == ',') {
                    plugboardSettings.emplace_back(plugArg[j], plugArg[j + 1]);
                }
            }
        }
    }

    // mesajı büyük harflere çevir ve boşlukları '-' ile değiştir
    std::transform(message.begin(), message.end(), message.begin(), ::toupper);
    std::replace(message.begin(), message.end(), ' ', '-');

    // Rotor, reflector ve plugboard ayarları
    Rotor rotor1("EKMFLGDQVZNTOWYHXUSPAIBRCJ", 'Q', ringSettings[0]);
    Rotor rotor2("AJDKSIRUXBLHWTMCQGZNPYFVOE", 'E', ringSettings[1]);
    Rotor rotor3("BDFHJLCPRTXVZNYEIWGAKMUSQO", 'V', ringSettings[2]);
    Reflector reflector("YRUHQSLDPXNGOKMIEBFZCWVJAT");

    Plugboard plugboard;
    for (const auto& plug : plugboardSettings) {
        plugboard.addPlug(plug.first, plug.second);
    }

    Enigma enigma({rotor1, rotor2, rotor3}, reflector, plugboard);
    enigma.setRotorPositions(rotorPositions);

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
        printUsage();
        return 1;
    }

    return 0;
}
