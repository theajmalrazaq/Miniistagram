#include <iostream>
using namespace std;
#include "insta.h"

int main()
{
    int choice;
    Insta insta;
    do
    {
        cout << "\n\n\n";
        cout << "                      +----------------------------------------------------------+\n";
        cout << "                      |                         INSTAGRAM                        |\n";
        cout << "                      +----------------------------------------------------------+\n";
        cout << "                      |                         1. Sign up                       |\n";
        cout << "                      |                         2. Sign in                       |\n";
        cout << "                      |                         3. Forgot password               |\n";
        cout << "                      |                         4. Exit                          |\n";
        cout << "                      +----------------------------------------------------------+\n";
        cout << "                       Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            insta.signup();
            break;
        case 2:
            insta.signin();
            break;
        case 3:
            insta.forgotpassword();
            break;
        case 4:
            cout << "\nExiting...\n";
            break;
        default:
            cout << "\nInvalid choice, please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}
