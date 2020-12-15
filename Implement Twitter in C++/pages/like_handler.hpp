#ifndef __LIKE_HANDLER__
#define __LIKE_HANDLER__

#include <iostream>
#include "../server/server.hpp"
#include "../utils/utilities.hpp"
#include "../logics/interface.hpp"

class Like_Handler : public RequestHandler {
	Interface* jeek_jeek_interface;
public:
	Like_Handler(Interface* _jeek_jeek_interface) :
			jeek_jeek_interface(_jeek_jeek_interface) {}
 	Response *callback(Request *req);
};
#endif