#ifndef __EXEPTIONS__
#define __EXEPTIONS__

#include <iostream>
#include <string>

class Input_Exception {};

class Logic_Exception
{
private:
	std::string error_message;
public:
	Logic_Exception(std::string _error_massge) : error_message(_error_massge) {}
	void print_error();
};

class Taken_Username_Exception_In_Signup : public Logic_Exception
{
public:
	Taken_Username_Exception_In_Signup() : Logic_Exception("Username has already taken.\n") {}
};
class Login_State_Exception_In_Signup : public Logic_Exception
{
public:
	Login_State_Exception_In_Signup() : Logic_Exception("To signup, please logout first.\n") {}
};
class Login_Twice_Exception_In_Login : public Logic_Exception
{
public:
	Login_Twice_Exception_In_Login() : Logic_Exception("You have already logged in.\n") {}
};
class Wrong_Username_Or_Password_In_Login : public Logic_Exception
{
public:
	Wrong_Username_Or_Password_In_Login() : Logic_Exception("Wrong username or password.\n") {}
};
class Logout_Twice_Exception_In_Logout : public Logic_Exception
{
public:
	Logout_Twice_Exception_In_Logout() : Logic_Exception("You have already logged out.\n") {}
};
class No_Login_User_Exception : public Logic_Exception
{
public:
	No_Login_User_Exception() : Logic_Exception("Please login first.\n") {}
};
class User_Not_Found_Exception : public Logic_Exception
{
public:
	User_Not_Found_Exception() : Logic_Exception("User not found.\n") {}
};
class Jeek_Length_Exception : public Logic_Exception
{
public:
	Jeek_Length_Exception() : Logic_Exception("Jeek length must not exceed 140 character.\n") {}
};
class Jeek_Not_Found_Exception : public Logic_Exception
{
public:
	Jeek_Not_Found_Exception() : Logic_Exception("Jeek not found.\n") {}
};
class Reply_Or_Commant_Not_Found_Exception : public	Logic_Exception
{
public:
	Reply_Or_Commant_Not_Found_Exception() : Logic_Exception("Reply or comment not found.\n") {}
};
class Dislike_Before_Like_Exception : public Logic_Exception
{
public:
	Dislike_Before_Like_Exception() : Logic_Exception("You have not like this jeek.\n") {}
};
class Unfollow_Before_Follow_Exception : public Logic_Exception
{
public:
	Unfollow_Before_Follow_Exception() : Logic_Exception("You have not follow this user.\n") {}
};
class Follow_Twice_Exception : public Logic_Exception
{
public:
	Follow_Twice_Exception() : Logic_Exception("This user has been followed before.\n") {}
};
class Like_Twice_Exception : public Logic_Exception
{
public:
	Like_Twice_Exception() : Logic_Exception("This jeek has been liked before.\n") {}
};
#endif