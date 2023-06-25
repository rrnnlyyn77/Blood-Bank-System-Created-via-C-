// book appt updated.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

struct Appointment {
    std::string username;
    std::string eligibilityForm;
    std::string date;
    std::string time;
    std::string donationType;
    std::string bloodType; 

};

class AppointmentBook {
private:
    std::vector<Appointment> appointments;

public:
    bool isAppointmentAvailable(const std::string& date, const std::string& time) {
        for (const auto& appointment : appointments) {
            if (appointment.date == date && appointment.time == time) {
                return false; // Appointment already booked
            }
        }

        std::ifstream file("appointments.txt");
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

    void addAppointment(const Appointment& appointment) {
        appointments.push_back(appointment);
    }

    void saveAppointmentsToFile(const std::string& filename) {
        std::ofstream file(filename, std::ios::app);
        if (!file) {
            std::cerr << "Error opening file: " << filename << "\n";
            return;
        }

        file << "Appointments:\n"; // Optional: Header for the appointment list

        for (const auto& appointment : appointments) {
            file << "Username: " << appointment.username << "\n";
            file << "Eligibility Form: " << appointment.eligibilityForm << "\n";
            file << "Date: " << appointment.date << "\n";
            file << "Time: " << appointment.time << "\n";
            file << "Donation Type: " << appointment.donationType << "\n";
            if (appointment.donationType == "blood") {
                file << "Blood Type: " << appointment.bloodType << "\n";
            }
            file << "\n";
        }

        file.close();
    }

    void updateInventory(const std::string& bloodType, int quantity) {
        std::map<std::string, int> inventory;
        std::ifstream file("blood_and_plasma_inventory.txt");

        // Read existing inventory from file
        std::string bloodTypeStr;
        int bags;
        while (file >> bloodTypeStr >> bags) {
            inventory[bloodTypeStr] = bags;
        }

        file.close();

        // Update inventory with new appointment
        inventory[bloodType] += quantity;

        // Write updated inventory back to file
        std::ofstream outFile("blood_and_plasma_inventory.txt");
        for (const auto& item : inventory) {
            outFile << item.first << " = " << item.second << " bags\n";
        }

        outFile.close();
    }

};



void displayConfirmationMessage() {
    std::cout << "Appointment booked successfully!\n";
}

void displayError(const std::string& message) {
    std::cout << "Error: " << message << "\n";
}

int main() {
    AppointmentBook appointmentBook;

    std::string username;
    std::cout << "Enter your username: ";
    std::getline(std::cin, username);

    std::string eligibilityForm;
    std::cout << "Fill in the eligibility form (yes/no): ";
    std::getline(std::cin, eligibilityForm);

    if (eligibilityForm != "yes") {
        displayError("Sorry, you are not eligible to donate.");
        return 0;
    }

    std::string date;
    std::cout << "Enter date (dd/mm/yy): ";
    std::getline(std::cin, date);

    std::string time;
    std::cout << "Enter time (between 10am to 6pm in 30-minute gaps): ";
    std::getline(std::cin, time);

    while (!appointmentBook.isAppointmentAvailable(date, time)) {
        displayError("Appointment already booked for the selected date and time.");

        std::cout << "Enter another date (dd/mm/yy): ";
        std::getline(std::cin, date);

        std::cout << "Enter another time (between 10am to 6pm in 30-minute gaps): ";
        std::getline(std::cin, time);
    }

    std::string donationType;
    std::cout << "Will you donate blood or plasma: ";
    std::getline(std::cin, donationType);

    std::string bloodType; 
    if (donationType == "blood") {
        std::cout << "Enter your blood type (e.g., A+, B-, AB+): ";
        std::getline(std::cin, bloodType);
    }

    // Displaying user's answers
    std::cout << "\nAppointment Details:\n";
    std::cout << "Username: " << username << "\n";
    std::cout << "Eligibility Form: " << eligibilityForm << "\n";
    std::cout << "Date: " << date << "\n";
    std::cout << "Time: " << time << "\n";
    std::cout << "Donation Type: " << donationType << "\n";

    // Saving appointment details to a text file
    Appointment appointment{ username, eligibilityForm, date, time, donationType, bloodType };
    appointmentBook.addAppointment(appointment);
    appointmentBook.saveAppointmentsToFile("appointments.txt");

    // Update blood and plasma inventory
    if (donationType == "blood") {
        appointmentBook.updateInventory(bloodType, 1);
    }

    displayConfirmationMessage();

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
