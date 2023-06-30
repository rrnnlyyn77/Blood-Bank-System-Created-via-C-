#include "display_donor_profile.h"

void DisplayProfile(const ViewProfile& profile) {
    cout << setw(80) << "Username               : " << profile.DonorUsername << endl;
    cout << setw(80) << "Password               : " << profile.password << endl;
    cout << setw(80) << "Email                  : " << profile.email << endl;
    cout << setw(80) << "First Name             : " << profile.fName << endl;
    cout << setw(80) << "Last Name              : " << profile.lName << endl;
    cout << setw(80) << "Date of Birth          : " << profile.doB << endl;
    cout << setw(80) << "Mobile Phone Number    : " << profile.mobileNo << endl;
    cout << setw(80) << "Donor ID               : " << profile.donorID << endl;
}

ViewProfile FindProfileByUsername(const string& username) {
    ifstream inputFile("donor_details.txt");
    ViewProfile profile;

    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return profile;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.find("Username: " + username) != string::npos) {
            profile.DonorUsername = line.substr(10);
            getline(inputFile, line);
            profile.password = line.substr(10);
            getline(inputFile, line);
            profile.email = line.substr(7);
            getline(inputFile, line);
            profile.fName = line.substr(12);
            getline(inputFile, line);
            profile.lName = line.substr(11);
            getline(inputFile, line);
            profile.doB = line.substr(15);
            getline(inputFile, line);
            profile.mobileNo = line.substr(21);
            getline(inputFile, line);
            profile.donorID = line.substr(10);
            break;
        }
    }

    inputFile.close();
    return profile;
}