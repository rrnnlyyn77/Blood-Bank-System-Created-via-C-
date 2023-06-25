#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>

struct Appointment {
    std::string username;
    std::string eligibilityForm;
    std::string date;
    std::string time;
    std::string donationType;
    std::string bloodType;
    std::string plasma;
};

void loadAppointmentsFromFile(const std::string& filename, std::vector<Appointment>& appointments) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    appointments.clear();
    std::string line;
    Appointment appointment;
    while (std::getline(file, line)) {
        if (line.find("Username: ") != std::string::npos) {
            appointment.username = line.substr(line.find("Username: ") + 10);
        }
        else if (line.find("Eligibility Form: ") != std::string::npos) {
            appointment.eligibilityForm = line.substr(line.find("Eligibility Form: ") + 18);
        }
        else if (line.find("Date: ") != std::string::npos) {
            appointment.date = line.substr(line.find("Date: ") + 6);
        }
        else if (line.find("Time: ") != std::string::npos) {
            appointment.time = line.substr(line.find("Time: ") + 6);
        }
        else if (line.find("Donation Type: ") != std::string::npos) {
            appointment.donationType = line.substr(line.find("Donation Type: ") + 15);
            appointments.push_back(appointment);
        }
        else if (line.find("Blood Type: ") != std::string::npos) {
            appointment.bloodType = line.substr(line.find("Blood Type: ") + 12);
            appointments.push_back(appointment);
        }
        else if (line.find("Plasma: ") != std::string::npos) {
            appointment.plasma = line.substr(line.find("Plasma: ") + 13);
        }
    }

    file.close();
}

void displayAppointments(const std::vector<Appointment>& appointments) {
    std::cout << "Appointments:\n";
    std::cout << std::setw(15) << std::left << "Username"
        << std::setw(18) << std::left << "Eligibility Form"
        << std::setw(10) << std::left << "Date"
        << std::setw(8) << std::left << "Time"
        << std::setw(15) << std::left << "Donation Type" << "\n"
        << std::setw(10) << std::left << "Blood Type" << "\n";

    std::cout << "------------------------------------------------------------\n";
    for (const auto& appointment : appointments) {
        std::cout << std::setw(15) << std::left << appointment.username
            << std::setw(18) << std::left << appointment.eligibilityForm
            << std::setw(10) << std::left << appointment.date
            << std::setw(8) << std::left << appointment.time
            << std::setw(15) << std::left << appointment.donationType
            << std::setw(10) << std::left << appointment.bloodType << "\n";
    }
}

void deleteAppointment(int index, std::vector<Appointment>& appointments, const std::string& filename) {
    if (index >= 0 && index < appointments.size()) {
        appointments.erase(appointments.begin() + index);
        std::cout << "Appointment deleted successfully!\n";

        // Update the file contents
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error opening file: " << filename << "\n";
            return;
        }

        for (const auto& appointment : appointments) {
            file << "Username: " << appointment.username << "\n";
            file << "Eligibility Form: " << appointment.eligibilityForm << "\n";
            file << "Date: " << appointment.date << "\n";
            file << "Time: " << appointment.time << "\n";
            file << "Donation Type: " << appointment.donationType << "\n\n";
        }

        file.close();
    }
    else {
        std::cout << "Invalid appointment index.\n";
    }
}

std::map<std::string, int> countDonationTypes(const std::vector<Appointment>& appointments) {
    std::map<std::string, int> countMap;
    for (const auto& appointment : appointments) {
        if (appointment.donationType == "blood") {
            countMap[appointment.bloodType]++;
        }
        else if (appointment.donationType == "plasma") {
            countMap[appointment.plasma]++;
        }
    }
    return countMap;
}

void displayBloodTypeInventory(const std::vector<Appointment>& appointments) {
    std::map<std::string, int> inventory;
    for (const auto& appointment : appointments) {
        if (appointment.donationType == "blood") {
            inventory[appointment.bloodType]++;
        }
    }

    std::map<std::string, int> countMap = countDonationTypes(appointments);

    std::cout << "------------------------------------------------------------\n";
    std::cout << "Blood and Plasma Inventory:\n";
    for (const auto& item : inventory) {
        std::cout << std::setw(15) << std::left << item.first
            << std::setw(18) << std::left << ""
            << std::setw(10) << std::left << ""
            << std::setw(8) << std::left << ""
            << std::setw(15) << std::left << ""
            << std::setw(10) << std::left << item.second << " bags\n";
    }
}

int main() {
    std::vector<Appointment> appointments;
    std::string filename = "appointments.txt";

    // Load appointments from the file
    loadAppointmentsFromFile(filename, appointments);

    // Admin Menu
    int choice = 0;
    while (choice != 3) {
        std::cout << "\nAdmin Menu:\n";
        std::cout << "1. Display Appointments\n";
        std::cout << "2. Delete Appointment\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            displayAppointments(appointments);
            displayBloodTypeInventory(appointments); 
            break;
        case 2: {
            int index;
            std::cout << "Enter the index of the appointment to delete: ";
            std::cin >> index;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            deleteAppointment(index, appointments, filename);
            break;
        }
        case 3:
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
