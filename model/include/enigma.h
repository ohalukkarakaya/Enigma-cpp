#ifndef ENIGMA_H
#define ENIGMA_H

#include "rotor.h"
#include "plugboard.h"
#include "reflector.h"

class Enigma {
public:
    Enigma(const std::vector<Rotor> &rotors, const Reflector &reflector, const Plugboard &plugboard)
        : rotors(rotors), reflector(reflector), plugboard(plugboard) {}

    void setRotorPositions(const std::vector<int> &positions);
    std::string encrypt(const std::string &message);

private:
    std::vector<Rotor> rotors;
    Reflector reflector;
    Plugboard plugboard;

    char processCharacter(char c);
    void rotateRotors();
};

#endif //ENIGMA_H
