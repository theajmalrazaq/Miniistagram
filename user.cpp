#include "user.h"
#include "validations.h"

User::User() {};
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
    cout << "Enter the following details to sign up: " << endl;
    ///////////////////////////// Username //////////////////////////////////
    string username;
    cout << "Enter username: ";
    getline(cin, username);
    while (!validateusername(username))
    {
        cout << "Invalid username. Please enter a valid username: ";
        getline(cin, username);
    }
    setusername(username);
    ///////////////////////////// Password //////////////////////////////////
    string password;
    cout << "Enter password: ";
    getline(cin, password);
    while (!validate_strong_password(password))
    {
        cout << "Invalid password. Please enter a strong password: ";
        getline(cin, password);
    }
    setpassword(password);
    ///////////////////////////// Email //////////////////////////////////
    string email;
    cout << "Enter email: ";
    getline(cin, email);
    while (!validate_email(email))
    {
        cout << "Invalid email. Please enter a valid email: ";
        getline(cin, email);
    }
    setemail(email);
    /////////////////// DOB /////////////////////////
    string DOB;
    cout << "Enter DOB: ";
    getline(cin, DOB);
    while (!validate_DOB(DOB))
    {
        cout << "Invalid DOB. Please enter a valid DOB: ";
        getline(cin, DOB);
    }
    setDOB(DOB);
    ////////////////// Gender //////////////////
    int choice;

    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cout << "Choose Your Gender :" << endl;
    cin >> choice;
    while (choice != 1 && choice != 2)
    {
        cout << "Invalid choice. Please enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        setgender('M');
    }
    else if (choice == 2)
    {
        setgender('F');
    }
    cout << "Sign up successful!" << endl;
}