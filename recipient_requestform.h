#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
#include <stdlib.h> 
#include <regex>

using namespace std;

struct RequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    string NumBags;

};

void SubmitReqForm(const RequestForm& form);