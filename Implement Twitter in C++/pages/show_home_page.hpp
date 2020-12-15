#ifndef __SHOW_HOME_PAGE__
#define __SHOW_HOME_PAGE__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"
#include "html_maker.hpp"

class Show_Home_Page : public RequestHandler {
	Interface* jeek_jeek_interface; 
	std::string file_path;
public:
	Show_Home_Page(Interface* _jeek_jeek_interface, std::string _file_path) :
			jeek_jeek_interface(_jeek_jeek_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif