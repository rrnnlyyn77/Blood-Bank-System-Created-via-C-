#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdlib.h>

using namespace std;

void UpdateProfile() {
    string Email;
    string EstablishmentName;
    string Username;
    string ContactNumber;
    cout << "                                                                         Update Recipient Profile\n";
    cout << "\n";
    cout << "                          Provide updated information in the fields below. If a field does not require updated information, enter current information.\n";
    cout << "\n";
    cout << "                                                          Enter Updated Email             : ";
    cin.ignore();
    getline(cin, Email);
    cout << "                                                          Enter Updated Establishment Name: ";
    getline(cin, EstablishmentName);
    cout << "                                                          Enter Updated Username          : ";
    getline(cin, Username);
    cout << "                                                          Enter Updated Contact Number    : ";
    getline(cin, ContactNumber);

    ofstream profileFile("profile.txt");
    if (profileFile.is_open()) {
        profileFile << "Email: " << Email << endl;
        profileFile << "Establishment Name: " << EstablishmentName << endl;
        profileFile << "Username: " << Username << endl;
        profileFile << "Contact Number: " << ContactNumber << endl;
        cout << "\n";
        cout << "                                                            Recipient Profile updated successfully" << endl;
        profileFile.close();
    }
    else {
        cout << "Unable to open the profile file." << endl;
    }
}

void DeleteProfile() {
   
    ofstream profileFile("profile.txt");
    if (profileFile.is_open()) {
        profileFile.close();
        cout << "Profile deleted successfully!" << endl;
    }
    else {
        cout << "Unable to open the profile file." << endl;
    }
}

int main() {

    system("Color 4F");
    int choice;

    cout << "                                                                            Modify Recipient Profile" << endl;
    cout << "                                                                            ________________________" << endl;
    cout << "\n";
    cout << "                                                                       1. Update Information" << endl;
    cout << "                                                                       2. Delete Information" << endl;
    cout << "\n";
    cout << "                                                                       Enter your choice: ";
    cin >> choice;
    system("CLS");

    switch (choice) {
    case 1:
        UpdateProfile();
        break;
    case 2:
        DeleteProfile();
        break;
    default:
        cout << "Incorrect choice" << endl;
    }

    return 0;
}
