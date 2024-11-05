#include "../include/rotor.h"

char Rotor::encryptForward(char input)
{
   int index = (input - 'A' + position - ringSetting + 26) % 26;
   char output = wiring[index];

   return (output - 'A' - position + ringSetting + 26) % 26 + 'A';
}

char Rotor::encryptBackward(char input)
{
   int index = (input - 'A' + position - ringSetting + 26) % 26;
   index = wiring.find('A' + index);

   return (index - position + ringSetting + 26) % 26 + 'A';
}

void Rotor::rotate()
{
    position = (position + 1) % 26;
}

bool Rotor::atNotch()
{
    return wiring[position] == notch;
}

void Rotor::setPosition(int pos)
{
    position = pos % 26;
}