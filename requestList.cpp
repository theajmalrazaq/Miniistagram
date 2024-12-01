#include "requestList.h"
#include "user.h"

RequestNode::RequestNode()
    : next(nullptr), prev(nullptr), is_accepted(false), sender(nullptr), receiver(nullptr) {}

RequestNode::RequestNode(User *sender, User *receiver)
    : next(nullptr), prev(nullptr), is_accepted(false), sender(sender), receiver(receiver) {}

RequestList::RequestList()
    : front(nullptr), back(nullptr) {}

void RequestList::addRequest(User *sender, User *receiver)
{
    // Check if the request already exists in the list to avoid duplicates
    RequestNode *temp = front;
    while (temp != nullptr)
    {
        if (temp->sender == sender && temp->receiver == receiver)
        {
            cout << "Request already exists between these users!" << endl;
            return;
        }
        temp = temp->next;
    }

    RequestNode *newRequest = new RequestNode(sender, receiver);

    if (front == nullptr)
    {
        front = back = newRequest;
    }
    else
    {
        back->next = newRequest;
        newRequest->prev = back;
        back = newRequest;
    }

    cout << "Request sent from " << sender->getusername() << " to " << receiver->getusername() << endl;
}

void RequestList::showRequests() const
{
    if (front == nullptr)
    {
        cout << "No requests available." << endl;
        return;
    }

    cout << "Received Requests:" << endl;
    int index = 1;
    RequestNode *temp = front;
    while (temp != nullptr)
    {
        cout << index << ". From: " << temp->sender->getusername()
             << " To: " << temp->receiver->getusername()
             << " | Status: " << (temp->is_accepted ? "Accepted" : "Pending") << endl;
        temp = temp->next;
        index++;
    }
}

void RequestList::acceptRequest(int index)
{
    if (front == nullptr)
    {
        cout << "No requests to accept." << endl;
        return;
    }

    RequestNode *temp = front;
    int currentIndex = 1;
    while (temp != nullptr && currentIndex < index)
    {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid selection. No request at index " << index << "." << endl;
        return;
    }

    temp->is_accepted = true;
    cout << "Request from " << temp->sender->getusername() << " accepted." << endl;
}

void RequestList::sendRequestBack(int index)
{
    if (front == nullptr)
    {
        cout << "No requests to send back." << endl;
        return;
    }

    RequestNode *temp = front;
    int currentIndex = 1;
    while (temp != nullptr && currentIndex < index)
    {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == nullptr)
    {
        cout << "Invalid index. No request to send back." << endl;
        return;
    }

    // Check if the request already exists to avoid duplicate requests
    RequestNode *checkTemp = front;
    while (checkTemp != nullptr)
    {
        if (checkTemp->sender == temp->receiver && checkTemp->receiver == temp->sender)
        {
            cout << "Request has already been sent back." << endl;
            return;
        }
        checkTemp = checkTemp->next;
    }

    // Send the request back
    cout << "Sending a request back from " << temp->receiver->getusername() << " to " << temp->sender->getusername() << endl;
    addRequest(temp->receiver, temp->sender);
}

void RequestList::menu(RequestList &senderRequests)
{
    while (true)
    {
        showRequests();

        if (front == nullptr)
        {
            cout << "All requests handled. Exiting menu." << endl;
            break;
        }

        cout << "\nMenu Options:" << endl;
        cout << "1. Accept a request" << endl;
        cout << "2. Send request back" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        int choice;
        cin >> choice;
        cin.ignore(); // To ignore newline character after input

        if (choice == 3)
        {
            cout << "Exiting the request menu." << endl;
            break;
        }
        else if (choice == 1)
        {
            cout << "Enter the number of the request you want to accept: ";
            int requestIndex;
            cin >> requestIndex;

            acceptRequest(requestIndex);

            // After accepting, ask if the user wants to send a request back
            cout << "Do you want to send a request back to the sender? (Y/N): ";
            char decision;
            cin >> decision;

            if (decision == 'Y' || decision == 'y')
            {
                sendRequestBack(requestIndex);
            }
        }
        else if (choice == 2)
        {
            cout << "Enter the number of the request you want to send back: ";
            int requestIndex;
            cin >> requestIndex;

            sendRequestBack(requestIndex);
        }
        else
        {
            cout << "Invalid option. Please select again." << endl;
        }
    }
}

// Getter for the front of the list
RequestNode *RequestList::getFront() const
{
    return front;
}

// Getter for the back of the list
RequestNode *RequestList::getBack() const
{
    return back;
}
