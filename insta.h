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
    // void addfriend();
    void display();
    // void search();
    // void deleteaccount();
    // void updateprofile();
    // void viewprofile();
};