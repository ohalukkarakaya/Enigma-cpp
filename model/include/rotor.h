#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>

class Rotor
{
public:
    Rotor(const std::string &wiring, char notch, int ringSetting = 0)
        : wiring(wiring), notch(notch), ringSetting(ringSetting), position(0) {}

    char encryptForward(char input);
    char encryptBackward(char input);
    void rotate();
    bool atNotch();
    void setPosition(int pos);

private:
    std::string wiring;
    char notch;
    int position;
    int ringSetting;
};

#endif //ROTOR_H
