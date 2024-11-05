#include "../include/enigma.h"

void Enigma::setRotorPositions(const std::vector<int> &positions)
{
    for (size_t i = 0; i < rotors.size(); ++i)
    {
        rotors[i].setPosition(positions[i]);
    }
}

std::string Enigma::encrypt(const std::string &message)
{
    std::string encryptedMessage;
    for (char c : message)
    {
        if (c >= 'A' && c <= 'Z')
        {
            encryptedMessage += processCharacter(c);
            rotateRotors();
        }
        else
        {
            encryptedMessage += c;
        }
    }

    return encryptedMessage;
}

char Enigma::processCharacter(char c)
{
    // Plugboard
    char encryptedChar = plugboard.swap(c);

    // Rotorların ileri geçişi
    for (Rotor &rotor : rotors)
    {
        encryptedChar = rotor.encryptForward(encryptedChar);
    }

    // Reflector
    encryptedChar = reflector.reflect(encryptedChar);

    // Rotorların geri geçişi
    for (auto it = rotors.rbegin(); it != rotors.rend(); ++it)
    {
        encryptedChar = it->encryptBackward(encryptedChar);
    }

    // Plugboard
    encryptedChar = plugboard.swap(encryptedChar);

    return encryptedChar;
}

void Enigma::rotateRotors()
{
    bool rotateNext = true;
    for (Rotor &rotor : rotors)
    {
        if (rotateNext)
        {
            rotor.rotate();
            rotateNext = rotor.atNotch();
        }
        else
        {
            break;
        }
    }
}
