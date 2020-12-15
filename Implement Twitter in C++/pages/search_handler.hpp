#ifndef __SEARCH_HANDLER__
#define __SEARCH_HANDLER__

#include <iostream>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"
#include "html_maker.hpp"

class Search_Handler : public RequestHandler {
	Interface* jeek_jeek_interface;
	std::string file_path;
public:
	Search_Handler(Interface* _jeek_jeek_interface, std::string _file_path) :
			jeek_jeek_interface(_jeek_jeek_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif