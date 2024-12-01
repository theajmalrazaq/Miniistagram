#include "requestList.h"

RequestNode::RequestNode()
    : next(nullptr), prev(nullptr), is_accepted(false), sender("") {}

RequestNode::RequestNode(string from)
    : next(nullptr), prev(nullptr), is_accepted(false), sender(from) {}

RequestList::RequestList()
    : front(nullptr), back(nullptr) {}

void RequestList::showRequests()
{
    if (front == nullptr)
    {
        cout << "No requests available." << endl;
        return;
    }

    RequestNode *temp = front;
    while (temp != nullptr)
    {
        cout << temp->sender << endl;
        temp = temp->next;
    }
}

void RequestList::addRequest(string receiver)
{
    if (receiver.empty())
    {
        cout << "Invalid request: receiver name cannot be empty." << endl;
        return;
    }

    RequestNode *newRequest = new RequestNode(receiver);

    if (front == nullptr) // If the list is empty
    {
        front = back = newRequest;
    }
    else
    {
        back->next = newRequest; // Link the current back to the new node
        newRequest->prev = back; // Set the new node's previous pointer
        back = newRequest;       // Update the back pointer to the new node
    }

    cout << "Request sent to " << receiver << endl;
}

RequestNode *RequestList::getFront() const
{
    return front;
}

RequestNode *RequestList::getBack() const
{
    return back;
}
