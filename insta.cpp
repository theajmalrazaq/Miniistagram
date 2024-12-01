#include "insta.h"
#include "validations.h"

////////////////// Constructor /////////////////
Insta::Insta()
{
    bst = new BST();
    user = new User[100];
    user_count = 0;
}

//////// Search User //////////
bool Insta::search(string username)
{
    BSTNode *userNode = bst->search(username);
    return userNode != nullptr;
}

////////////////// Sign Up /////////////////
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
    cout << "Enter First Name: ";
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
    User *newUser = new User(username, email, password, first_name, last_name, DOB, gender);
    cout << "Let's Secure Your Account" << endl;
    newUser->setSecurityAnswers();
    bst->insert(newUser);
    user[user_count] = *newUser;
    user_count++;
    cout << "Yahoooo You Made it!! " << endl;
    cout << "Welcome To Instagram" << endl;
}

///////////////////// sign in /////////////////////
BSTNode *activeuser;
void Insta::signin()
{
    string username;
    string password;
    cout << "Enter username: ";
    getline(cin, username);
    cout << "Enter password: ";
    getline(cin, password);
    bool is_valid = false;

    BSTNode *userNode = bst->search(username);

    if (userNode != nullptr && userNode->user->getpassword() == password)
    {
        activeuser = userNode;
        time_t now = time(0);
        userNode->user->setlast_sign_in(ctime(&now));
        is_valid = true;
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
    BSTNode *userNode = bst->search(username);
    if (userNode != nullptr && userNode->user->getemail() == email)
    {
        string password;
        cout << "Enter new password: ";
        getline(cin, password);
        while (!validate_strong_password(password) || password == userNode->user->getpassword())
        {
            cout << "Please enter a new and strong password: ";
            getline(cin, password);
        }
        userNode->user->setpassword(password);
        is_valid = true;
    }

    if (is_valid)
    {
        cout << "Password updated successfully." << endl;
    }
    else
    {
        cout << "Invalid username or email." << endl;
    }
}

//////////// show home after login //////////////////
void Insta::home(string username)
{
    int choice;
    string post;
    string date;
    cout << "welcome " << username << endl;
    cout << "1. Search User" << endl;
    cout << "2. Sign Out" << endl;
    cout << "3. New Post" << endl;
    cout << "4. Show Recent Post" << endl;
    cout << "5. Reset Password" << endl;
    cout << "6. Show Requests" << endl;

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
    else if (choice == 2)
    {
        signout();
    }
    else if (choice == 3)
    {
        activeuser->user->newPost();
        home(username);
    }
    else if (choice == 4)
    {
        activeuser->user->getLatestPost();
    }
    else if (choice == 5)
    {
        resetpassword();
    }
    else if (choice == 6)
    {
        activeuser->user->showRequests();
        cout << "Press 1 to go back to home" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            home(activeuser->user->getusername());
        }
    }
    else
    {
        cout << "Invalid choice" << endl;
        home(activeuser->user->getusername());
    }
}

/////////// Reset Password //////////
void Insta::resetpassword()
{
    if (activeuser->user->verifySecurityAnswers())
    {
        string password;
        cout << "Enter new password: ";
        getline(cin, password);
        while (!validate_strong_password(password) || password == activeuser->user->getpassword())
        {
            cout << "Please enter a new and strong password: ";
            getline(cin, password);
        }
        activeuser->user->setpassword(password);
        cout << "Password updated successfully." << endl;
        cout << "Press 1 to go back to home" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            home(activeuser->user->getusername());
        }
    }
    else
    {
        cout << "Invalid Security Answers" << endl;
    }
}
/////////////// View Profile //////////////////////
void Insta::viewprofile(string username)
{
    int choice;

    // Search for the user in the BST
    BSTNode *userNode = bst->search(username);

    if (userNode != nullptr)
    {
        // User found
        cout << "+----------------------- User Profile--------------------------+" << endl;
        cout << "First Name: " << userNode->user->getfirst_name() << endl;
        cout << "Last Name: " << userNode->user->getlast_name() << endl;
        cout << "Username: " << userNode->user->getusername() << endl;
        cout << "+-------------------------------------------------+" << endl;
        cout << "1. Add Friend" << endl;
        cout << "2. Back" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();
        if (choice == 1)
        {
            addfriend(username);
        }
        else if (choice == 2)
        {
            home(activeuser->user->getusername());
        }
        else
        {
            cout << "Invalid choice" << endl;
            viewprofile(username);
        }
    }
    else
    {
        cout << "User Not Found!!" << endl;
    }
}

////////////////// Add Friend /////////////////
void Insta::addfriend(string receiver)
{
    BSTNode *userNode = bst->search(receiver);
    if (userNode == nullptr)
    {
        cout << "User '" << receiver << "' not found." << endl;
        return;
    }
    userNode->user->sendrequest(activeuser->user->getusername());
    cout << "Friend request sent to " << receiver << endl;
}

/////// Signout /////
void Insta::signout()
{
    cout << "You are signed out." << endl;
    showmenu();
}

void Insta::showmenu()
{
    int choice;
    do
    {
        cout << "\n\n\n";
        cout << "                      +----------------------------------------------------------+\n";
        cout << "                      |                         INSTAGRAM                        |\n";
        cout << "                      +----------------------------------------------------------+\n";
        cout << "                      |                         1. Sign up                       |\n";
        cout << "                      |                         2. Sign in                       |\n";
        cout << "                      |                         3. Forgot password               |\n";
        cout << "                      |                         4.Display                          |\n";
        cout << "                      |                         5. Exit                          |\n";
        cout << "                      +----------------------------------------------------------+\n";
        cout << "                       Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            signup();
            break;
        case 2:
            signin();
            break;
        case 3:
            forgotpassword();
            break;
        case 4:
            display();
            break;
        case 5:
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice, please try again.\n";
            break;
        }
    } while (choice != 6);
}

////////////////// Display /////////////////
void Insta::inorderTraversal(BSTNode *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << "Username: " << node->user->getusername() << endl;
    cout << "Email: " << node->user->getemail() << endl;
    cout << "DOB: " << node->user->getDOB() << endl;
    cout << "Gender: " << node->user->getgender() << endl;
    cout << "First Name: " << node->user->getfirst_name() << endl;
    cout << "Last Name: " << node->user->getlast_name() << endl;
    cout << "Last Sign In: " << node->user->getlast_sign_in() << endl;
    cout << "-----------------------" << endl;
    inorderTraversal(node->right);
}

void Insta::display()
{
    if (bst->getRoot() == nullptr)
    {
        cout << "No users to display." << endl;
        return;
    }
    inorderTraversal(bst->getRoot());
}
