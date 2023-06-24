#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
#include <stdlib.h> 

using namespace std;

struct RequestForm {
    string Username;
    string EstablishmentName;
    string DateRequired;
    string BloodOrPlasma;
    string BloodType;
    int NumBags;
    
};

void SubmitReqForm(const RequestForm& form) {
    ofstream file("Requests.txt", ios::app );
    if (file.is_open()) {
        file << "***Request from Recipient***" << endl;
        file << "Username: " << form.Username << endl;
        file << "Establishment Name: " << form.EstablishmentName << endl;
        file << "Date Required: " << form.DateRequired << endl;
        file << "Blood or Plasma: " << form.BloodOrPlasma << endl;
        file << "Blood Type Required: " << form.BloodType << endl;
        file << "Number of Bags: " << form.NumBags << endl;
        file << "------------------------------------------" << endl;
        file.close();
    
        
    }
    else {
        cout << "                                                              Unable to open the file. Form submission failed." << endl;
    }
}

void CheckStockAvailability() {
    ifstream file("BloodTypes.txt");
    if (file.is_open()) {
        string bloodType;
        int quantity;

        while (file >> bloodType >> quantity) {
            cout << bloodType << ": " << quantity << " bags available" << endl;
        }   

        file.close();
    }
    else {
        cout << "                                                              Unable to open the file. Stock availability check failed." << endl;
    }
}

int main() {
    system("Color 4F");
    RequestForm form;

    cout << "                                                                           Blood/Plasma Recipient Request Form" << endl;
    cout << "                                                                           ___________________________________" << endl;

    cout << "                                                                           Username: ";
    getline(cin, form.Username);

    cout << "                                                                           Establishment Name: ";
    getline(cin, form.EstablishmentName);

    cout << "                                                                           Date Required: ";
    getline(cin, form.DateRequired);

    cout << "                                                                           Do you require Blood or Plasma? ";
    getline(cin, form.BloodOrPlasma);

    cout << "                                                                           What Blood Type do you require? ";
    getline(cin, form.BloodType);

    cout << "                                                                           Number of Bags required (1 bag = 470ml per bag): ";
    cin >> form.NumBags;

    cin.ignore();
    system("CLS");

    cout << "\n";
    cout << "                                               Thank you. Your request has been submitted. Please see below for stock availability." << endl; 
    SubmitReqForm(form);

    cout << "                                                                                Current stock available:" << endl;
    cout << "\n";
    CheckStockAvailability();

    return 0;
}

