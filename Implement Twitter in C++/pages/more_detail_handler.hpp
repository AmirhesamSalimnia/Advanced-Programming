#ifndef __MORE_DETAIL_HANDLER__
#define __MORE_DETAIL_HANDLER__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"
#include "html_maker.hpp"

class More_Detail_Handler : public RequestHandler {
	Interface* jeek_jeek_interface; 
	std::string file_path;
public:
	More_Detail_Handler(Interface* _jeek_jeek_interface, std::string _file_path) :
			jeek_jeek_interface(_jeek_jeek_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif