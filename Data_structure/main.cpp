#include <iostream>
using namespace std;
#include "Account.h"
int main() {
	int choice;
	Account userx;
	cout << "1. Signup" << endl;
	cout << "2. Login" << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1) {
		userx.signupprocess();
	}
}
