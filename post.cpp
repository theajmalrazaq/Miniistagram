#include "Post.h"
#include <iostream>
using namespace std;

PostNode::PostNode(string username, string post, string date)
    : username(username), post(post), date(date), next(nullptr) {}

string PostNode::getUsername() const
{
    return username;
}

string PostNode::getPost() const
{
    return post;
}

string PostNode::getDate() const
{
    return date;
}

PostNode *PostNode::getNext() const
{
    return next;
}

void PostNode::setNext(PostNode *next)
{
    this->next = next;
}
/////// Constuctor Implemenattaion /////////////////////////
PostStack::PostStack()
{
    top = nullptr;
}
///////// Add New post  /////////////////////
void PostStack::newPost(string name, string post, string date)
{
    PostNode *newPost = new PostNode(name, post, date);

    if (top == nullptr)
    {
        top = newPost;
    }
    else
    {
        newPost->setNext(top);
        top = newPost;
    }

    cout << "Post added successfully!" << endl;
}
//////// Show lastest Post /////////////////
void PostStack::peek() const
{
    if (top == nullptr)
    {
        cout << "No posts available." << endl;
        return;
    }

    cout << "Top Post: " << endl;
    cout << "Username: " << top->getUsername() << endl;
    cout << "Post: " << top->getPost() << endl;
    cout << "Date: " << top->getDate() << endl;
}

/////////////// Destructor implementation ////////////////////////
PostStack::~PostStack()
{
    while (top != nullptr)
    {
        PostNode *temp = top;
        top = top->getNext();
        delete temp;
    }
}
