#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

struct RequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodType;
    int NumBags;
};

void DisplayRequest(const RequestForm& form) {
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
    RequestForm request;
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
                request = RequestForm();
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
        cout << "Invalid Username." << endl;
    }
}

bool ValidateYesNoInputStock(const string& input) {
    return (input == "Yes" || input == "yes" || input == "No" || input == "no");
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

        validInput = ValidateYesNoInputStock(answer);
        if (!validInput) {
            cout << "Invalid input. Please enter either 'Yes' or 'No'." << endl;
        }
    }

    if (answer == "Yes" || answer == "yes") {
        cout << "Quantity is Available. Recipients Order Confirmed. Administrator to dispatch and update inventory" << endl;
    }
    else {
        cout << "Request denied due to stock unavailability. Please inform Recipient" << endl;
    }
}

int main() {

    system("Color 4F");

    string username;
    cout << "View Your Request";
    cout << "\n\n";

    cout << "Enter your username: ";
    getline(cin, username);

    ViewRequestByUsername("Requests.txt", username);

    cout << endl;

    CheckStockAvailability("donation_inventory.txt");

    return 0;
}

