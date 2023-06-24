#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;

void DeleteRequest(const string& EstablishmentName, const string& DateRequired) {
    ifstream inFile("Requests.txt");
    ofstream outFile("temp.txt");

    if (inFile.is_open() && outFile.is_open()) {
        string read;
        bool deleted = false;

        while (getline(inFile, read)) {
            if (read.find("Establishment Name: " + EstablishmentName) != string::npos &&
                getline(inFile, read) && read.find("Date Required: " + DateRequired) != string::npos) {
                deleted = true; 
            }
            else {
                outFile << read << endl;
            }
        }

        inFile.close();
        outFile.close();

        remove("Requests.txt");
        rename("temp.txt", "Requests.txt");

        if (deleted) {
            cout << "The request from " << EstablishmentName << " for " << DateRequired << " has been deleted." << endl;
        }
        else {
            cout << "The request from " << EstablishmentName << " for " << DateRequired << " was not found." << endl;
        }
    }
    else {
        cout << "Unable to open the file. Deletion failed." << endl;
    }
}

int main() {

    system("Color 4F");

    string establishmentName, dateRequired;

    cout << "Enter the Establishment Name for the request you want to delete: ";
    getline(cin, establishmentName);

    cout << "Enter the Date Required for the request you want to delete: ";
    getline(cin, dateRequired);

    DeleteRequest(establishmentName, dateRequired);

    return 0;
}
