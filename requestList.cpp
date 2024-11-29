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