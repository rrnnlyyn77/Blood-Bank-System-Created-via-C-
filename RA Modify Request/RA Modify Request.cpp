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
    RequestForm request;
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
        cout << "No requests found for the given username." << endl;
    }
}

int main() {
    system("Color 4F");

    string username;
    cout << "Welcome Recipient Administrator" << endl << endl;
    cout << "Modify a Recipients Request" << endl << endl;
    cout << "View the Recipients Request:" << endl << endl;
    cout << "Enter the Recipients Username: ";
    getline(cin, username);

    ViewRequestByUsername("Requests.txt", username);

    cout << endl << "Delete a request" << endl;
    cout << "Enter the username: ";
    getline(cin, username);

    DeleteRequestByUsername("Requests.txt", username);

    return 0;
}
