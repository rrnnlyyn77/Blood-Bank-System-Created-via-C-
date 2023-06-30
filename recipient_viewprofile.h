#ifndef RECIPIENT_VIEWPROFILE_H
#define RECIPIENT_VIEWPROFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

struct RProfile {
    string RUsername;
    string RPassword;
    string REmail;
    string REstablishmentName;
    string RPhone;
    string RAddress;
};


void removeSpaces(string& str);
void displayProfile(const string& Rusername, const vector<RProfile>& rprofiles);


#endif // !RECIPIENT_VIEWPROFILE_H
