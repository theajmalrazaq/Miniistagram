#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Signup {
	string FirstName;
	string LastName;
	string username;
	string dob;
	string email;
	string password;
public:
	Signup(string FirstName, string LastName, string username, string dob, string email, string password) {
		this->FirstName = FirstName;
		this->LastName = LastName;
		this->username = username;
		this->dob = dob;
		this->email = email;
		this->password = password;
	}
	string getFirstName() {
		return FirstName;
	}
	string getLastName() {
		return LastName;
	}
	string getUsername() {
		return username;
	}
	string getDob() {
		return dob;
	}
	string getEmail() {
		return email;
	}
	string getPassword() {
		return password;
	}
	void setFirstName(string FirstName) {
		this->FirstName = FirstName;
	}
	void setLastName(string LastName) {
		this->LastName = LastName;
	}
	void setUsername(string username) {
		this->username = username;
	}
	void setDob(string dob) {
		this->dob = dob;
	}
	void setEmail(string email) {
		this->email = email;
	}
	void setPassword(string password) {
		this->password = password;
	}
	void display() {
		cout << "First Name: " << FirstName << endl;
		cout << "Last Name: " << LastName << endl;
		cout << "Username: " << username << endl;
		cout << "Date of Birth: " << dob << endl;
		cout << "Email: " << email << endl;
		cout << "Password: " << password << endl;
	}
	void save() {
		ofstream file;
		file.open("signup.txt", ios::app);
		file << FirstName << " " << LastName << " " << username << " " << dob << " " << email << " " << password << endl;
		file.close();
	}
};	