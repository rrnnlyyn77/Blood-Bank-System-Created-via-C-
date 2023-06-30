#pragma once

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

void MRremoveSpaces(string& str);
void displayProfile(const string& username, const vector<Profile>& profiles);
void updateProfile(const string& username, vector<Profile>& profiles);
void deleteProfile(const string& username, vector<Profile>& profiles);