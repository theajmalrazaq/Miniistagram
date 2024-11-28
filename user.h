#include <iostream>
#include <string>
using namespace std;
class User
{
private:
    string username;
    string password;
    string email;
    string first_name;
    string last_name;
    char gender;
    string DOB;

public:
    User(string username, string email, string password, string first_name, string last_name, string DOB, char gender);
    void setusername(string);
    void setpassword(string);
    void setemail(string);
    void setgender(char);
    void setDOB(string);
    string getusername();
    string getpassword();
    string getemail();
    char getgender();
    string getDOB();
};
