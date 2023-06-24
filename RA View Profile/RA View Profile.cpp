#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct ViewProfile {
    string Email;
    string EstablishmentName;
    string Username;
    string ContactNumber;
};

int main() {

    system("Color 4F");

    ifstream inputFile("View Profile.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open the profile file." << endl;
        return 1;
    }

    ViewProfile profile;

    string read;
    while (getline(inputFile, read)) {
        size_t colonPos = read.find(':');
        if (colonPos != string::npos) {
            string key = read.substr(0, colonPos);
            string value = read.substr(colonPos + 2);

            if (key == "Email")
                profile.Email = value;
            else if (key == "Establishment Name")
                profile.EstablishmentName = value;
            else if (key == "Username")
                profile.Username = value;
            else if (key == "Contact Number")
                profile.ContactNumber = value;
        }
    }

    inputFile.close();
    cout << "                                                                          Recipients Profile\n";
    cout << "                                                                          _________________\n";
    cout << "\n";
    cout << "                                                               Email               : " << profile.Email << endl;
    cout << "                                                               Establishment Name  : " << profile.EstablishmentName << endl;
    cout << "                                                               Username            : " << profile.Username << endl;
    cout << "                                                               Contact Number      : " << profile.ContactNumber << endl;

    return 0;
}
