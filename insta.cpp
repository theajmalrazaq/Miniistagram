#include "insta.h"
#include "validations.h"
Insta::Insta()
{
    user = new User *[100];
    user_count = 0;
}
bool Insta::search(string username)
{
    bool is_user_exist = false;

    for (int i = 0; i < user_count; i++)
    {
        if (username == user[i]->getusername())
        {
            is_user_exist = true;
            break;
        }
    }
    return is_user_exist;
}
void Insta::signup()
{
    cout << "Enter the following details to sign up: " << endl;
    ///////////////////////////// Username //////////////////////////////////
    string username;
    cout << "Enter username: ";
    getline(cin, username);

    while (!validateusername(username) || search(username))
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
    cout << "Let' Setup Your Profile" << endl;
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
    cin.ignore();
    user[user_count] = new User(username, email, password, first_name, last_name, DOB, gender);
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
        home(username);
    }
    else
    {
        cout << "Invalid username or password" << endl;
    }
}
/////////////// Forget Password ///////////////
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
        else
        {
            cout << "Invalid username or email" << endl;
        }
    }
}

///////////////// view profile ///////////////////////
void Insta::viewprofile(string username)
{
    int choice;
    bool is_valid = false;
    for (int i = 0; i < user_count; i++)
    {
        if (user[i]->getusername() == username)
        {
            cout << "+-------------------------------------------------+" << endl;
            cout << "First Name: " << user[i]->getfirst_name() << endl;
            cout << "Last Name: " << user[i]->getlast_name() << endl;
            cout << "Username: " << user[i]->getusername() << endl;
            cout << "+-------------------------------------------------+" << endl;
            cout << "1. Add Frined" << endl;
            cout << "2. Back" << endl;
            cout << "Enter Your Choice: ";
            cin >> choice;
        }
        else
        {
            cout << "User Not Found!!" << endl;
        }
    }
}
//////////// show home after login //////////////////
void Insta::home(string username)
{
    int choice;
    cout << "welcome " << username << endl;
    cout << "1 .Serach User" << endl;
    cout << "Enter Choice:";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        string searchusername;
        cout << "Enter username: ";
        getline(cin, searchusername);
        viewprofile(searchusername);
    }
}

void Insta::addfriend()
{
    string sender;
    string receiver;
    cout << "Enter sender username: ";
    getline(cin, sender);
    cout << "Enter receiver username: ";
    getline(cin, receiver);
    bool is_sender = false;
    bool is_receiver = false;
    for (int i = 0; i < user_count; i++)
    {
        if (user[i]->getusername() == sender)
        {
            is_sender = true;
        }
        if (user[i]->getusername() == receiver)
        {
            is_receiver = true;
        }
    }
    if (is_sender && is_receiver)
    {
        for (int i = 0; i < user_count; i++)
        {
            if (user[i]->getusername() == receiver)
            {
                user[i]->friend_requests(sender, receiver);
            }
        }
        cout << "Friend request sent" << endl;
    }
    else
    {
        cout << "Invalid sender or receiver" << endl;
    }
}

void Insta::display()
{
    if (user_count == 0)
    {
        cout << "No users to display." << endl;
        return;
    }

    for (int i = 0; i < user_count; i++)
    {
        if (user[i] != nullptr) // Ensure the pointer is valid
        {
            cout << "User " << i + 1 << ":" << endl;
            cout << "Username: " << user[i]->getusername() << endl;
            cout << "Email: " << user[i]->getemail() << endl;
            cout << "DOB: " << user[i]->getDOB() << endl;
            cout << "Gender: " << user[i]->getgender() << endl;
            cout << "-----------------------" << endl;
        }
        else
        {
            cout << "User " << i + 1 << " is null." << endl;
        }
    }
}
