#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "lut.hh"
#include "sin_gen.hh"
#include "fft/kiss_fftr.h"

double stdbl(const std::string& s)
{
    std::istringstream iss(s);
    double v{0.0};
    iss >> v;
    return v;

}
int main(int argc, char** argv)
{
    // create a sinusoid table
    double freq{220.0};
    int framesz{100};
    std::cout << argc << std::endl;

    if (argc == 3)
    {
        framesz = stdbl(argv[1]);
        freq = stdbl(argv[2]);
    }
    std::cout << "Using: framesz=" << framesz << " freq=" << freq << std::endl;

    ap::SinGen gen;
    ap::Lut sintab(8192, gen);
    auto frame = sintab.next_frame(framesz, freq);

    kiss_fftr_cfg kcfg = kiss_fftr_alloc(4096, 0, 0, 0);
    kiss_fft_cpx data[4096] = {0, 0};
    kiss_fftr(kcfg, &frame[0], data);
    double binstep = 44100.0/4096;
    double bin = 0.0;
    std::ofstream of;
    of.open("spec.csv");
    for (auto i(0); i<2048; i++)
    {
        auto magsqr = sqrt(data[i].r*data[i].r + data[i].i*data[i].i)/2048;
        auto db = 20*log10(magsqr);
        //std::cout << "(" <<  data[i].r << "," << data[i].r << ")\n";
        of << bin << "," << db << "\n";
        bin += binstep;
    }
    of.close();
#if 0
    for (auto i:frame)
    {
        std::cout << i << "\n";
    }
#endif
    std::cout << std::endl;
    return 0;

}

