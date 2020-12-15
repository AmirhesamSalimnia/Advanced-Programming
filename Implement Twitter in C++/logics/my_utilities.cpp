#include "my_utilities.hpp"

using namespace std;

string int_to_string(int i)
{
	string str = "";
	while(i > 10)
	{
		str = (char)((i % 10) + '0') + str;
		i = i/10;
	}
	str = (char)((i % 10) + '0') + str;
	return str;
}
void split_input(string command_line ,string& commmand_word,vector<string> & data)
{
	bool first = true;
	string word = "";
	char previous_char = ' ';
	for(int i = 0; i < command_line.size(); i++)
	{
		if((previous_char != ' ') && (previous_char != '\t') && ((command_line[i] == ' ' ) || (command_line[i] == '\t')))
		{
			if(first){
				commmand_word = word;
				first = false;
				word = "";
			}
			else
			{
				data.push_back(word);
				word = "";
			}
		}
		else if((command_line[i] != ' ' ) && (command_line[i] != '\t'))
			word += command_line[i];
		previous_char = command_line[i];
	}
	if((previous_char != ' ') && (previous_char != '\t'))
	{
		if(first)
			commmand_word = word;
		else
			data.push_back(word);
	}
}
string separate_command_word(string &command_line)
{
	int begin_index_of_first_word = command_line.find_first_of(ALPHABETIC, 0);
	int end_index_of_first_word = command_line.find_first_of(WHITESPACES, begin_index_of_first_word) - 1;
	return command_line.substr(end_index_of_first_word + 1);
}