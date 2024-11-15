#include "misc_os_dependent.h"
#include <boost/lexical_cast.hpp>

namespace epee
{
namespace misc_utils
{
  std::string get_thread_string_id()
  {
#if defined(_WIN32)
    return boost::lexical_cast<std::string>(GetCurrentThreadId());
#elif defined(__GNUC__)
    return boost::lexical_cast<std::string>(pthread_self());
#endif
  }
}
}
