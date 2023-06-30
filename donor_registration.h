#ifndef DONOR_REGISTRATION_H
#define DONOR_REGISTRATION_H

#include <string>

//new donor details
struct newDonor {
    std::string email,
        nDpassword,
        confirmPassword,
        fName,
        lName,
        nDuserName,
        doB,
        mobileNo,
        donorID;
};

bool validateDate(std::string& doB);
bool validateFname(std::string& fName);
bool validateLname(std::string& lName);
bool validateEmail(std::string& email);
bool validateContactNo(std::string& nzContactNo);
bool validatePassword(std::string& nDpassword);
bool validateUsername(std::string& userN);
bool validateDonorID(std::string& donorID);
void saveDonorDetails(const newDonor& donor);
void getNewDonorDetails(newDonor& Newdonor);
bool donorLogin(const std::string& nDuserName, const std::string& nDpassword);

#endif  // DONOR_REGISTRATION_H
