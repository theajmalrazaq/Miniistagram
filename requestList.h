#pragma once
#include <iostream>
#include <string>
using namespace std;

// Forward declaration of the User class to avoid circular dependency
class User;
struct RequestNode
{
    RequestNode *next;
    RequestNode *prev;
    User *sender;   // Use pointers to User class
    User *receiver; // Use pointers to User class
    bool is_accepted;
    RequestNode();
    RequestNode(User *sender, User *receiver); // Use pointers to User
};

class RequestList
{
private:
    RequestNode *front;
    RequestNode *back;

public:
    RequestList();
    void addRequest(User *sender, User *receiver); // Use pointers to User
    void showRequests() const;
    RequestNode *getFront() const;
    RequestNode *getBack() const;
    void acceptRequest(int index);
    void sendRequestBack(int index);
    void menu(RequestList &senderRequests);
};