#include "html_maker.hpp"

using namespace std;

string show_jeeks_in_short_describe (string base_string, vector<Jeek*> jeeks)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_string.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_string.substr(0, first_index_of_second_part);
	string second_part = base_string.substr(first_index_of_second_part);
	body = first_part;
	for (int i = jeeks.size() - 1; i >= 0; --i)
	{
		int jeek_ID = jeeks[i]->get_jeek_ID();
		body += "<div class=\"a_jeek\">";
		body += "<div class=\"text\">";
		body += "<p class=\"display_name\"><strong>@";
		body += jeeks[i]->get_jeeker()->get_display_name();
		body += ":</strong></p>";
		body += jeeks[i]->get_text();
		body += jeeks[i]->return_tags();
		body += jeeks[i]->return_username_of_mentioned_users();
		body += "</div>";
		body += "<div class=\"more_detail_div\">";

		body += "<form class=\"more_detail_form\" action=\"/more_detail\" method=\"post\"> <input type=\"hidden\" name=\"jeek_index\" value=\"";
		body += jeek_ID + '0';
		body += "\"> <button class=\"more_detail_btn\" type=\"submit\"> More Details </button> </form>";
		body += "</div>";
		body += "</div>";
	}
	body += second_part;
	return body;
}
string show_jeeks_in_detailed_describe (string base_string, Jeek* the_jeek)
{
	string body;
	string s = "<div class=\"the_content\">";
	int index_of_content_flag = base_string.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string first_part = base_string.substr(0, first_index_of_second_part);
	string second_part = base_string.substr(first_index_of_second_part);
	body = first_part;

	int jeek_ID = the_jeek->get_jeek_ID();
	body += "<div class=\"a_jeek\">";
	body += "<div class=\"jeeker\">";
	body += the_jeek->get_jeeker()->get_display_name();
	body += "</div>";
	body += "<div class=\"text\">";
	body += the_jeek->get_text();
	body += "<br><br>";
	body += the_jeek->return_tags();
	body += "<br><ber>";
	body += the_jeek->return_username_of_mentioned_users();
	body += "</div>";
	body += "<div class=\"details\"> #Likes: &nbsp;";
	body += the_jeek->get_num_of_likes() + '0';
	body += "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; #Rejeeks: &nbsp;";
	body += the_jeek->get_num_of_rejeeks() + '0';
	body += "</div>";

	body += "<div class=\"options\">";

	body += "<div> <form action=\"/like\" method=\"post\"> <input type=\"hidden\" name=\"jeek_index\" value=\"";
	body += jeek_ID + '0';
	body += "\"> <input class=\"like_logo\" type=\"image\" src=\"/like_logo\"> </form> </div>";

	body += "<div> <form action=\"/dislike\" method=\"post\"> <input type=\"hidden\" name=\"jeek_index\" value=\"";
	body += jeek_ID + '0';
	body += "\"> <input class=\"dislike_logo\" type=\"image\" src=\"/dislike_logo\"> </form> </div>";

	body += "<div> <form action=\"/rejeek\" method=\"post\"> <input type=\"hidden\" name=\"jeek_index\" value=\"";
	body += jeek_ID + '0';
	body += "\"> <button class=\"btn_rejeek\" type=\"submit\"> Rejeek </button> </form> </div>";
	
	body += "</div>";
	body += "</div>";

	body += second_part;
	return body;
}
string set_logged_in_user(string base_string, string display_name)
{
	string body;
	string s = "<!--display_name-->";
	int index_of_content_flag = base_string.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string second_part = base_string.substr(first_index_of_second_part);
	string first_part = base_string.substr(0, first_index_of_second_part);

	body = first_part;
	body += display_name;
	body += second_part;
	return body;
}
string set_kind_of_stylesheet(string base_string, string style_path)
{
	string body;
	string s = "<title>Jeek Jeek</title>";
	int index_of_content_flag = base_string.find(s);
	int first_index_of_second_part = index_of_content_flag + s.length();
	string second_part = base_string.substr(first_index_of_second_part);
	string first_part = base_string.substr(0, first_index_of_second_part);

	body = first_part;
	body += "<link rel=\"stylesheet\" href=\"";
	body += style_path;
	body += "\">";
	body += second_part;
	return body;
}