#include <iostream>
#include<string>
using namespace std;

struct RequestNode{
    RequestNode* next;
    RequestNode* prev;
    string sender;
    bool is_accepted;
    RequestNode();
    RequestNode(string from);
};

class RequestList{
private:
    RequestNode* front;
    RequestNode* back;
public:
    RequestList();

    void addRequest(string sender);

    void decideRequest(){
        string decision;
        cout<<"If you want to accept the request type \"ACCEPT\" to decline type \"REJECT\": \n";
        getline(cin, decision);

        if(decision == "ACCEPT"){
            front->is_accepted = true;
        }

    }
};