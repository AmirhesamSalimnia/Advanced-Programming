#ifndef __JEEK__
#define __JEEK__

#include <iostream>
#include <string>
#include <vector>

#include "comment_class.hpp"
#include "user_class.hpp"
#include "exceptions.hpp"

#define NOT_FOUND -1

class Comment;

class Jeek
{
private:
	int jeek_ID;
	std::string text;
	User* jeeker;
	std::vector<std::string> tags;
	std::vector<User*> mentioned_users;
	std::vector<User*> likes_users;
	std::vector<Jeek*> rejeeks;
	std::vector<Comment*> comments;
	int find_index_of_user_in_likes_user(std::string display_name) const;
	Jeek(int _jeek_ID, std::string _text, User* _jeeker) : jeek_ID(_jeek_ID), text(_text), jeeker(_jeeker) {}
public:
	std::string return_tags();
	std::string return_username_of_mentioned_users();
	int get_num_of_likes() { return likes_users.size(); }
	int get_num_of_rejeeks() { return rejeeks.size(); }
	Jeek(int _jeek_ID, std::string _text, User* _jeeker, std::vector<std::string> _tags, std::vector<User*> _mentioned_users);
	void show_jeek() const;
	void like_jeek(User* likes_user);
	void dislike_jeek(std::string dislike_display_name);
	void add_comment(Comment* the_comment);
	bool is_this_user_mentioned(std::string mentioned_username);
	bool is_this_tag_exist(std::string tag);
	Jeek* make_a_rejeek(int _jeek_ID, User* _jeeker);
	std::string get_jeeker_display_name();
	int get_jeek_ID() { return jeek_ID; }
	std::string get_text();
	User* get_jeeker();
};

#endif