#ifndef SOLA_EXCEPTION_SDLEXCEPTION
#define SOLA_EXCEPTION_SDLEXCEPTION

#include "Exception/BasicException.hpp"
#include "sola_common.hpp"

namespace Sola
{
    namespace Exception
    {
        class SDLException : public BasicException
        {
            using BasicException::BasicException;
        };
    } // namespace Exception
} // namespace Sola

#endif