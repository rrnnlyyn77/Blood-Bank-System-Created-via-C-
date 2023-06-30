#include "recipient_viewrequest.h"

void DisplayRequest(const VRequestForm& form) {
    cout << "***Request from Recipient***" << std::endl;
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
    VRequestForm request;
    bool foundRequest = false;
    bool inRequestBlock = false;

    while (getline(file, line)) {
        if (line == "------------------------------------------") {
            if (inRequestBlock) {
                inRequestBlock = false;
                if (request.Username == username) {
                    DisplayRequest(request);
                    foundRequest = true;
                }
                request = VRequestForm();
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

    if (!foundRequest) {
        cout << "No requests found for the given username." << endl;
    }
}
