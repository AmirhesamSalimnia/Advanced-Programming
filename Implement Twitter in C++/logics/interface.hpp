#ifndef __INTERFACE__
#define __INTERFACE__

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#include "jeek_class.hpp"
#include "user_class.hpp"
#include "reply_class.hpp"
#include "comment_class.hpp"
#include "my_utilities.hpp"
#include "exceptions.hpp"
#include "my_utilities.hpp"

#define NOT_FOUND -1
#define MAX_JEEK_LENGTH 140

class Interface
{
private:
	std::vector<std::vector<int> > session_table;
	int next_jeek_ID;
	int next_replies_and_comments_ID;
	std::vector<Jeek*> jeeks;
	std::vector<Reply*> replies_and_comments;
	std::vector<User*> users;
	int find_index_of_user_in_session_table(int session_id) const;
public:
	User* get_logged_in_user(int session_id) const;
	Jeek* get_jeek(int jeek_ID) const;
	bool is_session_id_exist(int session_id) const;
	bool jeek_ID_exist(int jeek_ID) const;
	void signup(std::string username, std::string display_name, std::string password);
	void login(std::string username, std::string password, int session_id);
	void logout(int session_id);
	void jeek(std::string text, std::vector<std::string> tags, std::vector<User*> mentioned_users, int user_index);
	std::vector<Jeek*> search(std::string search_string);
	void rejeek(int jeek_ID, int session_id);
	void like(int jeek_ID, int session_id);
	void dislike(int jeek_ID, int session_id);
	Interface() : next_jeek_ID(0), next_replies_and_comments_ID(0) {}
};

#endif