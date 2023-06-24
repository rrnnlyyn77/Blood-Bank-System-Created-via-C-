#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct RequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodOrPlasma;
    string BloodType;
    int NumBags;
};

void DisplayRequest(const RequestForm& form) {
    cout << "***Request from Recipient***" << std::endl;
    cout << "Username: " << form.Username << std::endl;
    cout << "Establishment Name: " << form.EstablishmentName << std::endl;
    cout << "Date Required: " << form.DateRequired << std::endl;
    cout << "Blood or Plasma: " << form.BloodOrPlasma << std::endl;
    cout << "Blood Type Required: " << form.BloodType << std::endl;
    cout << "Number of Bags: " << form.NumBags << std::endl;
    cout << "------------------------------------------" << std::endl;
}

void ViewAllRequests(const std::string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Failed to open the request file." << std::endl;
        return;
    }

    string read;
    RequestForm request;

    while (std::getline(file, read)) {
        if (read.find("Username: ") != std::string::npos) {
            request.Username = read.substr(read.find(": ") + 2);
        }

        else if (read.find("Establishment Name: ") != string::npos) {
            request.EstablishmentName = read.substr(read.find(": ") + 2);
        }

        else if (read.find("Date Required: ") != string::npos) {
            request.DateRequired = read.substr(read.find(": ") + 2);
        }
        else if (read.find("Blood or Plasma: ") != string::npos) {
            request.BloodOrPlasma = read.substr(read.find(": ") + 2);
        }
        else if (read.find("Blood Type Required: ") != string::npos) {
            request.BloodType = read.substr(read.find(": ") + 2);
        }
        else if (read.find("Number of Bags: ") != string::npos) {
            request.NumBags = std::stoi(read.substr(read.find(": ") + 2));

     DisplayRequest(request);

     request = RequestForm();
        }
    }

    file.close();
}

int main() {

    system("Color 4F");

    ViewAllRequests("Requests.txt");

    return 0;
}
