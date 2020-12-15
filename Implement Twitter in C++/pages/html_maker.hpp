#ifndef __HTML_MAKER__
#define __HTML_MAKER__

#include <iostream>
#include <string>
#include "../logics/interface.hpp"

std::string show_jeeks_in_short_describe (std::string base_string, std::vector<Jeek*> jeeks);
std::string show_jeeks_in_detailed_describe (std::string base_string, Jeek* the_jeek);
std::string set_logged_in_user(std::string base_string, std::string display_name);
std::string set_kind_of_stylesheet(std::string base_string, std::string style_path);

#endif