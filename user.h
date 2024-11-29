#include <iostream>
#include <string>
#include "friendrequest.h"
using namespace std;
class User
{
private:
    string username;
    string password;
    string email;
    FriendRequest *friend_request;
    string first_name;
    string last_name;
    char gender;
    string DOB;

public:
    User();
    User(string username, string email, string password, string first_name, string last_name, string DOB, char gender);
    void setusername(string);
    void setpassword(string);
    void setemail(string);
    void setgender(char);
    string getfirst_name();
    string getlast_name();
    void setDOB(string);
    string getusername();
    string getpassword();
    string getemail();
    void friend_requests(string sender, string receiver);
    char getgender();
    string getDOB();
};
