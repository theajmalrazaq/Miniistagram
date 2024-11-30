#include <string>
using namespace std;

class PostNode
{
private:
    string username;
    string post;
    string date;
    PostNode *next; // Pointer to the next post in the stack

public:
    // Constructor to initialize the PostNode
    PostNode(string username, string post, string date);

    // Getter methods
    string getUsername() const;
    string getPost() const;
    string getDate() const;
    PostNode *getNext() const;

    // Setter method for 'next'
    void setNext(PostNode *next);
};

class PostStack
{
private:
    PostNode *top; // Pointer to the top of the stack

public:
    // Constructor for initializing an empty stack
    PostStack();

    // Function to add a new post
    void newPost(string, string, string);

    // Function to display the top post (peek)
    void peek() const;

    // Destructor to clean up the stack
    ~PostStack();
};
