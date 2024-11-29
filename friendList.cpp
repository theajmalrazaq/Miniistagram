#include "friendList.h"

FriendNode::FriendNode(string name, bool connect)
{
    friend_username = name;
    is_friend = connect;
    next = prev = nullptr;
}

FriendList::FriendList()
{
    top = nullptr;
}

void FriendList::addFriend(string friend_name)
{
    FriendNode *newFriend = new FriendNode(friend_name, true);
    if (top == nullptr)
    {
        top = newFriend;
    }

    FriendNode *current = top;
    top = newFriend;
    top->prev = current;
    current->next = top;
}