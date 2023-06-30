
#ifndef RECIPIENT_REGISTRATION_H
#define RECIPIENT_REGISTRATION_H

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <cstdlib>
#include <iomanip>

// New recipient details
struct newRecipient {
    std::string email,
        password,
        confirmPassword,
        establishmentName,
        userName,
        contactNo,
        address;
};

// Function declarations
bool validateEstName(std::string& establishmentName);
bool validateEmail(std::string& email);
bool validateContactNo(std::string& nzContactNo);
bool validatePassword(std::string& password);
bool validateUsername(std::string& userN);
bool validateNZAddress(const std::string& address);
void saveRecipientDetails(const newRecipient& recipient);
void getNewRecipientDetails(newRecipient& Newrecipient);
bool recipientLogin(const std::string& username, const std::string& password);

#endif  // RECIPIENT_REGISTRATION_H
