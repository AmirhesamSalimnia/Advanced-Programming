#ifndef __SIGNUP_PAGE__
#define __SIGNUP_PAGE__

#include <iostream>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"

class Signup_Handler : public RequestHandler {
	Interface* jeek_jeek_interface; 
public:
	Signup_Handler(Interface* _jeek_jeek_interface) :
			jeek_jeek_interface(_jeek_jeek_interface) {}
 	Response *callback(Request *req);
};
#endif