#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Login {
	string email;
	string password;

public:
	Login(string email, string password) {
		this->email = email;
		this->password = password;
	}
	string getEmail() {
		return email;
	}
	string getPassword() {
		return password;
	}
	void setEmail(string email) {
		this->email = email;
	}
	void setPassword(string password) {
		this->password = password;
	}
	void display() {
		cout << "Email: " << email << endl;
		cout << "Password: " << password << endl;
	}
	bool check() {
		ifstream file;
		file.open("signup.txt");
		string line;
		while (getline(file, line)) {
			if (line == email) {
				getline(file, line);
				if (line == password) {
					file.close();
					return true;
				}
			}
		}
		file.close();
		return false;
	}
};