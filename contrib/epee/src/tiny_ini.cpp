#include "string_tools.h"
#include <boost/regex.hpp>

namespace epee
{
namespace tiny_ini
{
  bool get_param_value(const std::string& param_name, const std::string& ini_entry, std::string& res)
  {
    std::string expr_str = std::string() + "^("+ param_name +") *=(.*?)$";
    const boost::regex match_ini_entry(expr_str, boost::regex::icase | boost::regex::normal);
    boost::smatch result;
    if (!boost::regex_search(ini_entry, result, match_ini_entry, boost::match_default))
      return false;
    res = result[2];
    string_tools::trim(res);
    return true;
  }
}
}
