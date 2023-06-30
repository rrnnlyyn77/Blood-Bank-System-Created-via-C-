#include "donor_registration.h"

#include <iostream>
#include <regex>
#include <fstream>
#include <iomanip>

// Function to validate date (dd/mm/yy)
bool validateDate(std::string& doB) {
    std::regex datePattern("^\\d{2}/\\d{2}/\\d{2}$");
    return std::regex_match(doB, datePattern);
}

// Function to validate first name
bool validateFname(std::string& fName) {
    std::regex fNameValidation("[A-Za-z]{1,50}");
    return std::regex_match(fName, fNameValidation);
}

// Function to validate last name
bool validateLname(std::string& lName) {
    std::regex lNameValidation("[A-Za-z]{1,50}");
    return std::regex_match(lName, lNameValidation);
}

// Function to validate email
bool validateEmail(std::string& email) {
    std::regex emailValidation("([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,})");
    return std::regex_match(email, emailValidation);
}

// Function to validate contact no. (mobile & landline)
bool validateDNContactNo(std::string& nzContactNo) {
    std::regex nzNoValidation("\\+?64[- ]?\\d{1,4}[- ]?\\d{4,10}");
    return std::regex_match(nzContactNo, nzNoValidation);
}
// Function to validate password
bool validatePassword(std::string& nDpassword) {
    std::regex passwordValidation("([a-zA-Z0-9@#$%^&+=]{8,})"); // 8 characters minimum
    return std::regex_match(nDpassword, passwordValidation);
}

// Function to validate username
bool validateUsername(std::string& userN) {
    std::regex userNValidation("([a-zA-Z0-9_]{4,})"); // 4 characters minimum
    return std::regex_match(userN, userNValidation);
}

// Function to validate NZBlood donor ID (2 letters, 6 numbers)
bool validateDonorID(std::string& donorID) {
    std::regex donorIDValidation("^[A-Z]{2}\\d{6}$");
    return std::regex_match(donorID, donorIDValidation);
}

// Function to save donor details to file
void saveDonorDetails(const newDonor& donor) {
    std::ofstream file("donor_details.txt", std::ios::app); // Open the file in append mode

    if (file.is_open()) {
        file << "\n";
        file << "Username: " << donor.nDuserName << std::endl;
        file << "Password: " << donor.nDpassword << std::endl;
        file << "Email: " << donor.email << std::endl;
        file << "First Name: " << donor.fName << std::endl;
        file << "Last Name: " << donor.lName << std::endl;
        file << "Date of Birth: " << donor.doB << std::endl;
        file << "Mobile Phone Number: " << donor.mobileNo << std::endl;
        file << "Donor ID: " << donor.donorID << std::endl;

        file.close();
    }
    else {
        std::cout << "Unable to open the file." << std::endl;
    }
}

// Function to get new donor details
void getNewDonorDetails(newDonor& Newdonor) {
    std::cout << std::setw(88) << std::right << "Create a Donor Profile Today!!!" << std::endl;
    std::cout << "\n\n";

    std::cout << std::setw(88) << std::right << "Please provide an email address        : ";
    std::getline(std::cin, Newdonor.email);
    std::cout << std::setw(88) << std::right << "Create a password (min. 8 characters)  : ";
    std::getline(std::cin, Newdonor.nDpassword);
    std::cout << std::setw(88) << std::right << "Confirm Password                       : ";
    std::getline(std::cin, Newdonor.confirmPassword);
    std::cout << std::setw(88) << std::right << "First Name                             : ";
    std::getline(std::cin, Newdonor.fName);
    std::cout << std::setw(88) << std::right << "Last Name                              : ";
    std::getline(std::cin, Newdonor.lName);
    std::cout << std::setw(88) << std::right << "Provide a username (min. 4 characters) : ";
    std::getline(std::cin, Newdonor.nDuserName);
    std::cout << std::setw(88) << std::right << "Date of Birth (dd/mm/yy)               : ";
    std::getline(std::cin, Newdonor.doB);
    std::cout << std::setw(88) << std::right << "NZ Mobile Number (starting with +64)   : ";
    std::getline(std::cin, Newdonor.mobileNo);
    std::cout << std::setw(88) << std::right << "Enter your Donor ID (if known)         : ";
    std::getline(std::cin, Newdonor.donorID);

    // Validate input
    if (validateEmail(Newdonor.email) && validatePassword(Newdonor.nDpassword) && Newdonor.nDpassword == Newdonor.confirmPassword &&
        validateFname(Newdonor.fName) && validateLname(Newdonor.lName) && validateUsername(Newdonor.nDuserName) &&
        validateDate(Newdonor.doB) && validateDNContactNo(Newdonor.mobileNo)) {

        // Save donor details to file
        saveDonorDetails(Newdonor);
    }
    else {
        std::cout << "\n";
        std::cout << std::setw(80) << std::right << "Invalid input. Please restart. ";
        std::system("pause");
        std::system("cls");
        getNewDonorDetails(Newdonor);
    }
}

// Function to perform login
bool donorLogin(const std::string& username, const std::string& password) {
    std::ifstream file("donor_details.txt");

    std::string line;
    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("Username: " + username) != std::string::npos) {
                getline(file, line); // Read the next line (Password)
                if (line.find("Password: " + password) != std::string::npos) {
                    found = true;
                    break;
                }
            }
        }

        file.close();
    }
    else {
        std::cout << "Unable to open the file." << std::endl;
    }

    return found;
}
