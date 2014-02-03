#ifndef AP_LUT_HH
#   define AP_LUT_HH

#include "table_generator.hh"

namespace ap
{
    class Lut
    {
        public:
            Lut() : m_size{0} {};
            Lut(int size) : m_size{size}, m_lut(size) {}
            Lut(int size, TableGenerator& generator); 

            void size(int size) { m_size = size; m_lut.resize(size); }
            int size() { return m_size; }

            void samplerate(double rate) { m_fs = rate; }
            double samplerate() { return m_fs; }

            /// Fill the lut using the supplied generator
            /// @param generator TableGenerator 
            void fill(TableGenerator& generator);

            SampleBuf next_frame(int framesize, double frequency);
            

        protected:
            // given phase, return index bound by length of lut
            int index(double x)
            {
                return static_cast<int>(x) % m_size;
            }
            // TODO: delete copy/assignment ?
            int m_size;
            double m_fs{44100.0};
            double m_cur_phase{0.0};
            bool m_neg{false};
            SampleBuf m_lut;
    };
}
#endif

