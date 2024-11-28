#include<iostream>
#include<string>
using namespace std;

struct MessageNode{
    MessageNode* next;
    string message;
    MessageNode(){
        next = nullptr;
        message = "";
    }
};

class MessageStack{
    private:
    string recipient_name;
    MessageNode* top;
    public:
    MessageStack(){  //default
        top = nullptr;
        recipient_name = "";
    }

    MessageStack(string friend_username){ // parametrized
        top = nullptr;
        recipient_name  = friend_username;
    }

};

struct ChatNode{
    ChatNode* next;
    MessageStack* message_stack;
    ChatNode(){
        next = nullptr;
    }
};

class ChatStack{
    private:
    ChatNode* top;
    public:
    ChatStack(){
        top = nullptr;
    }
};



int main (){

    return 0;
}