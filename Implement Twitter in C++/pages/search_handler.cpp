#include "search_handler.hpp"

using namespace std;

Response* Search_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	User* the_user = jeek_jeek_interface->get_logged_in_user(session_id);
	
	res->setHeader("Content-Type", "text/html");
	string body = readFile(file_path);

	body = set_kind_of_stylesheet(body, "/home_style");
	string display_name = the_user->get_display_name();
	body = set_logged_in_user(body, display_name);

	string search_word = req->getBodyParam("search_word");
	vector<Jeek*> finded_jeek = jeek_jeek_interface->search(search_word);
	body = show_jeeks_in_short_describe(body, finded_jeek);
	res->setBody(body);
	return res;
}