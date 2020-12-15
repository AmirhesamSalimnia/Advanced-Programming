#include "more_detail_handler.hpp"

using namespace std;

Response* More_Detail_Handler::callback(Request *req) 
{
	Response *res = new Response;
	int session_id = atoi((req->getSessionId()).c_str());
	User* the_user = jeek_jeek_interface->get_logged_in_user(session_id);

	res->setHeader("Content-Type", "text/html");
	string body = readFile(file_path);

	body = set_kind_of_stylesheet(body, "/more_detail_style");
	string display_name = the_user->get_display_name();
	body = set_logged_in_user(body, display_name);

	int jeek_index = atoi((req->getBodyParam("jeek_index").c_str()));
	Jeek* the_jeek = jeek_jeek_interface->get_jeek(jeek_index);
	body = show_jeeks_in_detailed_describe(body, the_jeek);
	res->setBody(body);
	return res;
}