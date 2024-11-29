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
    string last_singn_in;
    string DOB;

public:
    User();
    User(string username, string email, string password, string first_name, string last_name, string DOB, char gender);
    ////// Setters ///////

    void setusername(string);
    void setpassword(string);
    void setemail(string);
    void setfirst_name(string);
    void setlast_name(string);
    void setlast_sign_in(string);
    void setgender(char);
    void setDOB(string);
    void friend_requests(string sender, string receiver);

    ////// Getters ///////
    string getfirst_name();
    string getlast_name();
    string getlast_sign_in();
    string getusername();
    string getpassword();
    string getemail();
    char getgender();
    string getDOB();
};
