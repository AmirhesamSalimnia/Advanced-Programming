#ifndef __COMMENT__
#define __COMMENT__

#include "reply_class.hpp"
#include "jeek_class.hpp"

class Jeek;

class Comment : public Reply
{
private:
	Jeek* its_jeek;
public:
	Comment(int _ID, std::string _text, Jeek* _its_jeek, User* _creator)
		: Reply(_ID, _text, _creator), its_jeek(_its_jeek) {}
};

#endif