#include <iostream>
using namespace std;
class FriendRequest
{
private:
    string sender;
    string receiver;
    FriendRequest *next;

public:
    FriendRequest(string sender, string receiver);
    string getSender() const;
    string getReceiver() const;
    FriendRequest *getNext() const;
    void setNext(FriendRequest *next);
};