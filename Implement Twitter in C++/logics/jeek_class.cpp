#include "jeek_class.hpp"

using namespace std;

Jeek::Jeek(int _jeek_ID, string _text, User* _jeeker, vector<string> _tags, vector<User*> _mentioned_users)
{
	jeek_ID = _jeek_ID;
	text = _text;
	jeeker = _jeeker;
	tags = _tags;
	mentioned_users = _mentioned_users;
}
string Jeek::return_tags()
{
	string s;
	for (int i = 0; i < tags.size(); ++i)
	{
		s += '#';
		s += tags[i];
	}
	return s;
}
string Jeek::return_username_of_mentioned_users()
{
	string s;
	for (int i = 0; i < mentioned_users.size(); ++i)
	{
		s += '@';
		s += mentioned_users[i]->get_username();
	}
	return s;
}
void Jeek::show_jeek() const
{
	cout << jeeker->get_display_name() << endl;
	cout << text << endl;
	if(tags.size() != 0){
		for (int i = 0; i < tags.size(); ++i)
			cout << "#" << tags[i] << endl;
	}
	if(mentioned_users.size() != 0){
		for (int i = 0; i < mentioned_users.size(); ++i)
			cout << "@" << mentioned_users[i]->get_username() << endl;
	}
	cout << "Likes " << likes_users.size() << endl;
	cout << "Rejeeks " << rejeeks.size() << endl;
	if(comments.size() != 0){
		cout << "comments: " << endl;
		for (int i = 0; i < comments.size(); ++i)
			cout << comments[i]->get_ID() << " \n";
	}
}
void Jeek::like_jeek(User* like_user)
{
	for (int i = 0; i < likes_users.size(); ++i)
	{
		if(likes_users[i] == like_user)
			throw Like_Twice_Exception();
	}
	likes_users.push_back(like_user);
}
void Jeek::dislike_jeek(string dislike_display_name)
{
	int index_of_disliker = find_index_of_user_in_likes_user(dislike_display_name);
	if(index_of_disliker == NOT_FOUND)
		throw Dislike_Before_Like_Exception();
	likes_users.erase(likes_users.begin() + index_of_disliker);
}
int Jeek::find_index_of_user_in_likes_user(string display_name) const
{
	for (int i = 0; i < likes_users.size(); ++i)
	{
		if(likes_users[i]->get_display_name() == display_name)
			return i;
	}
	return NOT_FOUND;
}
void Jeek::add_comment(Comment* the_comment)
{
	comments.push_back(the_comment);
}
bool Jeek::is_this_user_mentioned(string mentioned_username)
{
	for (int i = 0; i < mentioned_users.size(); ++i)
	{
		if(mentioned_users[i]->get_username() == mentioned_username)
			return true;
	}
	return false;
}
bool Jeek::is_this_tag_exist(string tag)
{
	for (int i = 0; i < tags.size(); ++i)
	{
		if(tags[i] == tag)
			return true;
	}
	return false;
}
Jeek* Jeek::make_a_rejeek(int _jeek_ID, User* _jeeker)
{
	string temp_text = "Rejeeked: " + this->text; 
	Jeek* new_jeek = new Jeek(_jeek_ID, temp_text, _jeeker);
	rejeeks.push_back(new_jeek);
	return new_jeek;
}
string Jeek::get_jeeker_display_name()
{
	return jeeker->get_display_name();
}
User* Jeek::get_jeeker()
{
	return jeeker;
}
string Jeek::get_text()
{
	return text;
}