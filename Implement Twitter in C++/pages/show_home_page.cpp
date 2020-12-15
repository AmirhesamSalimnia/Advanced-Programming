#include "show_home_page.hpp"

using namespace std;

Response* Show_Home_Page::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	if(jeek_jeek_interface->is_session_id_exist(session_id))
	{
		User* the_user = jeek_jeek_interface->get_logged_in_user(session_id);

		res->setHeader("Content-Type", "text/html");
		string body = readFile(file_path);

		body = set_kind_of_stylesheet(body, "/home_style");
		string display_name = the_user->get_display_name();
		body = set_logged_in_user(body, display_name);

		vector<Jeek*> jeeks_of_user = the_user->get_jeeks();
		body = show_jeeks_in_short_describe(body, jeeks_of_user);
		res->setBody(body);
	}
	else
		res = Response::redirect("/login");
	return res;
}