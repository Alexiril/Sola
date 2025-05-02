#ifndef SOLA_EXCEPTION_APPLICATIONEXCEPTION
#define SOLA_EXCEPTION_APPLICATIONEXCEPTION

#include "Exception/BasicException.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Exception
    {
        namespace ApplicationException
        {
            class ApplicationInitializationException : public BasicException
            {
                using BasicException::BasicException;
            };

        } // namespace ApplicationException
    } // namespace Exception
} // namespace Sola

#endif
