#ifndef _DNA_ENCODER_H_
#define _DNA_ENCODER_H_

#include <iosfwd>

class DnaEncoder
{
    static char const s_magicHeader = 109; // used to indicate file is binary
public:
    static bool convToBinary(std::ifstream &in, std::ofstream &out);
    static bool convToText(std::ifstream &in, std::ofstream &out);

private:
    static void copyFile(std::ifstream &in, std::ofstream &out);

    static void getChars(char val, char ret[4]);
    static bool getBinary(char const bases[4], char *dest);
};

#endif  // _DNA_ENCODER_H_