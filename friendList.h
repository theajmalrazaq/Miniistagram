#pragma once
#include <iostream>
#include<string>
using namespace std;

struct FriendNode{
    FriendNode* next;
    FriendNode* prev;
    string friend_username;
    bool is_friend;
    FriendNode(string name, bool connect);
};

class FriendList{
private:
    FriendNode* top;
public:
    FriendList();
    FriendNode* getTop() const;
    void addFriend(string friend_name);
};