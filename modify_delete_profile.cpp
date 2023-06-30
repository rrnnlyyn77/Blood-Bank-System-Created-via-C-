#include "modify_delete_profile.h"


vector<donorProfile> LoadProfiles() {
    vector<donorProfile> profiles;
    ifstream file("donor_details.txt");
    if (file.is_open()) {
        string line;
        donorProfile profile;


        while (getline(file, line)) {
            if (line.find("Username: ") != string::npos) {
                profile.userName = line.substr(line.find("Username: ") + 10);
            }
            else if (line.find("Password: ") != string::npos) {
                profile.password = line.substr(line.find("Password: ") + 10);
            }
            else if (line.find("Email: ") != string::npos) {
                profile.email = line.substr(line.find("Email: ") + 7);
            }
            else if (line.find("First Name: ") != string::npos) {
                profile.fName = line.substr(line.find("First Name: ") + 12);
            }
            else if (line.find("Last Name: ") != string::npos) {
                profile.lName = line.substr(line.find("Last Name: ") + 11);
            }
            else if (line.find("Date of Birth: ") != string::npos) {
                profile.doB = line.substr(line.find("Date of Birth: ") + 15);
            }
            else if (line.find("Mobile Phone Number: ") != string::npos) {
                profile.mobileNo = line.substr(line.find("Mobile Phone Number: ") + 21);
            }
            else if (line.find("Donor ID: ") != string::npos) {
                profile.donorID = line.substr(line.find("Donor ID: ") + 10);
            }
            else if (line.find("") != std::string::npos) {
                profiles.push_back(profile);
            }
        }
        file.close();
    }
    return profiles;
}


void SaveProfiles(const vector<donorProfile>& profiles) {
    ofstream file("donor_details.txt");
    if (file.is_open()) {
        for (const donorProfile& profile : profiles) {
            file << "Username: " << profile.userName << endl;
            file << "Password: " << profile.password << endl;
            file << "Email: " << profile.email << endl;
            file << "First Name: " << profile.fName << endl;
            file << "Last Name: " << profile.lName << endl;
            file << "Date of Birth: " << profile.doB << endl;
            file << "Mobile Phone Number: " << profile.mobileNo << endl;
            file << "Donor ID: " << profile.donorID << endl;
            file << " " << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open the file." << endl;
    }
}

void UpdateProfile() {
    string username;
    cout << setw(82) << right << "Enter your Username   : ";
    cin.ignore();
    getline(cin, username);



    vector<donorProfile> profiles = LoadProfiles();
    bool found = false;



    for (donorProfile& profile : profiles) {
        if (profile.userName == username) {
            found = true;

            cout << "\n\n";
            cout << setw(88) << right << "Original Profile Information ";
            cout << "\n";
            cout << setw(87) << right << "-----------------------------";
            cout << "\n\n";


            cout << setw(80) << "Username                : " << profile.userName << endl;
            cout << setw(80) << "Password                : " << profile.password << endl;
            cout << setw(80) << "Email                   : " << profile.email << endl;
            cout << setw(80) << "First Name              : " << profile.fName << endl;
            cout << setw(80) << "Last Name               : " << profile.lName << endl;
            cout << setw(80) << "Date of Birth           : " << profile.doB << endl;
            cout << setw(80) << "Mobile Phone Number     : " << profile.mobileNo << endl;
            cout << setw(80) << "Donor ID                : " << profile.donorID << endl;



            string email,
                password,
                confirmPassword,
                fName,
                lName,
                userName,
                doB,
                mobileNo,
                donorID;

            cout << "\n\n";
            cout << setw(85) << right << "Update Information Form";
            cout << "\n";
            cout << setw(87) << right << "-----------------------------";
            cout << "\n\n";

            cout << setw(80) << "Enter *Updated* Password          : ";
            getline(cin, password);
            cout << setw(80) << "Enter *Updated* Email             : ";
            getline(cin, email);
            cout << setw(80) << "Enter *Updated* First Name        : ";
            getline(cin, fName);
            cout << setw(80) << "Enter *Updated* Last Name         : ";
            getline(cin, lName);
            cout << setw(80) << "Enter *Updated* Date of Birth     : ";
            getline(cin, doB);
            cout << setw(80) << "Enter *Updated* Mobile No         : ";
            getline(cin, mobileNo);
            cout << setw(80) << "Enter *Updated* Donor ID          : ";
            getline(cin, donorID);



            if (!password.empty()) {
                profile.password = password;
            }
            if (!email.empty()) {
                profile.email = email;
            }
            if (!fName.empty()) {
                profile.fName = fName;
            }
            if (!lName.empty()) {
                profile.lName = lName;
            }
            if (!doB.empty()) {
                profile.doB = doB;
            }
            if (!mobileNo.empty()) {
                profile.mobileNo = mobileNo;
            }
            if (!donorID.empty()) {
                profile.donorID = donorID;
            }

            cout << "\n";
            cout << setw(80) << "Profile updated successfully." << endl;
            break;
        }
    }



    if (!found) {
        cout << "Profile not found." << endl;
    }
    else {
        SaveProfiles(profiles);
    }
}


void DeleteProfile() {
    string username;
    cout << setw(82) << right << "Enter your Username   : ";
    cin.ignore();
    getline(cin, username);



    vector<donorProfile> profiles = LoadProfiles();
    bool found = false;



    for (size_t i = 0; i < profiles.size(); i++) {
        if (profiles[i].userName == username) {
            found = true;

            cout << "\n";
            cout << setw(80) << right << "Donor Profile" << "\n\n";

            cout << setw(80) << "Username                : " << profiles[i].userName << endl;
            cout << setw(80) << "Password                : " << profiles[i].password << endl;
            cout << setw(80) << "Email                   : " << profiles[i].email << endl;
            cout << setw(80) << "First Name              : " << profiles[i].fName << endl;
            cout << setw(80) << "Last Name               : " << profiles[i].lName << endl;
            cout << setw(80) << "Date of Birth           : " << profiles[i].doB << endl;
            cout << setw(80) << "Mobile Phone Number     : " << profiles[i].mobileNo << endl;
            cout << setw(80) << "Donor ID                : " << profiles[i].donorID << endl;
            cout << "\n\n";

            char confirm;
            cout << setw(102) << "Do you wish to delete this donor's profile? (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {
                profiles.erase(profiles.begin() + i);
                cout << setw(80) << "Profile deleted successfully." << endl;
                break;
            }
            else {
                cout << setw(83) << "Profile not deleted." << endl;
                break;
            }
        }
    }


    if (!found) {
        cout << "Profile not found." << endl;
    }
    else {
        SaveProfiles(profiles);
    }
}