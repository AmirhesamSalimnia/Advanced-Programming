#ifndef __NOTIFICATION_CLASS__
#define __NOTIFICATION_CLASS__

#include <iostream>
#include <string>
#include <vector>

#include "my_utilities.hpp"

class Notification
{
private:
	std::string text;
public:
	void add_like_notification(std::string username, int jeek_ID);
	void add_dislike_notification(std::string username, int jeek_ID);
	void add_comment_notification(std::string username, int jeek_ID);
	void add_reply_notification(std::string username, int comment_ID);
	void add_jeek_notification(std::string username, int jeek_ID);
	void add_mention_notification(std::string username, int jeek_ID);
	void add_rejeek_notification(std::string username, int jeek_ID);
	void show_notifications();
};
#endif