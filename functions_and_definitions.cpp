#include "functions_and_declarations.h"

//booleans (to be accessed by all valdidations)
//validate date
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
    regex passwordValidation("([a-zA-Z0-9@#$%^&+=]{8,})");//8 characters minimum
    return regex_match(password, passwordValidation);
}
// to validate username
bool validateUsername(string& userN)
{
    regex userNValidation("([a-zA-Z0-9_]{4,})"); //4characters minimum
    return regex_match(userN, userNValidation);
}
//to validate NZBlood donor ID (2 letters, 6 nos.)
bool validateDonorID(string& donorID)
{
    regex donorIDValidation("^[A-Z]{2}\\d{6}$");
    return regex_match(donorID, donorIDValidation);
}

//to validate establishment name
bool validateEstName(string& establishmentName)
{
    regex estNameValidation("^[A-Za-z\\s]{1,50}$");
    
    return regex_match(establishmentName, estNameValidation);
}
//to validate contact no. (mobile & landline)
bool validateRContactNo(string& RcontactNo)
{
    std::regex nzNoValidation("\\d{4} \\d{4,7}");
    return regex_match(RcontactNo, nzNoValidation);

    regex nzLandlineValidation("^(0800|09)\\{7}$");
    return regex_match(RcontactNo, nzLandlineValidation);

    std::regex nzmobNoValidation("\\+?64[- ]?\\d{1,4}[- ]?\\d{4,10}");
    return regex_match(RcontactNo, nzmobNoValidation);
}

//donor
//new donor registration functions
void saveDonorDetails(const newDonor& donor) {
    ofstream file("donor_details.txt", ios::app);  // Open the file in append mode

    if (file.is_open()) {
        file << "\n";
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
        std::cout << "Unable to open the file.";
    }
}

void getNewDonorDetails(newDonor& Newdonor) {
    std::cout << "Create a Donor Profile Today!!!" << endl;
    cout << "------------------------------------" << endl;
    cout << "\n\n";

    cout << "Please provide an email address            : ";
    cin >> Newdonor.email;
    cout << "Create a password (min. 8 characters)      : ";
    cin >> Newdonor.password;
    cout << "Confirm Password                           : ";
    cin >> Newdonor.confirmPassword;
    cout << "First Name                                 : ";
    cin >> Newdonor.fName;
    cout << "Last Name                                  : ";
    cin >> Newdonor.lName;
    cout << "Provide a username (min. 4 characters)     : ";
    cin >> Newdonor.userName;
    cout << "Date of Birth (dd/mm/yy)                   : ";
    cin >> Newdonor.doB;
    cout << "NZ Mobile Number (starting with +64)       : ";
    cin >> Newdonor.mobileNo;

    cout <<"Donor ID (if known/Press Enter to skip)     : ";
    cin.ignore();
    string donorIDInput;
    getline(cin, donorIDInput);

    if (!donorIDInput.empty()) {
        Newdonor.donorID = donorIDInput;
        if (!validateDonorID(Newdonor.donorID)) {
            cout << "Invalid Donor ID. Please try again." << endl;
            getNewDonorDetails(Newdonor);
            return;
        }
    }

    // Validate input
    if (validateEmail(Newdonor.email) && validatePassword(Newdonor.password) &&
        Newdonor.password == Newdonor.confirmPassword &&
        validateFname(Newdonor.fName) && validateLname(Newdonor.lName) &&
        validateUsername(Newdonor.userName) && validateDate(Newdonor.doB) &&
        validateContactNo(Newdonor.mobileNo)) {
        // Save donor details to file
        saveDonorDetails(Newdonor);
    }
    else {
        cout << "\n";
        cout <<"Invalid input. Please restart. ";
        system("pause");
        system("cls");
        getNewDonorDetails(Newdonor);
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

void registerAndLogin() {
    newDonor donor;
    getNewDonorDetails(donor);
    cout << "\n";
    cout << "Registration complete, please check your inbox for a confirmation email. ";

    system("pause");
    system("CLS");
    
}

//view donor profile
void DisplayProfile(const ViewProfile& profile) {
    cout << "Username             : " << profile.userName << endl;
    cout << "Password             : " << profile.password << endl;
    cout << "Email                : " << profile.email << endl;
    cout << "First Name           : " << profile.fName << endl;
    cout << "Last Name            : " << profile.lName << endl;
    cout << "Date of Birth        : " << profile.doB << endl;
    cout << "Mobile Phone Number  : " << profile.mobileNo << endl;
    cout << "Donor ID             : " << profile.donorID << endl;
}

ViewProfile FindProfileByUsername(const string& username) {
    ifstream inputFile("donor_details.txt");
    ViewProfile profile;

    if (!inputFile) {
        cout << "Failed to open the file." << endl;
        return profile;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.find("Username: " + username) != string::npos) {
            profile.userName = line.substr(10);
            getline(inputFile, line);
            profile.password = line.substr(10);
            getline(inputFile, line);
            profile.email = line.substr(7);
            getline(inputFile, line);
            profile.fName = line.substr(12);
            getline(inputFile, line);
            profile.lName = line.substr(11);
            getline(inputFile, line);
            profile.doB = line.substr(15);
            getline(inputFile, line);
            profile.mobileNo = line.substr(21);
            getline(inputFile, line);
            profile.donorID = line.substr(10);
            break;
        }
    }

    inputFile.close();
    return profile;
}

void ViewDonorProfile() {
    std::string username;
    std::cout << "Enter username: ";
    std::cin >> username;

    system("cls");

    std::cout <<"Welcome to Donor's Profile" << "\n\n";

    ViewProfile profile = FindProfileByUsername(username);
    if (!profile.userName.empty()) {
        DisplayProfile(profile);
    }
    else {
        std::cout << "Profile not found." << std::endl;
    }
}

//**************modify donor profile*********************

void ModifyMenu() {
    cout << "Modify Donor Profile" << endl;
    cout << "1. Update Profile" << endl;
    cout << "2. Delete Profile" << endl;
    cout << "\n";
    cout << "Enter your choice     : ";
}

vector<donorProfile> LoadProfiles() {
    vector<donorProfile> profiles;
    ifstream file("donor_details.txt");
    if (file.is_open()) {
        string line;
        donorProfile profile;

        while (getline(file, line)) {
            if (line.find("Username: ") != string::npos) {
                profile.userName = line.substr(line.find("Username: ") + 10);
            }
            else if (line.find("Password: ") != string::npos) {
                profile.password = line.substr(line.find("Password: ") + 10);
            }
            else if (line.find("Email: ") != string::npos) {
                profile.email = line.substr(line.find("Email: ") + 7);
            }
            else if (line.find("First Name: ") != string::npos) {
                profile.fName = line.substr(line.find("First Name: ") + 12);
            }
            else if (line.find("Last Name: ") != string::npos) {
                profile.lName = line.substr(line.find("Last Name: ") + 11);
            }
            else if (line.find("Date of Birth: ") != string::npos) {
                profile.doB = line.substr(line.find("Date of Birth: ") + 15);
            }
            else if (line.find("Mobile Phone Number: ") != string::npos) {
                profile.mobileNo = line.substr(line.find("Mobile Phone Number: ") + 21);
            }
            else if (line.find("Donor ID: ") != string::npos) {
                profile.donorID = line.substr(line.find("Donor ID: ") + 10);
            }
            else if (line.find("") != std::string::npos) {
                profiles.push_back(profile);
            }
        }
        file.close();
    }
    return profiles;
}

void SaveProfiles(const vector<donorProfile>& profiles) {
    ofstream file("donor_details.txt");
    if (file.is_open()) {
        for (const donorProfile& profile : profiles) {
            file << "Username: " << profile.userName << endl;
            file << "Password: " << profile.password << endl;
            file << "Email: " << profile.email << endl;
            file << "First Name: " << profile.fName << endl;
            file << "Last Name: " << profile.lName << endl;
            file << "Date of Birth: " << profile.doB << endl;
            file << "Mobile Phone Number: " << profile.mobileNo << endl;
            file << "Donor ID: " << profile.donorID << endl;
            file << endl;
        }
        file.close();
    }
    else {
        cout << "Unable to open the file." << endl;
    }
}

void UpdateProfile() {
    string username;
    cout << "Enter your Username   : ";
    cin.ignore();
    getline(cin, username);

    vector<donorProfile> profiles = LoadProfiles();
    bool found = false;

    for (donorProfile& profile : profiles) {
        if (profile.userName == username) {
            found = true;

            cout << "\n\n";
            cout << "Original Profile Information " << endl;
            cout << "-----------------------------" << endl;
            cout << "Username                : " << profile.userName << endl;
            cout << "Password                : " << profile.password << endl;
            cout << "Email                   : " << profile.email << endl;
            cout << "First Name              : " << profile.fName << endl;
            cout << "Last Name               : " << profile.lName << endl;
            cout << "Date of Birth           : " << profile.doB << endl;
            cout << "Mobile Phone Number     : " << profile.mobileNo << endl;
            cout << "Donor ID                : " << profile.donorID << endl;

            string email,
                password,
                confirmPassword,
                fName,
                lName,
                userName,
                doB,
                mobileNo,
                donorID;

            cout << "\n\n";
            cout << "Update Information Form" << endl;
            cout << "-----------------------------" << endl;

            cout << "Enter *Updated* Password          : ";
            getline(cin, password);
            cout << "Enter *Updated* Email             : ";
            getline(cin, email);
            cout << "Enter *Updated* First Name        : ";
            getline(cin, fName);
            cout << "Enter *Updated* Last Name         : ";
            getline(cin, lName);
            cout << "Enter *Updated* Date of Birth     : ";
            getline(cin, doB);
            cout << "Enter *Updated* Mobile No         : ";
            getline(cin, mobileNo);
            cout << "Enter *Updated* Donor ID          : ";
            getline(cin, donorID);

            if (!password.empty()) {
                profile.password = password;
            }
            if (!email.empty()) {
                profile.email = email;
            }
            if (!fName.empty()) {
                profile.fName = fName;
            }
            if (!lName.empty()) {
                profile.lName = lName;
            }
            if (!doB.empty()) {
                profile.doB = doB;
            }
            if (!mobileNo.empty()) {
                profile.mobileNo = mobileNo;
            }
            if (!donorID.empty()) {
                profile.donorID = donorID;
            }

            cout << "\n";
            cout << "Profile updated successfully." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Profile not found." << endl;
    }
    else {
        SaveProfiles(profiles);
    }
}

void DeleteProfile() {
    string username;
    cout << "Enter your Username   : ";
    cin.ignore();
    getline(cin, username);

    vector<donorProfile> profiles = LoadProfiles();
    bool found = false;

    for (size_t i = 0; i < profiles.size(); i++) {
        if (profiles[i].userName == username) {
            found = true;

            cout << "\n";
            cout << "Donor Profile" << "\n\n";
            cout << "Username                : " << profiles[i].userName << endl;
            cout << "Password                : " << profiles[i].password << endl;
            cout << "Email                   : " << profiles[i].email << endl;
            cout << "First Name              : " << profiles[i].fName << endl;
            cout << "Last Name               : " << profiles[i].lName << endl;
            cout << "Date of Birth           : " << profiles[i].doB << endl;
            cout << "Mobile Phone Number     : " << profiles[i].mobileNo << endl;
            cout << "Donor ID                : " << profiles[i].donorID << endl;
            cout << "\n\n";

            char confirm;
            cout << "Do you wish to delete this donor's profile? (Y/N): ";
            cin >> confirm;

            if (confirm == 'Y' || confirm == 'y') {
                profiles.erase(profiles.begin() + i);
                cout << "Profile deleted successfully." << endl;
                break;
            }
            else {
                cout << "Profile not deleted." << endl;
                break;
            }
        }
    }

    if (!found) {
        cout << "Profile not found." << endl;
    }
    else {
        SaveProfiles(profiles);
    }
}

void modifyDonorProfile() {
    int choice;

    do {
        ModifyMenu();
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
            UpdateProfile();
            break;
        case 2:
            DeleteProfile();
            break;
        default:
            cout << "Incorrect choice." << endl;
            break;
        }

        cout << endl;
    } while (choice != 1 && choice != 2);
}

//********book a donation appointment*******************
bool isAppointmentAvailable(const std::vector<Appointment>& BAappointments, const std::string& date, const std::string& time) {
    for (const auto& appointment : BAappointments) {
        if (appointment.BAdate == date && appointment.BAdate == time) {
            return false; // Appointment already booked
        }
    }

    std::ifstream file("pending_appointments.txt");
    std::string line;
    while (std::getline(file, line)) {
        if (line.find("Date: " + date) != std::string::npos) {
            std::getline(file, line); // Read the corresponding time line
            if (line.find("Time: " + time) != std::string::npos) {
                file.close();
                return false; // Appointment already exists in the file
            }
        }
    }

    file.close();
    return true; // Appointment available
}

void addAppointment(std::vector<Appointment>& BAappointments, const Appointment& appointment) {
    BAappointments.push_back(appointment);
}

void saveAppointmentsToFile(const std::string& filename, const std::vector<Appointment>& BAappointments) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    for (const auto& appointment : BAappointments) {
        file << "Username: " << appointment.BAusername << "\n";
        file << "Eligibility Form: " << appointment.BAeligibilityForm << "\n";
        file << "Date: " << appointment.BAdate << "\n";
        file << "Time: " << appointment.BAtime << "\n";
        file << "Donation Type: " << appointment.BAdonationType << "\n";
        if (appointment.BAdonationType == "blood") {
            file << "Blood Type: " << appointment.BAbloodType << "\n";
        }
        file << "Status: " << appointment.BAstatus << "\n";
        file << "\n";
    }

    file.close();
}

void displayConfirmationMessage() {
    cout << "\n";
    cout << "Appointment booked successfully!";
    cout << "\n";
}

void displayError(const std::string& message) {
    cout << "Sorry, " << message << "\n";
}

void bookAppointment() {
    std::vector<Appointment> BAappointments;

    std::string BAusername;
    std::string BAeligibilityForm;
    std::string BAdate;
    std::string BAtime;
    std::string BAdonationType;
    std::string BAbloodType;
    std::string BAstatus = "Pending";

    cout << "Appointment Booking Form";
    cout << "\n\n";

    cout << "Enter username                       : "; cin >> BAusername;
    cout << "Submitted eligibility form (yes/no)  : "; cin >> BAeligibilityForm;

    if (BAeligibilityForm != "yes") {
        displayError("you are not eligible to donate.");
        return;
    }
    cout << "Preferred date (dd/mm/yy)            : "; cin >> BAdate;
    cout << "Preferred time (between 10am to 6pm) : "; cin >> BAtime;

    while (!isAppointmentAvailable(BAappointments, BAdate, BAtime)) {
        cout << "\n";
        cout << "\t\t\t\t------------------------------------------------------------------------------";
        cout << "\n";
        displayError("an appointment has already been booked for your preferred date and time.");
        cout << "\t\t\t\t------------------------------------------------------------------------------";
        cout << "\n\n";
    cout << "Choose another date (dd/mm/yy)            : ";
        cin >> BAdate;
    cout << "Choose another time (between 10am to 6pm) : ";
        cin >> BAtime;
    }

    cout << "Will you donate blood or plasma?     : "; cin >> BAdonationType;
    if (BAdonationType == "blood") {
    cout << "Please enter blood type              : ";
        cin >> BAbloodType;
    }

    system("cls");

    // Displaying user's answers
    cout << "\n";
    cout << "Appointment Details";
    cout <<"---------------------" << "\n\n";
    cout << "Username         : " << BAusername << "\n";
    cout << "Eligible?        : " << BAeligibilityForm << "\n";
    cout << "Date             : " << BAdate << "\n";
    cout << "Time             : " << BAtime << "\n";
    cout << "Donation Type    : " << BAdonationType << "\n";
    cout << "Status           : " << BAstatus << "\n";

    // Saving appointment details to a text file
    Appointment appointment{ BAusername, BAeligibilityForm, BAdate, BAtime, BAdonationType, BAbloodType,BAstatus };
    addAppointment(BAappointments, appointment);
    saveAppointmentsToFile("pending_appointments.txt", BAappointments);

    displayConfirmationMessage();
}

//**************************

//donor admin
void loadAppointmentsFromFile(const string& filename, vector<DAviewAppointment>& appointments) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << "\n";
        return;
    }

    appointments.clear();
    string line;
    DAviewAppointment appointment;
    while (getline(file, line)) {
        if (line.find("Username: ") != string::npos) {
            appointment.username = line.substr(line.find("Username: ") + 10);
        }
        else if (line.find("Eligibility Form: ") != string::npos) {
            appointment.eligibilityForm = line.substr(line.find("Eligibility Form: ") + 18);
        }
        else if (line.find("Date: ") != string::npos) {
            appointment.date = line.substr(line.find("Date: ") + 6);
        }
        else if (line.find("Time: ") != string::npos) {
            appointment.time = line.substr(line.find("Time: ") + 6);
        }
        else if (line.find("Donation Type: ") != string::npos) {
            appointment.donationType = line.substr(line.find("Donation Type: ") + 15);
        }
        else if (line.find("Blood Type: ") != string::npos) {
            appointment.bloodType = line.substr(line.find("Blood Type: ") + 12);
        }
        else if (line.find("Status: ") != string::npos) {
            appointment.apptStatus = line.substr(line.find("Status: ") + 8);
            appointments.push_back(appointment);
        }
    }

    file.close();
}

void displayAppointments(const vector<DAviewAppointment>& appointments) {
    cout << setw(87) << right << "Pending Appointments\n\n";
    cout << "\t\t\t\t" << setw(15) << left << "Username"
        << setw(18) << left << "Eligibility Form"
        << setw(10) << left << "Date"
        << setw(8) << left << "Time"
        << setw(15) << left << "Donation Type"
        << setw(15) << left << "Blood Type"
        << setw(10) << left << "Status" << "\n";

    cout << "\t\t\t\t" << "-----------------------------------------------------------------------------------------\n";
    for (const auto& appointment : appointments) {
        cout << "\t\t\t\t" << setw(15) << left << appointment.username
            << setw(18) << left << appointment.eligibilityForm
            << setw(10) << left << appointment.date
            << setw(8) << left << appointment.time
            << setw(15) << left << appointment.donationType
            << setw(15) << left << appointment.bloodType
            << setw(10) << left << appointment.apptStatus << "\n";
    }
}

void displayCompletedAppointments(const vector<DAviewAppointment>& appointments) {
    cout << setw(87) << right << "Completed Appointments\n\n";
    cout << "\t\t\t\t" << setw(15) << left << "Username"
        << setw(18) << left << "Eligibility Form"
        << setw(10) << left << "Date"
        << setw(8) << left << "Time"
        << setw(15) << left << "Donation Type"
        << setw(15) << left << "Blood Type"
        << setw(10) << left << "Status" << "\n";

    cout << "\t\t\t\t" << "-----------------------------------------------------------------------------------------\n";
    for (const auto& appointment : appointments) {
        cout << "\t\t\t\t" << setw(15) << left << appointment.username
            << setw(18) << left << appointment.eligibilityForm
            << setw(10) << left << appointment.date
            << setw(8) << left << appointment.time
            << setw(15) << left << appointment.donationType
            << setw(15) << left << appointment.bloodType
            << setw(10) << left << appointment.apptStatus << "\n";
    }
}

void deleteAppointment(int index, vector<DAviewAppointment>& appointments, const string& pendingFilename, const string& completedFilename) {
    if (index >= 0 && index < appointments.size()) {
        DAviewAppointment deletedAppointment = appointments[index];
        appointments.erase(appointments.begin() + index);
        cout << "Appointment deleted successfully!\n";

        ofstream completedFile(completedFilename, ios::app);
        if (!completedFile) {
            cerr << "Error opening file: " << completedFilename << "\n";
            return;
        }

        completedFile << "Username: " << deletedAppointment.username << "\n";
        completedFile << "Eligibility Form: " << deletedAppointment.eligibilityForm << "\n";
        completedFile << "Date: " << deletedAppointment.date << "\n";
        completedFile << "Time: " << deletedAppointment.time << "\n";
        completedFile << "Donation Type: " << deletedAppointment.donationType << "\n";
        completedFile << "Blood Type: " << deletedAppointment.bloodType << "\n";
        completedFile << "Status: " << "Completed" << "\n\n";

        completedFile.close();

        ofstream pendingFile(pendingFilename);
        if (!pendingFile) {
            cerr << "Error opening file: " << pendingFilename << "\n";
            return;
        }

        for (const auto& appointment : appointments) {
            pendingFile << "Username: " << appointment.username << "\n";
            pendingFile << "Eligibility Form: " << appointment.eligibilityForm << "\n";
            pendingFile << "Date: " << appointment.date << "\n";
            pendingFile << "Time: " << appointment.time << "\n";
            pendingFile << "Donation Type: " << appointment.donationType << "\n";
            pendingFile << "Blood Type: " << appointment.bloodType << "\n";
            pendingFile << "Status: " << appointment.apptStatus << "\n\n";
        }

        pendingFile.close();
    }
    else {
        cout << "Invalid appointment index.\n";
    }
}

map<string, int> countDonationTypes(const vector<DAviewAppointment>& appointments) {
    map<string, int> countMap;
    for (const auto& appointment : appointments) {
        if (appointment.donationType == "blood") {
            countMap[appointment.bloodType]++;
        }
        else if (appointment.donationType == "plasma") {
            countMap["Plasma"]++;
        }
    }
    return countMap;
}

void recordDonationInventory(const vector<DAviewAppointment>& appointments, const string& filename) {
    map<string, int> inventory = countDonationTypes(appointments);

    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << "\n";
        return;
    }

    file << "Donation Inventory\n";
    file << "-----------------------\n";
    for (const auto& item : inventory) {
        file << setw(15) << left << item.first
            << setw(10) << left << item.second << " bags\n";
    }

    file.close();
}

void displayDonationTypeInventory(const vector<DAviewAppointment>& appointments) {
    map<string, int> inventory = countDonationTypes(appointments);

    cout << setw(85) << right << "Donation Inventory\n";
    cout << setw(88) << right << "-------------------------\n";
    for (const auto& item : inventory) {
        cout << setw(68) << right << item.first
            << setw(12) << right << item.second << " bags\n";
    }
}



//recipient
//registration
void saveRecipientDetails(const newRecipient& recipient) {
    ofstream file("recipient_details.txt", ios::app);  // Open the file in append mode

    if (file.is_open()) {
        file << "Username: " << recipient.userName << endl;
        file << "Password: " << recipient.password << endl;
        file << "Email: " << recipient.email << endl;
        file << "Establishment Name: " << recipient.establishmentName << endl;
        file << "Phone: " << recipient.RcontactNo << endl;
        file << "NZ Address: " << recipient.address << endl;
        file << " " << endl;

        file.close();
    }
    else {
        cout << "Unable to open the file.";
    }
}

void getNewRecipientDetails(newRecipient& Newrecipient) {

    cout << "Create a Recipient Profile Today!!!" << endl;
    cout << "------------------------------------" << "\n\n";

    cout << "Please provide an email address        : ";
    cin >> Newrecipient.email;
    cout << "Create a password (min. 8 characters)  : ";
    cin >> Newrecipient.password;
    cout << "Confirm Password                       : ";
    cin >> Newrecipient.confirmPassword;
    cout << "Estblishment Name (eg. Auckland Hospital)                    : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, Newrecipient.establishmentName);
    cout << "Provide a username (min. 4 characters)                       : ";
    cin >> Newrecipient.userName;
    cout << "NZ Phone/Landline Number  (eg. 0800 1234)                    : ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, Newrecipient.RcontactNo);
    cout << "New Zealand Address (eg. 00 Street Name Suburb, City 0000)   : ";
    cin >> Newrecipient.address;

    // Validate input

    if (validateEmail(Newrecipient.email) && validatePassword(Newrecipient.password) && Newrecipient.password == Newrecipient.confirmPassword &&
        validateEstName(Newrecipient.establishmentName) && validateUsername(Newrecipient.userName) &&
        validateRContactNo(Newrecipient.RcontactNo)) {

        // Save donor details to file
        saveRecipientDetails(Newrecipient);

    }
    else {

        cout << "\n";

        cout << "Invalid input. Please restart. ";
        system("pause");
        system("cls");
        getNewRecipientDetails(Newrecipient);
    }
}

bool Rlogin(const string& username, const string& password) {
    ifstream file("recipient_details.txt");

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

void recipientRegistrationAndLogin() {
    newRecipient recipient;

    // Register a new recipient
    getNewRecipientDetails(recipient);

    cout << "\n";
    cout << "Registration complete, please check your inbox for a confirmation email. ";

    // Clear the screen
    system("pause");
    system("CLS");
}

//*******VIEW RECIPIENT PROFILE************
void removeSpaces(string& str) {
    size_t start = str.find_first_not_of(' ');
    if (start != string::npos) {
        str = str.substr(start);
    }

    size_t end = str.find_last_not_of(' ');
    if (end != string::npos) {
        str = str.substr(0, end + 1);
    }
}

void displayProfile(const string& username, const vector<Profile>& profiles) {
    bool profileFound = false;

    for (const auto& profile : profiles) {
        if (profile.Username == username) {
            cout << " " << endl;
            cout << "Recipient Profile" << endl;
            cout << "_________________" << endl;
            cout << "Username            : " << profile.Username << endl;
            cout << "Password            : " << profile.Password << endl;
            cout << "Email               : " << profile.Email << endl;
            cout << "Establishment Name  : " << profile.EstablishmentName << endl;
            cout << "Phone               : " << profile.Phone << endl;
            cout << "NZ Address          : " << profile.Address << endl;

            profileFound = true;
            break;
        }
    }

    if (!profileFound) {
        cout << "Profile not found." << endl;
    }
}

void viewRecipientProfile() {

    string fileName = "recipient_details.txt";
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Failed to open the profile file." << endl;
        return;
    }

    vector<Profile> profiles;
    Profile profile;

    string line;
    while (getline(inputFile, line)) {
        if (line.find("Username:") != string::npos) {
            profile.Username = line.substr(line.find(":") + 1);
            removeSpaces(profile.Username);
        }
        else if (line.find("Password:") != string::npos) {
            profile.Password = line.substr(line.find(":") + 1);
            removeSpaces(profile.Password);
        }
        else if (line.find("Email:") != string::npos) {
            profile.Email = line.substr(line.find(":") + 1);
            removeSpaces(profile.Email);
        }
        else if (line.find("Establishment Name:") != string::npos) {
            profile.EstablishmentName = line.substr(line.find(":") + 1);
            removeSpaces(profile.EstablishmentName);
        }
        else if (line.find("Phone:") != string::npos) {
            profile.Phone = line.substr(line.find(":") + 1);
            removeSpaces(profile.Phone);
        }
        else if (line.find("NZ Address:") != string::npos) {
            profile.Address = line.substr(line.find(":") + 1);
            removeSpaces(profile.Address);
            profiles.push_back(profile);
            profile = Profile();
        }
    }

    inputFile.close();

    string username;
    cout << "View Recipient Profile" << endl;
    cout << " " << endl;
    cout << "Enter Username: ";
    cin >> username;

    displayProfile(username, profiles);
}


//*********MODIFY RECIPIENT PROFILE*****

void displayProfile(const string& MRusername, const vector<MRProfile>& MRprofiles) {
    bool profileFound = false;

    for (const auto& profile : MRprofiles) {
        if (profile.MRUsername == MRusername) {
            cout << " " << endl;
            cout << "Recipient Profile" << endl;
            cout << "_________________" << endl;
            cout << "Username            : " << profile.MRUsername << endl;
            cout << "Password            : " << profile.MRPassword << endl;
            cout << "Email               : " << profile.MREmail << endl;
            cout << "Establishment Name  : " << profile.MREstablishmentName << endl;
            cout << "Phone               : " << profile.MRPhone << endl;
            cout << "NZ Address          : " << profile.MRAddress << endl;

            profileFound = true;
            break;
        }
    }

    if (!profileFound) {
        cout << "Profile not found." << endl;
    }
}

void updateProfile(const string& MRusername, vector<MRProfile>& MRprofiles) {
    for (auto& profile : MRprofiles) {
        if (profile.MRUsername == MRusername) {
            cout << " " << endl;
            cout << "Update Profile" << endl;
            cout << "No white spaces, use dash (-) to separate text (eg. 0800-9233, My-Name)" << endl;
            cout << "______________" << endl;

            string MRnewPassword, MRnewEmail, MRnewEstablishmentName, MRnewPhone, MRnewAddress;

            // Password
            cout << "Enter new password: ";
            cin >> MRnewPassword;
            removeSpaces(MRnewPassword);
            while (MRnewPassword.empty()) {
                cout << "Field empty. Please enter a new password: ";
                cin >> MRnewPassword;
                removeSpaces(MRnewPassword);
            }
            profile.MRPassword = MRnewPassword;

            // Email
            cout << "Enter new email: ";
            cin >> MRnewEmail;
            removeSpaces(MRnewEmail);
            while (MRnewEmail.empty()) {
                cout << "Field empty. Please enter a new email: ";
                cin >> MRnewEmail;
                removeSpaces(MRnewEmail);
            }
            profile.MREmail = MRnewEmail;

            // Establishment Name
            cout << "Enter new establishment name (no space): ";
            cin >> MRnewEstablishmentName;
            removeSpaces(MRnewEstablishmentName);
            while (MRnewEstablishmentName.empty()) {
                cout << "Field empty. Please enter a new establishment name: ";
                cin >> MRnewEstablishmentName;
                removeSpaces(MRnewEstablishmentName);
            }
            profile.MREstablishmentName = MRnewEstablishmentName;

            // Phone Number
            cout << "Enter new phone number: ";
            cin >> MRnewPhone;
            removeSpaces(MRnewPhone);
            while (MRnewPhone.empty()) {
                cout << "Field empty. Please enter a new phone number: ";
                cin >> MRnewPhone;
                removeSpaces(MRnewPhone);
            }
            profile.MRPhone = MRnewPhone;

            // NZ Address
            cout << "Enter new NZ address: ";
            cin >> MRnewAddress;
            removeSpaces(MRnewAddress);
            while (MRnewAddress.empty()) {
                cout << "Field empty. Please enter a new NZ address: ";
                cin >> MRnewAddress;
                removeSpaces(MRnewAddress);
            }
            profile.MRAddress = MRnewAddress;


            return;
        }
    }

    cout << "Profile not found." << endl;
}

void deleteProfile(const string& username, vector<MRProfile>& profiles) {
    for (auto it = profiles.begin(); it != profiles.end(); ++it) {
        if (it->MRUsername == username) {
            cout << "Are you sure you want to delete your profile? (Y/N): ";
            string confirm;
            cin >> confirm;

            if (confirm == "Y" || confirm == "y") {
                profiles.erase(it);
                cout << "Profile deleted successfully." << endl;
            }
            else {
                cout << "Profile deletion canceled." << endl;
            }

            return;
        }
    }

    cout << "Profile not found." << endl;
}

void modifyRecipientProfile() {
  

    string fileName = "recipient_details.txt";
    ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        cout << "Failed to open the profile file." << endl;
        return;
    }

    vector<MRProfile> profiles;
    MRProfile profile;

    string line;
    while (getline(inputFile, line)) {
        if (line.find("Username:") != string::npos) {
            profile.MRUsername = line.substr(line.find(":") + 1);
            removeSpaces(profile.MRUsername);
        }
        else if (line.find("Password:") != string::npos) {
            profile.MRPassword = line.substr(line.find(":") + 1);
            removeSpaces(profile.MRPassword);
        }
        else if (line.find("Email:") != string::npos) {
            profile.MREmail = line.substr(line.find(":") + 1);
            removeSpaces(profile.MREmail);
        }
        else if (line.find("Establishment Name:") != string::npos) {
            profile.MREstablishmentName = line.substr(line.find(":") + 1);
            removeSpaces(profile.MREstablishmentName);
        }
        else if (line.find("Phone:") != string::npos) {
            profile.MRPhone = line.substr(line.find(":") + 1);
            removeSpaces(profile.MRPhone);
        }
        else if (line.find("NZ Address:") != string::npos) {
            profile.MRAddress = line.substr(line.find(":") + 1);
            removeSpaces(profile.MRAddress);
            profiles.push_back(profile);
            profile = MRProfile();
        }
    }

    inputFile.close();

    string username;
    cout << "View Recipient Profile" << endl;
    cout << " " << endl;
    cout << "Enter Username: ";
    cin >> username;

    displayProfile(username, profiles);

    cout << endl;
    cout << "Modify Profile Menu" << endl;
    cout << "1. Update Profile" << endl;
    cout << "2. Delete Profile" << endl;

    int choice;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
        system("cls");
        displayProfile(username, profiles);
        updateProfile(username, profiles);
        cout << "Profile updated successfully." << endl;
        break;
    case 2:
        system("cls");
        displayProfile(username, profiles);
        deleteProfile(username, profiles);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    ofstream outputFile(fileName);
    if (!outputFile.is_open()) {
        cout << "Failed to open the profile file for writing." << endl;
        return;
    }

    for (const auto& profile : profiles) {
        outputFile << "Username: " << profile.MRUsername << endl;
        outputFile << "Password: " << profile.MRPassword << endl;
        outputFile << "Email: " << profile.MREmail << endl;
        outputFile << "Establishment Name: " << profile.MREstablishmentName << endl;
        outputFile << "Phone: " << profile.MRPhone << endl;
        outputFile << "NZ Address: " << profile.MRAddress << endl;
        outputFile << endl;
    }

    outputFile.close();
}

//*****REQUEST FORM****
void SubmitReqForm(const RequestForm& form) {
    ofstream file("Requests.txt", ios::app);
    if (file.is_open()) {
        file << "***Request from Recipient***" << endl;
        file << "Username: " << form.Username << endl;
        file << "Establishment Name: " << form.EstablishmentName << endl;
        file << "Date Required: " << form.DateRequired << endl;
        file << "What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: " << form.BloodType << endl;
        file << "Number of Bags required (1 bag = 470ml per bag): " << form.NumBags << endl;
        file << "------------------------------------------" << endl;
        file.close();

        //if (validateRequestDate(form.DateRequired) && validateBloodType(form.BloodType)) {}

    }
    else {
        cout << "                                                              Unable to open the file. Form submission failed." << endl;
    }
}

void requestBloodRecipientForm() {
    RequestForm form;

    cout << "                                                                      Blood/Plasma Recipient Request Form" << endl;
    cout << "                                                                      ___________________________________" << endl;

    cout << "                                                                   Username: ";
    cin >> form.Username;
    cin.ignore();

    cout << "                                                                   Establishment Name: ";
    cin >> form.EstablishmentName;
    cin.ignore();

    cout << "                                                                   Date Required (dd/mm/yy): ";
    cin >> form.DateRequired;
    cin.ignore();

    cout << "                                                                   What Blood Type do you require - Eg. A+, O+, B+ or Plasma? ";
    cin >> form.BloodType;
    cin.ignore();

    cout << "                                                                   Number of Bags required (1 bag = 470ml per bag): ";
    cin >> form.NumBags;
    cin.ignore();

    system("CLS");

    cout << "\n";
    cout << "                                                                   Thank you. Your request has been submitted" << endl;
    SubmitReqForm(form);
}

//******VIEW REQUEST******
void DisplayRequest(const viewRRequestForm& form) {
    cout << "***Request from Recipient***" << endl;
    cout << "Username: " << form.Username << endl;
    cout << "Establishment Name: " << form.EstablishmentName << endl;
    cout << "Date Required: " << form.DateRequired << endl;
    cout << "What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: " << form.BloodType << endl;
    cout << "Number of Bags (1 bag = 470ml per bag): " << form.NumBags << endl;
    cout << "------------------------------------------" << endl;
}

void ViewRequestByUsername(const string& filename, const string& username) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the request file." << endl;
        return;
    }

    string line;
    viewRRequestForm vRRequest;
    bool foundRequest = false;
    bool inRequestBlock = false;

    while (getline(file, line)) {
        if (line == "------------------------------------------") {
            if (inRequestBlock) {
                inRequestBlock = false;
                if (vRRequest.Username == username) {
                    DisplayRequest(vRRequest);
                    foundRequest = true;
                }
                vRRequest = viewRRequestForm();
            }
        }
        else {
            inRequestBlock = true;
            if (line.find("Username: ") != string::npos) {
                vRRequest.Username = line.substr(line.find(": ") + 2);
            }
            else if (line.find("Establishment Name: ") != string::npos) {
                vRRequest.EstablishmentName = line.substr(line.find(": ") + 2);
            }
            else if (line.find("Date Required: ") != string::npos) {
                vRRequest.DateRequired = line.substr(line.find(": ") + 2);
            }
            else if (line.find("What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: ") != string::npos) {
                vRRequest.BloodType = line.substr(line.find(": ") + 2);
            }
            else if (line.find("Number of Bags required (1 bag = 470ml per bag): ") != string::npos) {
                vRRequest.NumBags = stoi(line.substr(line.find(": ") + 2));
            }
        }
    }

    file.close();

    if (!foundRequest) {
        cout << "No requests found for the given username." << endl;
    }
}

void viewRRequests() {

    string username;
    cout << "View Your Request" << endl;
    cout << "\n\n";

    cout << "Enter your username: ";
    cin >> username;
    cin.ignore();

    ViewRequestByUsername("Requests.txt", username);
}

//recipient admin
//****VIEW AND DELETE SPECIFIC REQUEST***
void DisplayRequest(const RAVRequestForm& form) {
    cout << "***Request from Recipient***" << endl;
    cout << "Username: " << form.Username << endl;
    cout << "Establishment Name: " << form.EstablishmentName << endl;
    cout << "Date Required: " << form.DateRequired << endl;
    cout << "What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: " << form.BloodType << endl;
    cout << "Number of Bags required (1 bag = 470ml per bag): " << form.NumBags << " bag(s)" << endl;
    cout << "------------------------------------------" << endl;
}

void DeleteRequestByUsername(const string& filename, const string& username) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the request file." << endl;
        return;
    }

    ofstream temp("temp.txt");
    if (!temp.is_open()) {
        cout << "Failed to create a temporary file." << endl;
        return;
    }

    string line;
    RAVRequestForm request;
    bool foundRequest = false;
    bool inRequestBlock = false;

    while (getline(file, line)) {
        if (line == "------------------------------------------") {
            if (inRequestBlock) {
                inRequestBlock = false;
                if (request.Username == username) {
                    foundRequest = true;
                    continue;
                }
                temp << "***Request from Recipient***" << endl;
                temp << "Username: " << request.Username << endl;
                temp << "Establishment Name: " << request.EstablishmentName << endl;
                temp << "Date Required: " << request.DateRequired << endl;
                temp << "What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: " << request.BloodType << endl;
                temp << "Number of Bags required (1 bag = 470ml per bag): " << request.NumBags << endl;
                temp << "------------------------------------------" << endl;
                request = RAVRequestForm();
            }
        }
        else {
            inRequestBlock = true;
            if (line.find("Username: ") != string::npos) {
                request.Username = line.substr(line.find(": ") + 2);
            }
            else if (line.find("Establishment Name: ") != string::npos) {
                request.EstablishmentName = line.substr(line.find(": ") + 2);
            }
            else if (line.find("Date Required: ") != string::npos) {
                request.DateRequired = line.substr(line.find(": ") + 2);
            }
            else if (line.find("What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: ") != string::npos) {
                request.BloodType = line.substr(line.find(": ") + 2);
            }
            else if (line.find("Number of Bags required (1 bag = 470ml per bag): ") != string::npos) {
                request.NumBags = stoi(line.substr(line.find(": ") + 2));
            }
        }
    }

    file.close();
    temp.close();

    if (!foundRequest) {
        cout << "No requests found for the given username." << endl;
        remove("temp.txt");
        return;
    }

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Request successfully deleted." << endl;
}

//*****PROCESS REQUEST*****
bool ValidateYesNoInputStock(const string& input) {
    return (input == "Yes" || input == "yes" || input == "No" || input == "no");
}

void DisplayRequest(const RAPRequestForm& form) {
    cout << "***Request from Recipient***" << std::endl;
    cout << "Username: " << form.Username << endl;
    cout << "Establishment Name: " << form.EstablishmentName << endl;
    cout << "Date Required: " << form.DateRequired << endl;
    cout << "What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: " << form.BloodType << endl;
    cout << "Number of Bags (1 bag = 470ml per bag): " << form.NumBags << endl;
    cout << "------------------------------------------" << endl;
}

void CheckStockAvailability(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open the inventory file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();

    string answer;
    bool validInput = false;
    while (!validInput) {
        cout << "Check for stock availability." << endl;
        cout << "Is stock available? (Yes/No): ";
        getline(cin, answer);
        cout << "\n\n";
        validInput = ValidateYesNoInputStock(answer);
        if (!validInput) {
            cout << "Invalid input. Please enter either 'Yes' or 'No'." << endl;
        }
    }
    cout << "\n\n";
    if (answer == "Yes" || answer == "yes") {
        cout << "Quantity is Available. Recipients Order Confirmed. Administrator to dispatch and update inventory manually." << endl;
    }
    else {
        cout << "Request denied due to stock unavailability. Please inform Recipient." << endl;
    }
}

//*********HEALTH STATS FORM*******
bool validateNewDonorAge(int& newDonorAge) {
    return (newDonorAge >= 16 && newDonorAge <= 71);
}

bool validateNewDonorWeight(float& newDonorWeight) {
    return (newDonorWeight > 50);
}

bool validateNewDonorHeight(float& newDonorHeight) {
    return (newDonorHeight >= 150);
}

void getNDHealthStatus(healthStatsForm& Healthstatsform) {
    bool eligible = true;

    cout << "Health Status Form (for new donors only)" << endl;
    cout << "\n\n";

    cout << "How old are you?: ";
    cin >> Healthstatsform.age;
    if (!validateNewDonorAge(Healthstatsform.age)) {
        eligible = false;
    }

    cout << "Weight in kilograms (kgs): ";
    cin >> Healthstatsform.weight;
    if (!validateNewDonorWeight(Healthstatsform.weight)) {
        eligible = false;
    }

    cout << "Height in centimeters (cm): ";
    cin >> Healthstatsform.height;
    if (!validateNewDonorHeight(Healthstatsform.height)) {
        eligible = false;
    }

    cout << "Gender (M/F): ";
    cin >> Healthstatsform.gender;

    if (Healthstatsform.gender == 'M' || Healthstatsform.gender == 'm') {

        cout << "\n\n" << "Travel Eligibility Information";
        cout << "\n\n";
        cout << "You must not have lived in the United Kingdom, France or the Republic of Ireland between 1980 and 1996 for a cumulative 6 months or more." << endl;
        cout << "\n";
        cout << "Do you meet the criteria above? (Y/N) : ";
        cin >> Healthstatsform.travel;
        if (Healthstatsform.travel == 'N' || Healthstatsform.travel == 'n') {
            eligible = false;
        }

        cout << "Have you ever injected drugs not prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.drugs;
        if (Healthstatsform.drugs == 'N' || Healthstatsform.drugs == 'n') {
            eligible = true;
        }

        cout << "\n\n" << "Pregnancy Eligibility Information";
        cout << "\n\n";
        cout << "Following pregnancy, you will not be eligible to donate blood or plasma for as many months as your pregnancy was long. In most cases, this is 9 months." << endl;
        cout << "\n";
        cout << "Have you been pregnant or given birth in the last 9 months? (Y/N) : ";
        cin >> Healthstatsform.pregnancy;
        if (Healthstatsform.pregnancy == 'N' || Healthstatsform.pregnancy == 'n') {
            eligible = true;
        }

        cout << "Have you taken iron medication prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.medication;
        if (Healthstatsform.medication == 'N' || Healthstatsform.medication == 'n') {
            eligible = true;
        }

        cout << "Have you had an endoscopy in the last 4 months? (Y/N) : ";
        cin >> Healthstatsform.endoscopy;
        if (Healthstatsform.endoscopy == 'N' || Healthstatsform.endoscopy == 'n') {
            eligible = true;
        }

        cout << "Have you had a tattoo or piercing in the last 3 months? (Y/N) : ";
        cin >> Healthstatsform.tattoosAndpiercings;
        if (Healthstatsform.tattoosAndpiercings == 'N' || Healthstatsform.tattoosAndpiercings == 'n') {
            eligible = true;
        }

        cout << "MALES: Have you had anal or oral sex with another man, or have you used PEP/PrEP in the last 3 months? (Y/N) : ";
        cin >> Healthstatsform.sex;
        if (Healthstatsform.sex == 'N' || Healthstatsform.sex == 'n') {
            eligible = true;
        }

        cout<< "Have you had a cough, cold, sore throat, or influenza in the last 28 days? (Y/N) : ";
        cin >> Healthstatsform.sickness;
        if (Healthstatsform.sickness == 'N' || Healthstatsform.sickness == 'n') {
            eligible = true;
        }

        cout << "Have you or anyone in your household had diarrhea or vomiting symptoms in the last 28 days? (Y/N) : ";
        cin >> Healthstatsform.diarrhoea;
        if (Healthstatsform.diarrhoea == 'N' || Healthstatsform.diarrhoea == 'n') {
            eligible = true;
        }

        cout << "Have you taken antibiotics in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.antibiotics;
        if (Healthstatsform.antibiotics == 'N' || Healthstatsform.antibiotics == 'n') {
            eligible = true;
        }

        cout << "Have you traveled outside of New Zealand in the last 12 months? (Y/N) : ";
        cin >> Healthstatsform.travelOutNZ;
        if (Healthstatsform.travelOutNZ == 'N' || Healthstatsform.travelOutNZ == 'n') {
            eligible = true;
        }

        cout << "Have you tested positive for COVID-19 in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.covid19;
        if (Healthstatsform.covid19 == 'N' || Healthstatsform.covid19 == 'n') {
            eligible = true;
        }
    }
    else {

        cout << "\n\n" << setw(70) << right << "Travel Eligibility Information";
        cout << "\n\n";
        cout << "You must not have lived in the United Kingdom, France, or the Republic of Ireland between 1980 and 1996 for a cumulative 6 months or more." << endl;
        cout << "\n";
        cout  << "Do you meet the criteria above? (Y/N) : ";
        cin >> Healthstatsform.travel;
        if (Healthstatsform.travel == 'N' || Healthstatsform.travel == 'n') {
            eligible = false;
        }

        cout<< "Have you ever injected drugs not prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.drugs;
        if (Healthstatsform.drugs == 'N' || Healthstatsform.drugs == 'n') {
            eligible = true;
        }

        cout << "\n\n" << "Pregnancy Eligibility Information";
        cout << "\n\n";
        cout << "Following pregnancy, you will not be eligible to donate blood or plasma for as many months as your pregnancy was long. In most cases, this is 9 months." << endl;
        cout << "\n";
        cout << "Have you been pregnant or given birth in the last 9 months? (Y/N) : ";
        cin >> Healthstatsform.pregnancy;
        if (Healthstatsform.pregnancy == 'N' || Healthstatsform.pregnancy == 'n') {
            eligible = true;
        }

        cout << "Have you taken iron medication prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.medication;
        if (Healthstatsform.medication == 'N' || Healthstatsform.medication == 'n') {
            eligible = true;
        }

        cout << "Have you had an endoscopy in the last 4 months? (Y/N) : ";
        cin >> Healthstatsform.endoscopy;
        if (Healthstatsform.endoscopy == 'N' || Healthstatsform.endoscopy == 'n') {
            eligible = true;
        }

        cout << "Have you had a tattoo or piercing in the last 3 months? (Y/N) : ";
        cin >> Healthstatsform.tattoosAndpiercings;
        if (Healthstatsform.tattoosAndpiercings == 'N' || Healthstatsform.tattoosAndpiercings == 'n') {
            eligible = true;
        }

        cout << "Have you had a cough, cold, sore throat, or influenza in the last 28 days? (Y/N) : ";
        cin >> Healthstatsform.sickness;
        if (Healthstatsform.sickness == 'N' || Healthstatsform.sickness == 'n') {
            eligible = true;
        }

        cout << "Have you or anyone in your household had diarrhea or vomiting symptoms in the last 28 days? (Y/N) : ";
        cin >> Healthstatsform.diarrhoea;
        if (Healthstatsform.diarrhoea == 'N' || Healthstatsform.diarrhoea == 'n') {
            eligible = true;
        }

        cout << "Have you taken antibiotics in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.antibiotics;
        if (Healthstatsform.antibiotics == 'N' || Healthstatsform.antibiotics == 'n') {
            eligible = true;
        }

        cout << "Have you traveled outside of New Zealand in the last 12 months? (Y/N) : ";
        cin >> Healthstatsform.travelOutNZ;
        if (Healthstatsform.travelOutNZ == 'N' || Healthstatsform.travelOutNZ == 'n') {
            eligible = true;
        }

        cout << "Have you tested positive for COVID-19 in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.covid19;
        if (Healthstatsform.covid19 == 'N' || Healthstatsform.covid19 == 'n') {
            eligible = true;
        }
    }

    if (eligible) {
        cout << "Congratulations! You are eligible to donate blood or plasma. Please continue to book an appointment" << endl;
    }
    else {
        cout << "Sorry, you are not eligible to donate blood or plasma." << endl;
    }
}