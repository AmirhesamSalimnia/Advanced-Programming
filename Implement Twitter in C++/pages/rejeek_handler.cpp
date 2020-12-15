#include "rejeek_handler.hpp"

using namespace std;

Response* Rejeek_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int jeek_index = atoi((req->getBodyParam("jeek_index").c_str()));
	int session_id = atoi((req->getSessionId()).c_str());
	jeek_jeek_interface->rejeek(jeek_index, session_id);
	res = Response::redirect("home");
	return res;
}