#include "interface.hpp"

using namespace std;

int Interface::find_index_of_user_in_session_table(int session_id) const
{
	for (int i = 0; i < session_table.size(); ++i)
	{
		if(session_table[i][1] == session_id)
			return i;
	}
	return NOT_FOUND;
}
User* Interface::get_logged_in_user(int session_id) const
{ 
	int index_in_sessoin_table = find_index_of_user_in_session_table(session_id);
	int user_index = session_table[index_in_sessoin_table][0];
	return users[user_index]; 
}
Jeek* Interface::get_jeek(int jeek_ID) const
{
	return jeeks[jeek_ID];
}
bool Interface::is_session_id_exist(int session_id) const
{
	int index_in_sessoin_table = find_index_of_user_in_session_table(session_id);
	if(index_in_sessoin_table == NOT_FOUND)
		return false;
	else
		return true;
}
bool Interface::jeek_ID_exist(int jeek_ID) const
{
	if(next_jeek_ID == 0)
		return false;
	if((jeek_ID >= next_jeek_ID) || (jeek_ID < 0))
		return false;
	else
		return true;
}
void Interface::signup(string username, string display_name, string password)
{
	for (int i = 0; i < users.size(); ++i)
	{
		if(username == users[i]->get_username())
			throw Taken_Username_Exception_In_Signup();
	}
	users.push_back(new User(username, display_name, password));
}
void Interface::login(string username, string password, int session_id)
{
	for (int i = 0; i < users.size(); ++i)
	{
		if(users[i]->check_if_this_username_and_password_can_login(username, password))
		{	
			vector<int> new_session_pair;
			new_session_pair.push_back(i);
			new_session_pair.push_back(session_id);
			session_table.push_back(new_session_pair);
			return;
		}
	}
	throw Wrong_Username_Or_Password_In_Login();
}
void Interface::logout(int session_id)
{
	session_table.erase(find_index_of_user_in_session_table(session_id) + session_table.begin());
}
void Interface::jeek(string text, vector<string> tags, vector<User*> mentioned_users, int user_index)
{
	Jeek* the_jeek = new Jeek(next_jeek_ID, text, users[user_index], tags, mentioned_users);
	jeeks.push_back(the_jeek);
	users[user_index]->add_jeek(the_jeek);
	next_jeek_ID++;
}
vector<Jeek*> Interface::search(string search_string)
{
	string searched_word = search_string.substr(1);
	vector<Jeek*> finded_jeek;
	if(search_string[0] == '#')
	{
		for (int i = 0; i < jeeks.size(); ++i)
		{
			if(jeeks[i]->is_this_tag_exist(searched_word))
				finded_jeek.push_back(jeeks[i]);
		}
	}
	else if(search_string[0] == '@')
	{
		for (int i = 0; i < jeeks.size(); ++i)
		{
			if(jeeks[i]->is_this_user_mentioned(searched_word))
				finded_jeek.push_back(jeeks[i]);
		}
	}
	return finded_jeek;
}
void Interface::rejeek(int jeek_ID, int session_id)
{
	int index_in_sessoin_table = find_index_of_user_in_session_table(session_id);
	int user_index = session_table[index_in_sessoin_table][0];
	Jeek* new_jeek = jeeks[jeek_ID]->make_a_rejeek(next_jeek_ID, users[user_index]);
	users[user_index]->add_jeek(new_jeek);
	jeeks.push_back(new_jeek);
	next_jeek_ID++;
}
void Interface::like(int jeek_ID, int session_id)
{
	int index_in_sessoin_table = find_index_of_user_in_session_table(session_id);
	int user_index = session_table[index_in_sessoin_table][0];
	jeeks[jeek_ID]->like_jeek(users[user_index]);
	jeeks[jeek_ID]->get_jeeker()->add_like_notification(users[user_index]->get_username(), jeek_ID);
}
void Interface::dislike(int jeek_ID, int session_id)
{
	int index_in_sessoin_table = find_index_of_user_in_session_table(session_id);
	int user_index = session_table[index_in_sessoin_table][0];
	jeeks[jeek_ID]->dislike_jeek(users[user_index]->get_display_name());
	jeeks[jeek_ID]->get_jeeker()->add_dislike_notification(users[user_index]->get_username(), jeek_ID);	
}