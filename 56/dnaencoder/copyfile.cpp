#include "dnaencoder.ih"

void DnaEncoder::copyFile(std::ifstream &in, std::ofstream &out) const
{
    //return to the beginning of both streams
    in.seekg(0);
    out.seekp(0);

    out << in.rdbuf();
}
