#include "../include/reflector.h"

char Reflector::reflect(char input) const
{
    return wiring[input - 'A'];
}