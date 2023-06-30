#include "book_appointment.h"


bool isAppointmentAvailable(const std::vector<Appointment>& appointments, const std::string& date, const std::string& time) {
    for (const auto& appointment : appointments) {
        if (appointment.date == date && appointment.time == time) {
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

void addAppointment(std::vector<Appointment>& appointments, const Appointment& appointment) {
    appointments.push_back(appointment);
}

void saveAppointmentsToFile(const std::string& filename, const std::vector<Appointment>& appointments) {
    std::ofstream file(filename, std::ios::app);
    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    for (const auto& appointment : appointments) {
        file << "Username: " << appointment.username << "\n";
        file << "Eligibility Form: " << appointment.eligibilityForm << "\n";
        file << "Date: " << appointment.date << "\n";
        file << "Time: " << appointment.time << "\n";
        file << "Donation Type: " << appointment.donationType << "\n";
        if (appointment.donationType == "blood") {
            file << "Blood Type: " << appointment.bloodType << "\n";
            file << "Status: Pending" << appointment.apptStatus << "\n";
        }
        file << "Status: Pending" << appointment.apptStatus << "\n";
        file << "\n";
    }

    file.close();
}

void displayConfirmationMessage() {
    cout << "\n";
    cout << setw(90) << right << "Appointment booked successfully!";
    cout << "\n";
}

void displayError(const std::string& message) {
    cout << setw(40) << right << "Sorry, " << message << "\n";
}