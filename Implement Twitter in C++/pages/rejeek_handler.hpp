#ifndef __REJEEK_HANDLER__
#define __REJEEK_HANDLER__

#include <iostream>
#include <string>
#include <cstdlib>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"

class Rejeek_Handler : public RequestHandler {
	Interface* jeek_jeek_interface;
public:
	Rejeek_Handler(Interface* _jeek_jeek_interface) :
			jeek_jeek_interface(_jeek_jeek_interface) {}
 	Response *callback(Request *req);
};
#endif