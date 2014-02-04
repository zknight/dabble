#include "sin_gen.hh"
#include "common.hh"
#include <cmath>

namespace ap
{
    void SinGen::generate(SampleBuf& table_buffer)
    {
        auto size = table_buffer.size();
        auto p = PI/size;
        for (unsigned int i(0); i<size; i++)
        {
            table_buffer[i] = sin(p*i);
        }
    }
}
