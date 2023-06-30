
#ifndef DISPLAY_DONOR_PROFILE_H
#define DISPLAY_DONOR_PROFILE_H


#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <iomanip>

using namespace std;

struct ViewProfile {
    string email,
        password,
        confirmPassword,
        fName,
        lName,
        DonorUsername,
        doB,
        mobileNo,
        donorID;
};

void DisplayProfile(const ViewProfile& profile);
ViewProfile FindProfileByUsername(const string& DonorUsername);

#endif // !DISPLAY_DONOR_PROFILE_H
