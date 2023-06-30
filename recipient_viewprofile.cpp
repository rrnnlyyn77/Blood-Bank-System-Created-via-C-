#include "recipient_viewprofile.h"

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

void displayProfile(const string& rusername, const vector<RProfile>& rprofiles) {
    bool RprofileFound = false;

    for (const auto& Rprofile : rprofiles) {
        if (Rprofile.RUsername == rusername) {
            cout << " " << endl;
            cout << "Recipient Profile" << endl;
            cout << "_________________" << endl;
            cout << "Username            : " << Rprofile.RUsername << endl;
            cout << "Password            : " << Rprofile.RPassword << endl;
            cout << "Email               : " << Rprofile.REmail << endl;
            cout << "Establishment Name  : " << Rprofile.REstablishmentName << endl;
            cout << "Phone               : " << Rprofile.RPhone << endl;
            cout << "NZ Address          : " << Rprofile.RAddress << endl;

            RprofileFound = true;
            break;
        }
    }

    if (!RprofileFound) {
        cout << "Profile not found." << endl;
    }
}
