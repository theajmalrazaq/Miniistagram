#include <iostream>
using namespace std;
#include "user.h"
class Insta
{
private:
    User **user;
    int user_count;

public:
    Insta();
    void signup();
    void signin();
    void forgotpassword();
    string Search();
    // void addfriend();
    // void display();
    // void deleteaccount();
    // void updateprofile();
    // void viewprofile();
};