#include "user.h"
#include "validations.h"

User::User(string username, string email, string password, string first_name, string last_name, string DOB, char gender)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->DOB = DOB;
    this->gender = gender;
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
string User::getusername()
{
    return username;
}
string User::getpassword()
{
    return password;
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
