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
    friend_list =  new FriendList();
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
    friend_list =  new FriendList();
}

void User::setpassword(string password)
{
    this->password = password;
}
void User::setemail(string email)
{
    this->email = email;
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

char User::getgender()
{
    return gender;
}
