#include <iostream>
using namespace std;
#include "insta.h"

int main()
{
    int choice;

    do
    {
        // Add some blank lines for spacing
        cout << "\n\n\n";

        // Centered menu design
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
            cout << "\nYou selected Sign up.\n";
            break;
        case 2:
            cout << "\nYou selected Sign in.\n";
            break;
        case 3:
            cout << "\nYou selected Forgot password.\n";
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
