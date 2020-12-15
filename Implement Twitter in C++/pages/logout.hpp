#ifndef __LOGOUT__
#define __LOGOUT__

#include <iostream>
#include <string>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"

class Logout : public RequestHandler {
	Interface* jeek_jeek_interface; 
public:
	Logout(Interface* _jeek_jeek_interface) :
			jeek_jeek_interface(_jeek_jeek_interface) {}
 	Response *callback(Request *req);
};
#endif