#include "sin_gen.hh"
#include "common.hh"
#include <cmath>

namespace ap
{
    void SinGen::generate(SampleBuf& table_buffer)
    {
        int size{table_buffer.size()};
        auto p = PI/size;
        for (auto i{0}; i<size; i++)
        {
            table_buffer[i] = sin(p*i);
        }
    }
}
