#include <iostream>
#include<string>
using namespace std;

struct RequestNode{
    RequestNode* next;
    RequestNode* prev;
    string sender;
    bool is_accepted;
    RequestNode(){
        next = prev = nullptr;
        is_accepted =false;
        sender = "";
    }

    RequestNode(string from){
        next = prev = nullptr;
        is_accepted =false;
        sender = from;
    }
};

class RequestList{
private:
    RequestNode* front;
    RequestNode* back;
public:
    RequestList(){
        front = back = nullptr;
    }

    void addRequest(string sender){
        RequestNode* newRequet = new RequestNode(sender);
        if(front == nullptr){
            back = front = newRequet;
        }

        back->next = newRequet;
        newRequet->prev = back;
        back = newRequet;
    }

    void decideRequest(){
        string decision;
        cout<<"If you want to accept the request type \"ACCEPT\" to decline type \"REJECT\": \n";
        getline(cin, decision);

        if(decision == "ACCEPT"){
            front->is_accepted = true;
        }

    }
};