#include <iostream>
using namespace std;
#include "bst.h"
#include <ctime>
class Insta
{
private:
    User *user;
    BST *bst;
    int user_count;

public:
    Insta();
    void signup();
    void signin();
    void forgotpassword();
    void display();
    bool search(string username);
    void addfriend();
    void home(string username);
    // void deleteaccount();
    // void updateprofile();
    void viewprofile(string username);
    void signout();
    void showmenu();
    void inorderTraversal(BSTNode *node);
};