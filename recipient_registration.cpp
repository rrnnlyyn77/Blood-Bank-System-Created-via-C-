#include "recipient_registration.h"

bool validateEstName(std::string& establishmentName)
{
    std::regex fNameValidation("[A-Za-z\\s]{1,50}");
    return std::regex_match(establishmentName, fNameValidation);
}

//removed validateEmail (already defined in donor_registration.cpp)

bool validateContactNo(std::string& nzContactNo)
{
    //for new recipient number validation
    std::regex nzNoValidation("\\d{4} \\d{4,7}");
    return regex_match(nzContactNo, nzNoValidation);

    std::regex nzLandlineValidation("^(0800|09)\\{7}$");
    return regex_match(nzContactNo, nzLandlineValidation);

    //for new donor mobile no. validation
    std::regex nzmobNoValidation("\\+?64[- ]?\\d{1,4}[- ]?\\d{4,10}");
    return regex_match(nzContactNo, nzmobNoValidation);

 
}

//removed validatePassword (already defined in donor_registration.cpp)

//removed validateUsername (already defined in donor_registration.cpp)


bool validateNZAddress(const std::string& address)
{
    std::regex nzAddressValidation(R"(^\d+\s[A-Za-z\s]+\s[A-Za-z]+\s[A-Za-z\s]+\d{4}$)");
    return regex_match(address, nzAddressValidation);
}

void saveRecipientDetails(const newRecipient& recipient)
{
    std::ofstream file("recipient_details.txt", std::ios::app);  // Open the file in append mode

    if (file.is_open()) {
        file << "\n";
        file << "Username: " << recipient.userName << std::endl;
        file << "Password: " << recipient.password << std::endl;
        file << "Email: " << recipient.email << std::endl;
        file << "Establishment Name: " << recipient.establishmentName << std::endl;
        file << "Phone: " << recipient.contactNo << std::endl;
        file << "NZ Address: " << recipient.address << std::endl;

        file.close();
    }
    else {
        std::cout << "Unable to open the file.";
    }
}

void getNewRecipientDetails(newRecipient& Newrecipient)
{
    std::cout << std::setw(88) << std::right << "Create a Recipient Profile Today!!!" << std::endl;
    std::cout << "\n\n";

    std::cout << std::setw(88) << std::right << "Please provide an email address        : ";
    std::getline(std::cin, Newrecipient.email);
    std::cout << std::setw(88) << std::right << "Create a password (min. 8 characters)  : ";
    std::getline(std::cin, Newrecipient.password);
    std::cout << std::setw(88) << std::right << "Confirm Password                       : ";
    std::getline(std::cin, Newrecipient.confirmPassword);
    std::cout << std::setw(88) << std::right << "Estblishment Name                      : ";
    std::getline(std::cin, Newrecipient.establishmentName);
    std::cout << std::setw(88) << std::right << "Provide a username (min. 4 characters) : ";
    std::getline(std::cin, Newrecipient.userName);
    std::cout << std::setw(88) << std::right << "NZ Phone/Landline Number               : ";
    std::getline(std::cin, Newrecipient.contactNo);
    std::cout << std::setw(88) << std::right << "New Zealand Address                    : ";
    std::getline(std::cin, Newrecipient.address);

    // Validate input
    if (validateEmail(Newrecipient.email) && validatePassword(Newrecipient.password) && Newrecipient.password == Newrecipient.confirmPassword &&
        validateEstName(Newrecipient.establishmentName) && validateUsername(Newrecipient.userName) &&
        validateContactNo(Newrecipient.contactNo) && validateNZAddress(Newrecipient.address)) {
        // Save recipient details to file
        saveRecipientDetails(Newrecipient);
    }
    else {
        std::cout << "\n";
        std::cout << std::setw(80) << std::right << "Invalid input. Please restart. ";
        std::system("pause");
        std::system("cls");
        getNewRecipientDetails(Newrecipient);
    }
}

bool recipientLogin(const std::string& username, const std::string& password) {
    std::ifstream file("recipient_details.txt");

    std::string line;
    bool found = false;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.find("Username: " + username) != std::string::npos) {
                std::getline(file, line);  // Read the next line (Password)
                if (line.find("Password: " + password) != std::string::npos) {
                    found = true;
                    break;
                }
            }
        }

        file.close();
    }
    else {
        std::cout << "Unable to open the file.";
    }

    return found;
}
