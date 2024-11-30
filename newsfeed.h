#include <iostream>
using namespace std;
class NewsFeed
{
private:
    string username;
    string post;
    string date;
    NewsFeed *next;

public:
    NewsFeed(string username, string post, string date);
    string getUsername() const;
    string getPost() const;
    string getDate() const;
    NewsFeed *getNext() const;
    void setNext(NewsFeed *next);
};