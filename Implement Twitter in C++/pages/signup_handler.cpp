#include "signup_handler.hpp"

using namespace std;
Response* Signup_Handler::callback(Request *req) 
{
	Response* res;
	string body;
	string username = req->getBodyParam("username");
	string display_name = req->getBodyParam("display_name");
	string password = req->getBodyParam("password");
	try{
		jeek_jeek_interface->signup(username, display_name, password);
		res = Response::redirect("/login");
	}
	catch(Taken_Username_Exception_In_Signup ex)
	{
		res = Response::redirect("/signup_with_error");
	}
	return res;
}