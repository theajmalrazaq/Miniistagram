#include "friendrequest.h"
void FriendRequest::setNext(FriendRequest *next)
{
    this->next = next;
}
FriendRequest *FriendRequest::getNext() const
{
    return next;
}
string FriendRequest::getReceiver() const
{
    return receiver;
}
string FriendRequest::getSender() const
{
    return sender;
}
FriendRequest::FriendRequest(string sender, string receiver)
{
    this->sender = sender;
    this->receiver = receiver;
    next = nullptr;
}
