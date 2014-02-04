#ifndef AP_TABLE_GENERATOR_HH
#   define AP_TABLE_GENERATOR_HH
#include <vector>

namespace ap
{
    /// Type alias for a buffer of samples
    /// Sample values are double to avoid precision issues
    using SampleBuf = std::vector<double>;

    /// TableGenerator interface class
    /// create a concrete table generator
    /// by implementing the generate() method in your subclass
    class TableGenerator
    {
        public:
            // Use default ctors/dtor as this class simply wraps a 
            // generator method
            
            /// Implement this method in your table generator
            /// @precondition table_buffer is set to the size of the table
            ///     to generate
            /// @param table_buffer SampleBuf to place the samples
            virtual void generate(SampleBuf& table_buffer) = 0;
    };
}
#endif

