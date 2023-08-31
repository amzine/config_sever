#pragma once

#define STRUCTDATA_HPP

#include "webserv.hpp"

# define parseMap std::map<std::string, void (ConfigServer::*)(filevector)>

class ConfigServer;


typedef struct	s_listen {
	std::string	host;
	int			port;
}				t_listen;

