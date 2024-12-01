#include <iostream>
#include <string>
#include "friendList.h"
#include "requestList.h"
#include "post.h"
#include <ctime>
using namespace std;

class User
{
private:
    string username;
    string password;
    string email;
    FriendList *friend_list;
    RequestList request_list;
    PostStack post_stack;
    string first_name;
    string last_name;
    char gender;
    string last_sign_in;
    string DOB;
    string security_answers[3];
    string security_questions[3] = {"What is your pet name?", "What is your favourite color?", "What is your favourite food?"};

public:
    User();
    User(string username, string email, string password, string first_name, string last_name, string DOB, char gender);

    /////////// Setters /////////////
    void setusername(string);
    void setpassword(string);
    void setemail(string);
    void setfirst_name(string);
    void setlast_name(string);
    void setlast_sign_in(string);
    void setgender(char);
    void setDOB(string);
    void newPost();
    void getLatestPost();
    void setSecurityAnswers();

    // Friend Request Methods
    void sendRequest(User *receiver);
    void showRequests();

    ////// Getters ///////
    string getfirst_name();
    string getlast_name();
    string getlast_sign_in();
    string getusername();
    string getpassword();
    string getemail();
    bool verifySecurityAnswers();
    char getgender();
    string getDOB();
};
