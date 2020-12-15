#ifndef __MY_UTILITIES__
#define __MY_UTILITIES__

#include <iostream>
#include <string>
#include <vector>

#define WHITESPACES " \t"
#define ALPHABETIC "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

std::string int_to_string(int i);
void split_input(std::string command_line, std::string& commmand_word, std::vector<std::string> & data);
std::string separate_command_word(std::string &command_line);


#endif