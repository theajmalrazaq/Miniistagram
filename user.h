#include <iostream>
#include <string>
#include <iomanip>
#include "friendList.h"
#include "post.h"
#include "requestList.h"
using namespace std;
class User
{
private:
    string username;
    string password;
    string email;
    FriendList *friend_list;
    PostStack post_stack;
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
    void newPost(string, string, string);
    void getLatestPost();
    ////// Getters ///////
    string getfirst_name();
    string getlast_name();
    string getlast_sign_in();
    string getusername();
    string getpassword();
    string getemail();
    char getgender();
    string getDOB();
    ////// Follower Lists /////
    void showFollowers()
    {
        FriendNode *current = friend_list->getTop();
        int count_friends = 0;
        while (current != nullptr)
        {
            cout << "Name: " << current->friend_username << endl;
            cout << "Type: " << current->is_friend << endl;
            cout << setw(86) << setfill('-') << "-" << endl;
            count_friends++;
            current = current->prev;
        }
        cout << "THE NUMBER OF FOLLOWERS ARE: " << count_friends << endl;
    }

    void addFriend(string friend_name)
    {
    }
};
