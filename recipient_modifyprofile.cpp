#include "recipient_modifyprofile.h"

void MRremoveSpaces(string& str) {
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

            //pass
            cout << "Enter new password: ";
            getline(cin, newPassword);
            MRremoveSpaces(newPassword);
            while (newPassword.empty()) {
                cout << "Field empty. Please enter a new password: ";
                getline(cin, newPassword);
                MRremoveSpaces(newPassword);
            }
            profile.Password = newPassword;
            //email
            cout << "Enter new email: ";
            getline(cin, newEmail);
            MRremoveSpaces(newEmail);
            while (newEmail.empty()) {
                cout << "Field empty. Please enter a new email: ";
                getline(cin, newEmail);
                MRremoveSpaces(newEmail);
            }
            profile.Email = newEmail;
            //est name
            cout << "Enter new establishment name: ";
            getline(cin, newEstablishmentName);
            MRremoveSpaces(newEstablishmentName);
            while (newEstablishmentName.empty()) {
                cout << "Field empty. Please enter a new establishment name: ";
                getline(cin, newEstablishmentName);
                MRremoveSpaces(newEstablishmentName);
            }
            profile.EstablishmentName = newEstablishmentName;
            //phone no.
            cout << "Enter new phone number: ";
            getline(cin, newPhone);
            MRremoveSpaces(newPhone);
            while (newPhone.empty()) {
                cout << "Field empty. Please enter a new phone number: ";
                getline(cin, newPhone);
                MRremoveSpaces(newPhone);
            }
            profile.Phone = newPhone;
            //new address
            cout << "Enter new NZ address: ";
            getline(cin, newAddress);
            MRremoveSpaces(newAddress);
            while (newAddress.empty()) {
                cout << "Field empty. Please enter a new NZ address: ";
                getline(cin, newAddress);
                MRremoveSpaces(newAddress);
            }
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
