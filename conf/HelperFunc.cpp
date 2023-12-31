
#include "HelperFunc.hpp"



std::string	to_string(size_t n)
{
	std::stringstream tmp;

	tmp << n;

	return tmp.str();
}

bool isDigits(const std::string &str)
{
  return str.find_first_not_of("0123456789;") == std::string::npos;
}

std::string removeSlaches(const std::string &str) 
{
  std::string ret;
  bool  islastslash = false;

  for (std::string::size_type i = 0; i < str.length(); i++)
  {
    if (str[i] == '/')
    {
      if (!islastslash)
        ret.push_back(str[i]);
      islastslash = true;
    }
    else
    {
      islastslash = false;
      ret.push_back(str[i]);
    }
  }
  return ret;
}

unsigned int	strToIp(std::string strIp) 
{
	size_t  sep = 0;
	unsigned int   n;
	unsigned char  m[4];
	size_t  start = 0;
	if (strIp == "localhost")
		strIp = "127.0.0.1";
	for (unsigned int i = 3 ; i != std::numeric_limits<uint32_t>::max(); i--) {
		sep = strIp.find_first_of('.', sep);
		std::string str = strIp.substr(start, sep);
		n = atoi(str.c_str());
		m[i] = static_cast<unsigned char>(n);
		sep++;
		start = sep;
	}
	unsigned final = *(reinterpret_cast<unsigned int *>(m));
	return final;
}
