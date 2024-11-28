#include "insta.h"
#include "validations.h"
Insta::Insta()
{
    user = new User *[100];
    user_count = 0;
}
void Insta::signup()
{
    cout << "Enter the following details to sign up: " << endl;
    ///////////////////////////// Username //////////////////////////////////
    string username;
    cout << "Enter username: ";
    getline(cin, username);
    bool is_user_exist = false;
    for (int i = 0; i < user_count; i++)
    {
        if (username == user[i]->getusername())
        {
            is_user_exist = true;
            break;
        }
    }

    while (!validateusername(username) && is_user_exist)
    {
        cout << "Username Is Already Registred!! OR Invalid Username " << endl;
        cout << "Enter username: ";
        getline(cin, username);
    }

    ///////////////////////////// Email //////////////////////////////////
    string email;
    cout << "Enter email: ";
    getline(cin, email);
    while (!validate_email(email))
    {
        cout << "Invalid email. Please enter a valid email: ";
        getline(cin, email);
    }
    ///////////////////////////// Password //////////////////////////////////
    string password;
    cout << "Enter password: ";
    getline(cin, password);
    while (!validate_strong_password(password))
    {
        cout << "Invalid password. Please enter a strong password: ";
        getline(cin, password);
    }

    cout << "Sign up successfull!!" << endl;
    cout
        << "Let' Setup Your Profile" << endl;
    ///////////////// First Name /////////////////////
    string first_name;
    cout << "Enter Firts Name: ";
    getline(cin, first_name);
    ///////////////// Last Name /////////////////////
    string last_name;
    cout << "Enter Last Name: ";
    getline(cin, last_name);

    /////////////////// DOB /////////////////////////
    string DOB;
    cout << "Enter DOB (DD-MM-YYY): ";
    getline(cin, DOB);
    while (!validate_DOB(DOB))
    {
        cout << "Invalid DOB. Please enter a valid DOB: ";
        getline(cin, DOB);
    }
    ////////////////// Gender //////////////////
    int choice;

    cout << "1. Male" << endl;
    cout << "2. Female" << endl;
    cout << "Choose Your Gender :" << endl;
    cin >> choice;
    char gender;
    while (choice != 1 && choice != 2)
    {
        cout << "Invalid choice. Please enter a valid choice: ";
        cin >> choice;
    }
    if (choice == 1)
    {
        gender = 'M';
    }
    else if (choice == 2)

    {
        gender = 'F';
    }
    user[user_count] = new User(username, password, email, first_name, last_name, DOB, gender);
    user_count++;
    cout << "Yahoooo You Made it!! " << endl;
    cout << "Welcome To Instagram" << endl;
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

void Insta::forgotpassword()
{
    string username;
    string email;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter email: ";
    getline(cin, email);
    bool is_valid = false;
    for (int i = 0; i < user_count; i++)
    {
        if (user[i]->getusername() == username && user[i]->getemail() == email)
        {
            string password;
            cout << "Enter password: ";
            getline(cin, password);
            while (!validate_strong_password(password) || password == user[i]->getpassword())
            {
                cout << "Please enter a new and strong password: ";
                getline(cin, password);
            }
            user[i]->setpassword(password);
            is_valid = true;
            break;
        }

        if (is_valid)
        {
            cout << "Password Changed Sucessfully!!" << endl;
        }
        else
        {
            cout << "Invalid username or email" << endl;
        }
    }
}