#ifndef SOLA_EXCEPTION_PYTHONEXCEPTION
#define SOLA_EXCEPTION_PYTHONEXCEPTION

#include "Exception/BasicException.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Exception
    {
        class PythonException : public BasicException
        {
            using BasicException::BasicException;
        };
    } // namespace Exception
} // namespace Sola

#endif