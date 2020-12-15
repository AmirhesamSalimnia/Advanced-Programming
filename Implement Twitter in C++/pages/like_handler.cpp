#include "like_handler.hpp"

using namespace std;

Response* Like_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int jeek_index = atoi((req->getBodyParam("jeek_index")).c_str());
	int session_id = atoi((req->getSessionId()).c_str());
	try {
		jeek_jeek_interface->like(jeek_index, session_id);
	}
	catch(Logic_Exception)
	{
	}
	res = Response::redirect("home");
	return res;
}