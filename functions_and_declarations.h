#ifndef FUNCTIONS_AND_DECLARATIONS_H
#define FUNCTIONS_AND_DECLARATIONS_H

//main

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

//booleans
//to validate date (dd//mm//yy)
bool validateDate(string& doB);

//to validate first name
bool validateFname(string& fName);

//to validate last name
bool validateLname(string& lName);

//to validate email
bool validateEmail(string& email);

//to validate donor contact no. (mobile & landline)
bool validateContactNo(string& nzContactNo);

//to validate password
bool validatePassword(string& password);

// to validate username
bool validateUsername(string& userN);

//to validate NZBlood donor ID (2 letters, 6 nos.)
bool validateDonorID(string& donorID);

//to validate NZ address
bool validateNZAddress(const std::string& address);

//to validate establishment name
bool validateEstName(string& establishmentName);

//to validate recipient contact no. (mobile & landline)
bool validateRContactNo(string& RcontactNo);



//donor
//new donor registration
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

void saveDonorDetails(const newDonor& donor);
void getNewDonorDetails(newDonor& Newdonor);
bool login(const string& username, const string& password);
void registerAndLogin();

//view profile (donor)
struct ViewProfile {
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

void DisplayProfile(const ViewProfile& profile);
ViewProfile FindProfileByUsername(const string& username);
void ViewDonorProfile();

//modify profile (donor)
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

void ModifyMenu();
vector<donorProfile> LoadProfiles();
void SaveProfiles(const vector<donorProfile>& profiles);
void UpdateProfile();
void DeleteProfile();
void modifyDonorProfile();

//**********book appt donor**********
struct Appointment {
    std::string BAusername;
    std::string BAeligibilityForm;
    std::string BAdate;
    std::string BAtime;
    std::string BAdonationType;
    std::string BAbloodType;
    std::string BAstatus = "Pending";
};

bool isAppointmentAvailable(const std::vector<Appointment>& BAappointments, const std::string& date, const std::string& time);
void addAppointment(std::vector<Appointment>& BAappointments, const Appointment& appointment);
void saveAppointmentsToFile(const std::string& filename, const std::vector<Appointment>& BAappointments);
void displayConfirmationMessage();
void displayError(const std::string& message);
void bookAppointment();

//donor admin
//***********DISPLAY APPOINTMENTS******

#include <vector>
#include <map>
#include <limits>

struct DAviewAppointment {
    string username;
    string eligibilityForm;
    string date;
    string time;
    string donationType;
    string bloodType;
    string apptStatus;
};

void loadAppointmentsFromFile(const string& filename, vector<DAviewAppointment>& appointments);
void displayAppointments(const vector<DAviewAppointment>& appointments);
void displayCompletedAppointments(const vector<DAviewAppointment>& appointments);
void deleteAppointment(int index, vector<DAviewAppointment>& appointments, const string& pendingFilename, const string& completedFilename);
map<string, int> countDonationTypes(const vector<DAviewAppointment>& appointments);
void recordDonationInventory(const vector<DAviewAppointment>& appointments, const string& filename);
void displayDonationTypeInventory(const vector<DAviewAppointment>& appointments);


//recipient
//**********new recipient registration***********
struct newRecipient {
    string email,
        password,
        confirmPassword,
        establishmentName,
        userName,
        RcontactNo,
        address;
};

void saveRecipientDetails(const newRecipient& recipient);
void getNewRecipientDetails(newRecipient& Newrecipient);
bool Rlogin(const string& username, const string& password);
void recipientRegistrationAndLogin();


//******view recipient profile**********

struct Profile {
    string Username;
    string Password;
    string Email;
    string EstablishmentName;
    string Phone;
    string Address;
};

void removeSpaces(string& str);
void displayProfile(const string& username, const vector<Profile>& profiles);
void viewRecipientProfile();


//***********modify recipient profile******
struct MRProfile {
    string MRUsername;
    string MRPassword;
    string MREmail;
    string MREstablishmentName;
    string MRPhone;
    string MRAddress;
};

void removeSpaces(string& str);
void displayProfile(const string& MRusername, const vector<MRProfile>& MRprofiles);
void updateProfile(const string& MRusername, vector<MRProfile>& MRprofiles);
void deleteProfile(const string& username, vector<MRProfile>& profiles);
void modifyRecipientProfile();

//*****request form******
struct RequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    int NumBags;

};

void SubmitReqForm(const RequestForm& form);
void requestBloodRecipientForm();

//*****view request*****
struct viewRRequestForm{
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    int NumBags;
};

void DisplayRequest(const viewRRequestForm& form);
void ViewRequestByUsername(const string& filename, const string& username);
void viewRRequests();

//recipient admin
struct RAVRequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    int NumBags;
};

void DisplayRequest(const RAVRequestForm& form);
void DeleteRequestByUsername(const string& filename, const string& username);
void ViewRequestByUsername(const string& filename, const string& username);

struct RAPRequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    int NumBags;
};

void DisplayRequest(const RAPRequestForm& form);
void ViewRequestByUsername(const string& filename, const string& username);
bool ValidateYesNoInputStock(const string& input);
void CheckStockAvailability(const string& filename);

//*********HEALTH STATS FORM**********
struct healthStatsForm {
    int age;
    float weight, height;
    char covid19,
        tattoosAndpiercings,
        travel,
        pregnancy,
        drugs,
        medication,
        endoscopy,
        gender,
        sex,
        sickness,
        diarrhoea,
        antibiotics,
        travelOutNZ;
};

bool validateNewDonorAge(int& newDonorAge);
bool validateNewDonorWeight(float& newDonorWeight);
bool validateNewDonorHeight(float& newDonorHeight);
void getNDHealthStatus(healthStatsForm& Healthstatsform);

#endif // !FUNCTIONS_AND_DECLARATIONS_H
