#include "user_class.hpp"

using namespace std;

User::User(string _user_name, string _display_name, string _password)
{
	user_name = _user_name;
	display_name = _display_name;
	password = _password;
}
void User::add_one_following(User* user)
{
	int index_of_user = find_index_of_user_in_followings(user->get_username());
	if(index_of_user != NOT_FOUND)
		throw Follow_Twice_Exception();
	followings.push_back(user);
}
void User::delete_one_following(string _username)
{
	int index_of_user = find_index_of_user_in_followings(_username);
	if(index_of_user == NOT_FOUND)
		throw Unfollow_Before_Follow_Exception();
	followings.erase(followings.begin() + index_of_user);
}
int User::find_index_of_user_in_followings(string _username) const
{
	int index = NOT_FOUND;
	for (int i = 0; i < followings.size(); ++i)
	{
		if(followings[i]->user_name == _username)
			index = i;
	}
	return index;
}
void User::add_one_follower(User* user)
{
	int index_of_user = find_index_of_user_in_followers(user->get_username());
	if(index_of_user != NOT_FOUND)
		throw Follow_Twice_Exception();
	followers.push_back(user);
}
void User::delete_one_follower(string _username)
{
	int index_of_user = find_index_of_user_in_followers(_username);
	if(index_of_user == NOT_FOUND)
		throw Unfollow_Before_Follow_Exception();
	followers.erase(followers.begin() + index_of_user);
}
void User::add_jeek(Jeek* the_jeek)
{
	jeeks.push_back(the_jeek);
}
int User::find_index_of_user_in_followers(string _username) const
{
	int index = NOT_FOUND;
	for (int i = 0; i < followers.size(); ++i)
	{
		if(followers[i]->user_name == _username)
			index = i;
	}
	return index;
}
bool User::check_if_this_username_and_password_can_login(std::string _username, std::string _password)
{
	if((password == _password) && (user_name == _username))
		return true;
	else 
		return false;
}

void User::add_like_notification(string username, int jeek_ID)
{
	notifications = notifications + username + " liked " + int_to_string(jeek_ID) + "\n";
}
void User::add_dislike_notification(string username, int jeek_ID)
{
	notifications = notifications + username + " disliked " + int_to_string(jeek_ID) + "\n";
}
void User::add_comment_notification(string username, int jeek_ID)
{
	notifications = notifications + username + " commented on " + int_to_string(jeek_ID) + "\n";
}
void User::add_reply_notification(string username, int comment_ID)
{
	notifications = notifications + username + " replied " + int_to_string(comment_ID) + "\n";
}
void User::add_jeek_notification(string username, int jeek_ID)
{
	notifications = notifications + username + " jeeked " + int_to_string(jeek_ID) + "\n";
}
void User::add_jeek_notification_to_my_followers(string username, int jeek_ID)
{
	for (int i = 0; i < followers.size(); ++i)
		followers[i]->add_jeek_notification(username, jeek_ID);
}
void User::add_mention_notification(string username, int jeek_ID)
{
	notifications = notifications + username + " mentioned you in " + int_to_string(jeek_ID) + "\n";
}
void User::add_rejeek_notification(string username, int jeek_ID)
{
	notifications = notifications + username + " rejeeked " + int_to_string(jeek_ID) + "\n";
}
void User::show_notifications()
{
	cout << notifications;
	notifications = "";
}