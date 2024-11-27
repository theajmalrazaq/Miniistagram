#include <iostream>
#include <string>
using namespace std;
class User
{
private:
    string username;
    string password;
    string email;
    char gender;
    string DOB;

public:
    User();
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
    void login();
    void forgotpassword();
    void signup();
};
