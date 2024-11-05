#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <iostream>
#include <map>

class Plugboard {
public:
    void addPlug(char a, char b);

    char swap(char input) const;

private:
    std::map<char, char> connections;
};

#endif //PLUGBOARD_H
