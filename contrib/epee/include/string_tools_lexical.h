#ifndef _STRING_TOOLS_LEXICAL_H_
#define _STRING_TOOLS_LEXICAL_H_

#include "warnings.h"
#include "storages/parserse_base_utils.h"
#include <boost/lexical_cast.hpp>

#ifndef OUT
  #define OUT
#endif

namespace epee
{
namespace string_tools
{
PUSH_WARNINGS
DISABLE_GCC_WARNING(maybe-uninitialized)
  template<class XType>
  inline bool get_xtype_from_string(OUT XType& val, const std::string& str_id)
  {
    if (std::is_integral<XType>::value && !std::numeric_limits<XType>::is_signed && !std::is_same<XType, bool>::value)
    {
      for (char c : str_id)
      {
        if (!epee::misc_utils::parse::isdigit(c))
          return false;
      }
    }

    try
    {
      val = boost::lexical_cast<XType>(str_id);
      return true;
    }
    catch(const std::exception&)
    {
      return false;
    }
    catch(...)
    {
      return false;
    }

    return true;
  }
POP_WARNINGS

  template<class XType>
  inline bool xtype_to_string(const XType& val, std::string& str)
  {
    try
    {
      str = boost::lexical_cast<std::string>(val);
    }
    catch(...)
    {
      return false;
    }

    return true;
  }
}
}
#endif