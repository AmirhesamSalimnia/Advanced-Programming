#include "notification_class.hpp"

using namespace std;

void Notification::add_like_notification(string username, int jeek_ID)
{
	text = text + username + " liked " + int_to_string(jeek_ID) + "\n";
}
void Notification::add_dislike_notification(string username, int jeek_ID)
{
	text = text + username + " disliked " + int_to_string(jeek_ID) + "\n";
}
void Notification::add_comment_notification(string username, int jeek_ID)
{
	text = text + username + " commented on " + int_to_string(jeek_ID) + "\n";
}
void Notification::add_reply_notification(string username, int comment_ID)
{
	text = text + username + " replied " + int_to_string(comment_ID) + "\n";
}
void Notification::add_jeek_notification(string username, int jeek_ID)
{
	text = text + username + " jeeked " + int_to_string(jeek_ID) + "\n";
}
void Notification::add_mention_notification(string username, int jeek_ID)
{
	text = text + username + " mentioned you in " + int_to_string(jeek_ID) + "\n";
}
void Notification::add_rejeek_notification(string username, int jeek_ID)
{
	text = text + username + " rejeeked " + int_to_string(jeek_ID) + "\n";
}
void Notification::show_notifications()
{
	cout << text;
	text = "";
}