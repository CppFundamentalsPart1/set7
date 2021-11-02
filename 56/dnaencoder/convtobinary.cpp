#include "dnaencoder.ih"

bool DnaEncoder::convToBinary(std::ifstream &in, std::ofstream &out) const
{
    out.put(s_magicHeader);

    if (in.peek() == s_magicHeader)  // input already binary
    {
        copyFile(in, out);
        return false;
    }

    char bases[4];
    char numRead;
    while (true)
    {
        in.read(bases, sizeof(bases));

        if (!in.gcount())
            break;

        numRead = in.gcount();

        char binary;
        if (!getBinary(bases, &binary))  // character that was not A, T, C or
                                         // G
            return false;

        out.put(binary);
    }

    out.put(numRead);

    return true;
}
