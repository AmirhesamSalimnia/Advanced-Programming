#ifndef __SHOW_LOGIN_PAGE__
#define __SHOW_LOGIN_PAGE__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"

class Show_Login_Page : public RequestHandler {
	Interface* jeek_jeek_interface; 
	std::string file_path;
public:
	Show_Login_Page(Interface* _jeek_jeek_interface, std::string _file_path) :
			jeek_jeek_interface(_jeek_jeek_interface), file_path(_file_path) {}
 	Response *callback(Request *req);
};
#endif