#include "view_appts_and_inventory.h"

void loadAppointmentsFromFile(const string& filename, vector<viewAppointment>& appointments) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << "\n";
        return;
    }

    appointments.clear();
    string line;
    viewAppointment appointment;
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

void displayAppointments(const vector<viewAppointment>& appointments) {
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

void displayCompletedAppointments(const vector<viewAppointment>& appointments) {
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

void deleteAppointment(int index, vector<viewAppointment>& appointments, const string& pendingFilename, const string& completedFilename) {
    if (index >= 0 && index < appointments.size()) {
        viewAppointment deletedAppointment = appointments[index];
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

map<string, int> countDonationTypes(const vector<viewAppointment>& appointments) {
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

void recordDonationInventory(const vector<viewAppointment>& appointments, const string& filename) {
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

void displayDonationTypeInventory(const vector<viewAppointment>& appointments) {
    map<string, int> inventory = countDonationTypes(appointments);

    cout << setw(85) << right << "Donation Inventory\n";
    cout << setw(88) << right << "-------------------------\n";
    for (const auto& item : inventory) {
        cout << setw(68) << right << item.first
            << setw(12) << right << item.second << " bags\n";
    }
}