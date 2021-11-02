#include "dnaencoder.ih"

bool DnaEncoder::convToText(std::ifstream &in, std::ofstream &out) const
{
    if (in.get() != s_magicHeader)
        return false;  // no magic header so no human readable input

    char byte = in.get();
    char nextByte = in.get();

    if (!in)
        return false;  // file was too short

    char bases[4];
    while (true)
    {
        getChars(byte, bases);

        if (in.peek() == EOF)
        {
            out.write(bases, nextByte);
            break;
        }

        out.write(bases, sizeof(bases));

        byte = nextByte;
        nextByte = in.get();
    }

    return true;
}
