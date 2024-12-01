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

////////////////////////// Overloaded Constructor ////////////////////
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

////////////// setters ///////////////
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
    this->last_sign_in = last_sign_in;
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

/////////////// Getters ////////////////////
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
    return last_sign_in;
}
char User::getgender()
{
    return gender;
}

//////// function to add new post ////////////////////////
void User::newPost()
{
    string post;
    cout << "Enter Post:";
    getline(cin, post);
    time_t now = time(0);
    string posttime = ctime(&now);
    post_stack.newPost(this->username, post, posttime);
}

////////// function to get latest post ///////////////////
void User::getLatestPost()
{
    post_stack.peek();
}

////// verify qs for resetting password //////////////////
bool User::verifySecurityAnswers()
{
    string arr[3];
    for (int i = 0; i < 3; i++)
    {
        cout << "Question " << i + 1 << ":" << security_questions[i] << endl;
        cin >> arr[i];
        while (arr[i] != security_answers[i])
        {
            cout << "Invalid Answer" << endl;
            cout << security_questions[i] << endl;
            cin >> arr[i];
        }
    }
    return true;
}

////////// set security answers at sign up ////////////////////
void User::setSecurityAnswers()
{
    for (int i = 0; i < 3; i++)
    {
        cout << security_questions[i] << endl;
        cin >> security_answers[i];
    }
    cout << "Security Answers Set" << endl;
}

// In User.cpp
void User::sendRequest(User *receiver)
{
    receiver->request_list.addRequest(this, receiver); // Pass pointers correctly
    cout << "Friend request sent to " << receiver->getusername() << "." << endl;
}

void User::showRequests()
{
    cout << "Handling requests for " << username << ":" << endl;
    request_list.menu(request_list);
}
