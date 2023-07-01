#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct Profile {
    string Username;
    string Password;
    string Email;
    string EstablishmentName;
    string Phone;
    string Address;
};

void removeSpaces(string& str) {
    size_t start = str.find_first_not_of(' ');
    if (start != string::npos) {
        str = str.substr(start);
    }

    size_t end = str.find_last_not_of(' ');
    if (end != string::npos) {
        str = str.substr(0, end + 1);
    }
}

void displayProfile(const string& username, const vector<Profile>& profiles) {
    bool profileFound = false;

    for (const auto& profile : profiles) {
        if (profile.Username == username) {
            cout << " " << endl;
            cout << "Recipient Profile" << endl;
            cout << "_________________" << endl;
            cout << "Username            : " << profile.Username << endl;
            cout << "Password            : " << profile.Password << endl;
            cout << "Email               : " << profile.Email << endl;
            cout << "Establishment Name  : " << profile.EstablishmentName << endl;
            cout << "Phone               : " << profile.Phone << endl;
            cout << "NZ Address          : " << profile.Address << endl;

            profileFound = true;
            break;
        }
    }

    if (!profileFound) {
        cout << "Profile not found." << endl;
    }
}

int main() {
    system("Color 4F");

    string fileName = "recipient_details.txt";
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Failed to open the profile file." << endl;
        return 1;
    }

    vector<Profile> profiles;
    Profile profile;

    string line;
    while (getline(inputFile, line)) {
        if (line.find("Username:") != string::npos) {
            profile.Username = line.substr(line.find(":") + 1);
            removeSpaces(profile.Username);
        }
        else if (line.find("Password:") != string::npos) {
            profile.Password = line.substr(line.find(":") + 1);
            removeSpaces(profile.Password);
        }
        else if (line.find("Email:") != string::npos) {
            profile.Email = line.substr(line.find(":") + 1);
            removeSpaces(profile.Email);
        }
        else if (line.find("Establishment Name:") != string::npos) {
            profile.EstablishmentName = line.substr(line.find(":") + 1);
            removeSpaces(profile.EstablishmentName);
        }
        else if (line.find("Phone:") != string::npos) {
            profile.Phone = line.substr(line.find(":") + 1);
            removeSpaces(profile.Phone);
        }
        else if (line.find("NZ Address:") != string::npos) {
            profile.Address = line.substr(line.find(":") + 1);
            removeSpaces(profile.Address);
            profiles.push_back(profile);
            profile = Profile();
        }
    }

    inputFile.close();

    string username;
    cout << "Welcome Recipient Administrator" << endl;
    cout << " " << endl;
    cout << "View Recipients Profile" << endl;
    cout << " " << endl;
    cout << "Enter the Recipients Username: ";
    getline(cin, username);

    displayProfile(username, profiles);

    return 0;
}

