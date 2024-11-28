#include "insta.h"
#include "validations.h"
Insta::Insta()
{
    user = new User *[100];
    user_count = 0;
}
void Insta::signup()
{
    user[user_count] = new User;
    user[user_count]->signup();
    user_count++;
}
void Insta::signin()
{
    string username;
    string password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    bool is_valid = false;
    for (int i = 0; i < user_count; i++)
    {
        if (user[i]->getusername() == username && user[i]->getpassword() == password)
        {
            is_valid = true;
            break;
        }
    }
    if (is_valid)
    {
        cout << "Sign in successful" << endl;
    }
    else
    {
        cout << "Invalid username or password" << endl;
    }
}

string Insta::Search()
{
    string username;
    cout << "Enter Username: " << endl;
    if (validateusername(username))
    {
        for (int i = 0; i < user_count; i++)
        {
            if (user[i]->getusername() == username)
            {
                cout << "Username: " << user[i]->getusername() << endl;
                cout << "Email: " << user[i]->getemail() << endl;
                        }
        }
    }
    else
    {
        cout << "Invalid Username" << endl;
    }
    return username;
}