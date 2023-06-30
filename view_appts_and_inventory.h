
#ifndef VIEW_APPTS_AND_INVENTORY_H
#define VIEW_APPTS_AND_INVENTORY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <windows.h>
#include <limits>

using namespace std;

struct viewAppointment {
    string username;
    string eligibilityForm;
    string date;
    string time;
    string donationType;
    string bloodType;
    string apptStatus;
};

void loadAppointmentsFromFile(const std::string&, std::vector<viewAppointment>&);
void displayAppointments(const vector<viewAppointment>& appointments);
void displayCompletedAppointments(const vector<viewAppointment>& appointments);
void deleteAppointment(int index, vector<viewAppointment>& appointments, const string& pendingFilename, const string& completedFilename);
map<string, int> countDonationTypes(const vector<viewAppointment>& appointments);
void recordDonationInventory(const vector<viewAppointment>& appointments, const string& filename);
void displayDonationTypeInventory(const vector<viewAppointment>& appointments);

#endif // VIEW_APPTS_AND_INVENTORY_H
