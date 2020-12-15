#ifndef __LOGIN_HANDLER__
#define __LOGIN_HANDLER__

#include <iostream>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"

class Login_Handler : public RequestHandler {
	Interface* jeek_jeek_interface; 
public:
	Login_Handler(Interface* _jeek_jeek_interface) :
			jeek_jeek_interface(_jeek_jeek_interface) {}
 	Response *callback(Request *req);
};
#endif