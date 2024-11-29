#include "requestList.h"

RequestNode::RequestNode()
{
    next = prev = nullptr;
    is_accepted = false;
    sender = "";
}

RequestNode::RequestNode(string from)
{
    next = prev = nullptr;
    is_accepted = false;
    sender = from;
}

RequestList::RequestList()
{
    front = back = nullptr;
}

void RequestList::addRequest(string sender){
        RequestNode* newRequet = new RequestNode(sender);
        if(front == nullptr){
            back = front = newRequet;
        }

        back->next = newRequet;
        newRequet->prev = back;
        back = newRequet;
    }