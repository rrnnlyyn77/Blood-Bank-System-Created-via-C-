
#ifndef BOOK_APPOINTMENT_H
#define BOOK_APPOINTMENT_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <windows.h>
#include <limits>

using namespace std;

struct Appointment {
    string username;
    string eligibilityForm;
    string date;
    string time;
    string donationType;
    string bloodType;
    string apptStatus;
};

bool isAppointmentAvailable(const std::vector<Appointment>& appointments, const std::string& date, const std::string& time);
void addAppointment(std::vector<Appointment>& appointments, const Appointment& appointment);
void saveAppointmentsToFile(const std::string& filename, const std::vector<Appointment>& appointments);
void displayConfirmationMessage();
void displayError(const std::string& message);

#endif //BOOK_APPOINTMENT_H