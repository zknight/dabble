#include "lut.hh"

namespace ap
{
    Lut::Lut(int size, TableGenerator& generator)
        : m_size{size}, m_lut(size)
    {
        fill(generator);
    }

    void Lut::fill(TableGenerator& generator)
    {
        generator.generate(m_lut);
    }

    SampleBuf Lut::next_frame(int framesize, double frequency)
    {
        // wrap index
        if (m_cur_phase > m_size)
        {
            m_cur_phase -= m_size;
        }

        auto half_per = (1.0/(2.0*frequency));
        SampleBuf frame(framesize);
        auto step = (m_size/half_per)/m_fs;

        for (int i{0}; i<framesize; i++)
        {
            auto xa = index(m_cur_phase);
            auto xb = index(m_cur_phase+1);

            auto ya = (m_lut[xa]);
            auto yb = (m_lut[xb]);
            auto yb_flip = false;

            if (xa < m_cur_phase)
            {
                m_neg = !m_neg;
            }
            else if (xb < m_cur_phase)
            {
                yb_flip = true;
            }
            ya = m_neg == true ? -ya : ya;
            yb = m_neg != yb_flip ? -yb : yb;
            auto r = m_cur_phase - static_cast<int>(m_cur_phase);

            // interpolate
            auto y = ya + (yb - ya) * r;
            m_cur_phase += step;
            frame.push_back(y);

        }
        return frame;
    }

    // Genetalia
}

