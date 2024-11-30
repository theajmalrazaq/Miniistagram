#include "user.h"
#include "validations.h"
User::User()
{
    username = "";
    email = "";
    password = "";
    first_name = "";
    last_name = "";
    DOB = "";
    gender = '\0';
    friend_list = new FriendList();
    post_stack = PostStack();
}
User::User(string username, string email, string password, string first_name, string last_name, string DOB, char gender)
{
    this->username = username;
    this->email = email;
    this->password = password;
    this->first_name = first_name;
    this->last_name = last_name;
    this->DOB = DOB;
    this->gender = gender;
    friend_list = new FriendList();
}
void User::setpassword(string password)
{
    this->password = password;
}
void User::setemail(string email)
{
    this->email = email;
}
void User::setfirst_name(string first_name)
{
    this->first_name = first_name;
}
void User::setlast_name(string last_name)
{
    this->last_name = last_name;
}
void User::setlast_sign_in(string last_sign_in)
{
    this->last_singn_in = last_sign_in;
}
void User::setDOB(string DOB)
{
    this->DOB = DOB;
}
void User::setgender(char gender)
{
    this->gender = gender;
}
void User::setusername(string username)
{
    this->username = username;
}
string User::getfirst_name()
{
    return this->first_name;
}
string User::getlast_name()
{
    return this->last_name;
}

string User::getusername()
{
    return this->username;
}
string User::getpassword()
{
    return this->password;
}
string User::getemail()
{
    return email;
}
string User::getDOB()
{
    return DOB;
}
string User::getlast_sign_in()
{
    return last_singn_in;
}
char User::getgender()
{
    return gender;
}

void User::newPost(string username, string post, string date)
{
    post_stack.newPost(username, post, date);
}
void User::getLatestPost()
{
    post_stack.peek();
}