#include <iostream>
#include "lut.hh"
#include "sin_gen.hh"

int main(int argc, char** argv)
{
    // create a sinusoid table
    (void)argc;
    (void)argv;
    ap::SinGen gen;
    ap::Lut sintab(4096, gen);
    auto frame = sintab.next_frame(100, 20);
    for (auto i:frame)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;

}

