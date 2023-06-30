#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct VRequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    int NumBags;
};

void DisplayRequest(const VRequestForm& form);
void ViewRequestByUsername(const string& filename, const string& username);