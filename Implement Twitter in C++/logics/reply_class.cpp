#include "reply_class.hpp"

using namespace std;

void Reply::show() const
{
	cout << creator->get_display_name() << endl;
	cout << text << endl;
	if(!replies.empty())
	{
		cout << "Replies:" << endl;
		for (int i = 0; i < replies.size(); ++i)
			cout << replies[i]->ID << endl;
	}
}
void Reply::add_reply(Reply* the_reply)
{
	replies.push_back(the_reply);
}
User* Reply::get_creator()
{
	return creator;
}