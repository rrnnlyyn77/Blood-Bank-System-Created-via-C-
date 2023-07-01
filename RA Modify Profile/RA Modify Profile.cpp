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

void updateProfile(const string& username, vector<Profile>& profiles) {
    for (auto& profile : profiles) {
        if (profile.Username == username) {
            cout << " " << endl;
            cout << "Update Profile" << endl;
            cout << "______________" << endl;

            string newPassword, newEmail, newEstablishmentName, newPhone, newAddress;

            cout << "Enter new password: ";
            getline(cin, newPassword);
            removeSpaces(newPassword);
            profile.Password = newPassword;

            cout << "Enter new email: ";
            getline(cin, newEmail);
            removeSpaces(newEmail);
            profile.Email = newEmail;

            cout << "Enter new establishment name: ";
            getline(cin, newEstablishmentName);
            removeSpaces(newEstablishmentName);
            profile.EstablishmentName = newEstablishmentName;

            cout << "Enter new phone number: ";
            getline(cin, newPhone);
            removeSpaces(newPhone);
            profile.Phone = newPhone;

            cout << "Enter new NZ address: ";
            getline(cin, newAddress);
            removeSpaces(newAddress);
            profile.Address = newAddress;

            cout << "Profile updated successfully." << endl;
            return;
        }
    }

    cout << "Profile not found." << endl;
}

void deleteProfile(const string& username, vector<Profile>& profiles) {
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if (it->Username == username) {
            cout << "Are you sure you want to delete your profile? (Y/N): ";
            string confirm;
            getline(cin, confirm);

            if (confirm == "Y" || confirm == "y") {
                profiles.erase(it);
                cout << "Profile deleted successfully." << endl;
            }
            else {
                cout << "Profile deletion canceled." << endl;
            }

            return;
        }
    }

    cout << "Profile not found." << endl;
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
    cout << "Modify a Recipient Profile" << endl;
    cout << " " << endl;
    cout << "View Recipient Profile:" << endl;
    cout << " " << endl;
    cout << "Enter your Username: ";
    getline(cin, username);

    displayProfile(username, profiles);

    cout << endl;
    cout << "Modify Recipient Profile Menu" << endl;
    cout << "1. Update Profile" << endl;
    cout << "2. Delete Profile" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1:
        updateProfile(username, profiles);
        break;
    case 2:
        deleteProfile(username, profiles);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }


    ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        cout << "Failed to open the profile file for writing." << endl;
        return 1;
    }

    for (const auto& profile : profiles) {
        outputFile << "Username: " << profile.Username << endl;
        outputFile << "Password: " << profile.Password << endl;
        outputFile << "Email: " << profile.Email << endl;
        outputFile << "Establishment Name: " << profile.EstablishmentName << endl;
        outputFile << "Phone: " << profile.Phone << endl;
        outputFile << "NZ Address: " << profile.Address << endl;
        outputFile << endl;
    }

    outputFile.close();

    return 0;
}


