
#ifndef MODIFY_DELETE_PROFILE_H
#define MODIFY_DELETE_PROFILE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct donorProfile {
    string email,
        password,
        confirmPassword,
        fName,
        lName,
        userName,
        doB,
        mobileNo,
        donorID;
};

vector<donorProfile> LoadProfiles();
void SaveProfiles(const vector<donorProfile>& profiles);
void UpdateProfile();
void DeleteProfile();

#endif // !MODIFY_DELETE_PROFILE_H
