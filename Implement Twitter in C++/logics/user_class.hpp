#ifndef __USER__
#define __USER__

#include <iostream>
#include <string>
#include <vector>

#include "exceptions.hpp"
#include "my_utilities.hpp"

#define NOT_FOUND -1
class Jeek;

class User
{
private:
	std::string display_name;
	std::string user_name;
	std::string password;
	std::vector<Jeek*> jeeks;
	std::vector<User*> followings;
	std::vector<User*> followers;
	std::string notifications;
	int find_index_of_user_in_followings(std::string username) const;
	int find_index_of_user_in_followers(std::string username) const;
public:
	User(std::string _user_name, std::string _display_name, std::string _password);
	std::vector<Jeek*> get_jeeks() const { return jeeks; }
	void add_one_following(User* user);
	void delete_one_following(std::string username);
	void add_one_follower(User* user);
	void delete_one_follower(std::string username);
	void add_jeek(Jeek* the_jeek);
	std::string get_display_name() { return display_name; }
	std::string get_username() { return user_name; }
	bool check_if_this_username_and_password_can_login(std::string _username, std::string _password);
	void show_notifications();

	void add_like_notification(std::string username, int jeek_ID);
	void add_dislike_notification(std::string username, int jeek_ID);
	void add_comment_notification(std::string username, int jeek_ID);
	void add_reply_notification(std::string username, int comment_ID);
	void add_jeek_notification(std::string username, int jeek_ID);
	void add_jeek_notification_to_my_followers(std::string username, int jeek_ID);
	void add_mention_notification(std::string username, int jeek_ID);
	void add_rejeek_notification(std::string username, int jeek_ID);
};

#endif