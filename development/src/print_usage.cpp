#include "../include/print_usage.h"

void printUsage()
{
    std::cout << "Kullanım: ./enigma <mesaj> --encrypt veya --decrypt "
              << "--rotors <rotor_positions> --ring <ring_settings> "
              << "--plugboard <plug_connections>" << std::endl;

    std::cout << std::endl;

    std::cout << "Örnek: ./enigma YAŞASIN_CUMHURİYET! --encrypt --rotors 1,2,3 --ring 0,0,0 --plugboard AB,CD" << std::endl;
}
