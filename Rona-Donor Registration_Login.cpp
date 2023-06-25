// new donotr registration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <cstdlib>
using namespace std;

//to validate doB (dd//mm//yy)
bool validateDate(string& doB)
{
    regex datepattern("^\\d{2}/\\d{2}/\\d{2}$");
    return regex_match(doB, datepattern);
}
//to validate first name
bool validateFname(string& fName)
{
    regex fNameValidation("[A-Za-z]{1,50}");
    return regex_match(fName, fNameValidation);
}
//to validate last name
bool validateLname(string& lName)
{
    regex lNameValidation("[A-Za-z]{1,50}");
    return regex_match(lName, lNameValidation);
}
//to validate email
bool validateEmail(string& email)
{
    regex emailValidation("([a-zA-z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    return regex_match(email, emailValidation);
}
//to validate contact no. (mobile & landline)
bool validateContactNo(string& nzContactNo)
{
    regex nzNoValidation("\\+?64[- ]?\\d{1,4}[- ]?\\d{4,10}");
    return regex_match(nzContactNo, nzNoValidation);

    regex nzLandlineValidation("^(0800|09)\\{7}$");
    return regex_match(nzContactNo, nzLandlineValidation);
}
//to validate password
bool validatePassword(string& password)
{
    regex passwordValidation("([a-zA-Z0-9@#$%^&+=]{10,})");//10 characters minimum
    return regex_match(password, passwordValidation);
}
// to validate username
bool validateUsername(string& userN)
{
    regex userNValidation("([a-zA-Z0-9_]{6,})"); //6characters minimum
    return regex_match(userN, userNValidation);
}
//to validate NZBlood donor ID (2 letters, 6 nos.)
bool validateDonorID(string& donorID)
{
    regex donorIDValidation("^[A-Z]{2}\\d{6}$");
    return regex_match(donorID, donorIDValidation);
}


//new donor details
struct newDonor {
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

void saveDonorDetails(const newDonor& donor) {
    ofstream file("donor_details.txt", ios::app);  // Open the file in append mode

    if (file.is_open()) {
        file << "Username: " << donor.userName << endl;
        file << "Password: " << donor.password << endl;
        file << "Email: " << donor.email << endl;
        file << "First Name: " << donor.fName << endl;
        file << "Last Name: " << donor.lName << endl;
        file << "Date of Birth: " << donor.doB << endl;
        file << "Mobile Phone Number: " << donor.mobileNo << endl;
        file << "Donor ID: " << donor.donorID << endl;

        file.close();
    }
    else {
        cout << "Unable to open the file.";
    }
}

void getNewDonorDetails(newDonor& Newdonor) {
    // ...

    cout << "Create a Donor Profile Today!!!" << endl;
    cout << "\n\n";

    cout << "Email : "; getline(cin, Newdonor.email);
    cout << "Password (min. 6 characters, contain 1 letter, 1 number) : ";
    getline(cin, Newdonor.password);
    cout << "Confirm Password : "; getline(cin, Newdonor.confirmPassword);
    cout << "First Name : "; getline(cin, Newdonor.fName);
    cout << "Last Name : "; getline(cin, Newdonor.lName);
    cout << "Provide a username : "; getline(cin, Newdonor.userName);
    cout << "Date of Birth : "; getline(cin, Newdonor.doB);
    cout << "Mobile Phone Number (starting with +64) : "; getline(cin, Newdonor.mobileNo);
    cout << "Donor ID (optional) : "; getline(cin, Newdonor.donorID);

    // Validate input

    if (validateEmail(Newdonor.email) && validatePassword(Newdonor.password) && Newdonor.password == Newdonor.confirmPassword &&
        validateFname(Newdonor.fName) && validateLname(Newdonor.lName) && validateUsername(Newdonor.userName) &&
        validateDate(Newdonor.doB) && validateContactNo(Newdonor.mobileNo) && validateDonorID(Newdonor.donorID)) {

        // Save donor details to file
        saveDonorDetails(Newdonor);

        // ...
    }
    else {
        cout << "Invalid input. Please try again." << endl;
    }
}
bool login(const string& username, const string& password) {
    ifstream file("donor_details.txt");

    string line;
    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line.find("Username: " + username) != string::npos) {
                getline(file, line);  // Read the next line (Password)
                if (line.find("Password: " + password) != string::npos) {
                    found = true;
                    break;
                }
            }
        }

        file.close();
    }
    else {
        cout << "Unable to open the file.";
    }

    return found;
}



int main() {
    // ...

    newDonor donor;

    // Register a new donor
    getNewDonorDetails(donor);

    // Save donor details to file
    saveDonorDetails(donor);

    // Clear the screen
    system("CLS");

    // Fill in health status form


    // Prompt for login
    string username, password;
    cout << "Login\n";
    cout << "Username: ";
    getline(cin, username);
    cout << "Password: ";
    getline(cin, password);

    if (login(username, password)) {
        cout << "Login successful!" << endl;
        // Call the function to fill the health status form and save the file
        // ...
    }
    else {
        cout << "Invalid username or password." << endl;
    }

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
