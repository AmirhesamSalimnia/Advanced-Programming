#ifndef __REPLY__
#define __REPLY__

#include <iostream>
#include <string>
#include <vector>

#include "user_class.hpp"

class Reply
{
protected:
	int ID;
	std::string text;
	std::vector<Reply*> replies;
	User* creator;
public:
	Reply(int _ID, std::string _text, User* _creator)
		: ID(_ID), text(_text), creator(_creator) {}
	int get_ID(){ return ID; }
	void show() const;
	void add_reply(Reply* the_reply);
	User* get_creator();
};

#endif