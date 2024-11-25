#include <iostream>
#include "signup.h"
#include "login.h"
#include "Forget.h"
using namespace std;
class Account
{
public:
	void signupprocess(){
		string FirstName, LastName, username, dob, email, password;
		cout << "Enter First Name: ";
		cin >> FirstName;
		cout << "Enter Last Name: ";
		cin >> LastName;
		cout << "Enter Username: ";
		cin >> username;
		cout << "Enter Date of Birth: ";
		cin >> dob;
		cout << "Enter Email: ";
		cin >> email;
		cout << "Enter Password: ";
		cin >> password;
		Signup signup(FirstName, LastName, username, dob, email, password);
		signup.save();
	}
	void signupprocess(string username,string password) const {
		Login login(username, password);
	}

	void forgetprocess(string username) {
		ForgetPassword Forget(username);
	}
};
