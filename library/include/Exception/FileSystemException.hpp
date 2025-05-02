#ifndef SOLA_EXCEPTION_FILESYSTEMEXCEPTION
#define SOLA_EXCEPTION_FILESYSTEMEXCEPTION

#include "Exception/BasicException.hpp"
#include "sola_common.hpp" 

namespace Sola
{
    namespace Exception
    {
        namespace FileSystemException
        {
            class ExecutableDirectoryUnavailableException : public BasicException
            {
                using BasicException::BasicException;
            };

        } // namespace FileSystemException
    } // namespace Exception
} // namespace Sola

#endif
