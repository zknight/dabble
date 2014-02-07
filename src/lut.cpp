#include "lut.hh"
#include <iostream>

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
#if 0
        // wrap index
        if (m_cur_phase > m_size)
        {
            m_cur_phase -= m_size;
        }
#endif

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

            std::cout << "phase: " << m_cur_phase << " xa: " << xa << " xb: " << xb <<  std::endl;
            if (xa+1 < m_cur_phase)
            {
                m_neg = !m_neg;
                std::cout << " xa m_cur_phase:" << m_cur_phase << std::endl;
            }
            else if (xb < m_cur_phase)
            {
                std::cout << " xb m_cur_phase:" << m_cur_phase << std::endl;
                yb_flip = true;
            }
            ya = m_neg ? -ya : ya;
            yb = m_neg ? -yb : yb;
            yb = yb_flip ? -yb : yb;
            std::cout << "ya: " << ya << " yb: " << yb << std::endl;
            auto r = m_cur_phase - static_cast<int>(m_cur_phase);

            // interpolate
            auto y = ya + (yb - ya) * r;
            m_cur_phase += step;
            if (m_cur_phase > m_size)
            {
                std::cout << "should flip" << std::endl;
                m_neg = !m_neg;
                m_cur_phase -= m_size;
            }
            frame[i] = y;

        }
        return frame;
    }

    // Genetalia
}

