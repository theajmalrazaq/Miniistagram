#include <iostream>
using namespace std;
#include "bst.h"
#include <ctime>
class Insta
{
private:
    User *user;
    string **connections;
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
    void viewprofile(string username);
    void signout();
    void showmenu();
    void inorderTraversal(BSTNode *node);
    void resetpassword();
};