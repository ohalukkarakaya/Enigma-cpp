#include "../include/plugboard.h"

void Plugboard::addPlug(char a, char b)
{
    connections[a] = b;
    connections[b] = a;
}

char Plugboard::swap(char input) const
{
    if (connections.count(input)) {
        return connections.at(input);
    }

    return input;
}