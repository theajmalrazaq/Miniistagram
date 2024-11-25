#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class ForgetPassword {
private:
    string username;
public:
    ForgetPassword(string username) {
        this->username = username;
    }
    bool findAccount() {
        ifstream file("signup.txt");
        if (!file.is_open()) {
            cerr << "Unable to open file" << endl;
            return false;
        }

        string line;
        while (getline(file, line)) {
            if (line.find(username) != string::npos) {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }


    bool updatePassword(const string& newPassword) {
        ifstream file("signup.txt");
        if (!file.is_open()) {
            cerr << "Unable to open file" << endl;
            return false;
        }

        stringstream buffer;
        buffer << file.rdbuf();
        string content = buffer.str();
        file.close();

        size_t pos = content.find(username);
        if (pos == string::npos) {
            cerr << "Email not found" << endl;
            return false;
        }

        size_t endPos = content.find('\n', pos);
        string oldLine = content.substr(pos, endPos - pos);
        string newLine = username + " " + newPassword;

        content.replace(pos, oldLine.length(), newLine);

        ofstream outFile("signup.txt");
        if (!outFile.is_open()) {
            cerr << "Unable to open file" << endl;
            return false;
        }

        outFile << content;
        outFile.close();

        return true;
    }
};
