#include "user.h"
#include "validations.h"

void User::setusername(string username)
{
    this->username = username;
}
void User::setpassword(string password)
{
    this->password = password;
}
void User::setemail(string email)
{
    this->email = email;
}

void User::setDOB(string DOB)
{
    this->DOB = DOB;
}
void User::setgender(char gender)
{
    this->gender = gender;
}
void User::signup()
{
    validations v;
    ///////////////////////////// Username //////////////////////////////////
    string username;
    cout << "Enter username: ";
    getline(cin, username);
    while (!v.validateusername(username))
    {
        cout << "Invalid username. Please enter a valid username: ";
        getline(cin, username);
    }
    setusername(username);
    ///////////////////////////// Password //////////////////////////////////
    string password;
    cout << "Enter password: ";
    getline(cin, password);
    while (!v.validate_strong_password(password))
    {
        cout << "Invalid password. Please enter a strong password: ";
        getline(cin, password);
    }
    setpassword(password);
    ///////////////////////////// Email //////////////////////////////////
    string email;
    cout << "Enter email: ";
    getline(cin, email);
    while (!v.validate_email(email))
    {
        cout << "Invalid email. Please enter a valid email: ";
        getline(cin, email);
    }
    setemail(email);
    /////////////////// DOB /////////////////////////
    string DOB;
    cout << "Enter DOB: ";
    getline(cin, DOB);
    while (!v.validate_DOB(DOB))
    {
        cout << "Invalid DOB. Please enter a valid DOB: ";
        getline(cin, DOB);
    }
    setDOB(DOB);
    //////////////////
}