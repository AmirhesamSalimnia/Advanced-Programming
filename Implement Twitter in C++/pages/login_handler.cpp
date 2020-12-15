#include "login_handler.hpp"

using namespace std;

Response* Login_Handler::callback(Request *req) 
{
	Response *res = new Response;
	string username = req->getBodyParam("username");
	string password = req->getBodyParam("password");
	try{
		int random_number = rand(); 
		jeek_jeek_interface->login(username, password, random_number);
		string s_random_number = int_to_string(random_number);
		res = Response::redirect("/home");
		res->setSessionId(s_random_number);
	}
	catch(Wrong_Username_Or_Password_In_Login ex)
	{
		res = Response::redirect("/login_with_error");
	}
	return res;
}