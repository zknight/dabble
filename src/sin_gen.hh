#ifndef AP_SIN_GEN_HH
#   define AP_SIN_GEN_HH
#include "table_generator.hh"

namespace ap
{
    class SinGen : public TableGenerator
    {
        public:
            void generate(SampleBuf& table_buffer);
    };
}
#endif

