#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <iostream>

class Reflector
{
public:
    Reflector(const std::string &wiring) : wiring(wiring) {}

    char reflect(char input) const;

private:
    std::string wiring;
};

#endif //REFLECTOR_H
