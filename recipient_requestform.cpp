#include "recipient_requestform.h"


void SubmitReqForm(const RequestForm& form) {
    ofstream file("Requests.txt", ios::app);
    if (file.is_open()) {
        file << "***Request from Recipient***" << endl;
        file << "Username: " << form.Username << endl;
        file << "Establishment Name: " << form.EstablishmentName << endl;
        file << "Date Required: " << form.DateRequired << endl;
        file << "What Blood Type do you require - Eg. A+, O+, B+ or Plasma?: " << form.BloodType << endl;
        file << "Number of Bags required (1 bag = 470ml per bag): " << form.NumBags << endl;
        file << "------------------------------------------" << endl;
        file.close();

    }
    else {
        cout << "                                                              Unable to open the file. Form submission failed." << endl;
    }
}