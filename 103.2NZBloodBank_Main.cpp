// 103.2NZBloodBank_Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "donor_registration.h"
#include "recipient_registration.h"
#include "display_donor_profile.h"
#include "modify_delete_profile.h"
#include "book_appointment.h"
#include "view_appts_and_inventory.h"
#include "recipient_viewprofile.h"
#include "recipient_modifyprofile.h"
#include "recipient_requestform.h"
#include "recipient_viewrequest.h"


#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

void ModifyMenu() {
    cout << setw(82) << "Modify Donor Profile" << endl;
    cout << setw(80) << "1. Update Profile" << endl;
    cout << setw(80) << "2. Delete Profile" << endl;
    cout << "\n";
    cout << setw(82) << "Enter your choice     : ";
}

int recipientSubChoice;
void recipientSubMenu() {
    int recipientChoice;

    cout << "                                                                         Recipient Menu: \n";
    cout << "                                                                         _______________\n";
    cout << "\n";
    cout << "                                                                 1. View Profile\n";
    cout << "                                                                 2. Modify Profile\n";
    cout << "                                                                 3. Submit Blood/Plasma Request\n";
    cout << "                                                                 4. View Request\n";
    cout << "                                                                 5. Logout\n";
    cout << " \n";
    cout << "                                                                 Enter your choice:";
    cin >> recipientSubChoice;
}

bool recipientMenu() {
    
    recipientSubMenu();
    
    system("cls");
    //for view profile 
    string fileName = "recipient_details.txt";
    ifstream inputFile(fileName);
    vector<RProfile> rprofiles;
    RProfile Rprofile;
    string line;
    string Rrusername;

    //for modify profile
    string MfileName = "recipient_details.txt";
    ifstream MinputFile(MfileName);
    vector<Profile> profiles;
    Profile profile;
    string Mline;
    string username;
    ofstream outputFile(MfileName);

    //for submit request form
    RequestForm form;

    //for view request
    std::string VRusername;

    switch (recipientSubChoice) {
    case 1:
       
        if (!inputFile.is_open()) {
            cout << "Failed to open the profile file." << endl;
            return 1;
        }

   
        while (getline(inputFile, line)) {
            if (line.find("Username:") != string::npos) {
                Rprofile.RUsername = line.substr(line.find(":") + 1);
                removeSpaces(Rprofile.RUsername);
            }
            else if (line.find("Password:") != string::npos) {
                Rprofile.RPassword = line.substr(line.find(":") + 1);
                removeSpaces(Rprofile.RPassword);
            }
            else if (line.find("Email:") != string::npos) {
                Rprofile.REmail = line.substr(line.find(":") + 1);
                removeSpaces(Rprofile.REmail);
            }
            else if (line.find("Establishment Name:") != string::npos) {
                Rprofile.REstablishmentName = line.substr(line.find(":") + 1);
                removeSpaces(Rprofile.REstablishmentName);
            }
            else if (line.find("Phone:") != string::npos) {
                Rprofile.RPhone = line.substr(line.find(":") + 1);
                removeSpaces(Rprofile.RPhone);
            }
            else if (line.find("NZ Address:") != string::npos) {
                Rprofile.RAddress = line.substr(line.find(":") + 1);
                removeSpaces(Rprofile.RAddress);
                rprofiles.push_back(Rprofile);
                Rprofile = RProfile();
            }
        }

        inputFile.close();

        cout << "View Recipient Profile" << endl;
        cout << " " << endl;
        cout << "Enter your Username: "; cin >> Rrusername;
        //getline(cin, Rrusername);

        displayProfile(Rrusername, rprofiles);
        recipientSubMenu();
        system("cls");
        break;
    case 2:
 
        if (!inputFile.is_open()) {
            cout << "Failed to open the profile file." << endl;
            return 1;
        }
     
        while (getline(inputFile, line)) {
            if (line.find("Username:") != string::npos) {
                profile.Username = line.substr(line.find(":") + 1);
                MRremoveSpaces(profile.Username);
            }
            else if (line.find("Password:") != string::npos) {
                profile.Password = line.substr(line.find(":") + 1);
                MRremoveSpaces(profile.Password);
            }
            else if (line.find("Email:") != string::npos) {
                profile.Email = line.substr(line.find(":") + 1);
                MRremoveSpaces(profile.Email);
            }
            else if (line.find("Establishment Name:") != string::npos) {
                profile.EstablishmentName = line.substr(line.find(":") + 1);
                MRremoveSpaces(profile.EstablishmentName);
            }
            else if (line.find("Phone:") != string::npos) {
                profile.Phone = line.substr(line.find(":") + 1);
                MRremoveSpaces(profile.Phone);
            }
            else if (line.find("NZ Address:") != string::npos) {
                profile.Address = line.substr(line.find(":") + 1);
                MRremoveSpaces(profile.Address);
                profiles.push_back(profile);
                profile = Profile();
            }
        }

        inputFile.close();

        cout << "View Recipient Profile" << endl;
        cout << " " << endl;
        cout << "Enter your Username: "; cin >> username;
        //getline(cin, username);

        displayProfile(Rrusername, rprofiles);

        cout << endl;
        cout << "Modify Profile Menu" << endl;
        cout << "1. Update Profile" << endl;
        cout << "2. Delete Profile" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            updateProfile(username, profiles);
            break;
        case 2:
            deleteProfile(username, profiles);
            break;
        default:
            cout << "Invalid choice." << endl;
            break;
        }

        if (!outputFile.is_open()) {
            cout << "Failed to open the profile file for writing." << endl;
            return 1;
        }

        for (const auto& profile : profiles) {
            outputFile << "Username: " << profile.Username << endl;
            outputFile << "Password: " << profile.Password << endl;
            outputFile << "Email: " << profile.Email << endl;
            outputFile << "Establishment Name: " << profile.EstablishmentName << endl;
            outputFile << "Phone: " << profile.Phone << endl;
            outputFile << "NZ Address: " << profile.Address << endl;
            outputFile << endl;
        }

        outputFile.close();
        break;
    case 3:
     
        cout << "                                                                      Blood/Plasma Recipient Request Form" << endl;
        cout << "                                                                      ___________________________________" << endl;

        cout << "                                                                   Username: ";
        getline(cin, form.Username);
        cin.ignore();

        cout << "                                                                   Establishment Name: ";
        getline(cin, form.EstablishmentName);
        cin.ignore();

        cout << "                                                                   Date Required (dd/mm/yy): ";
        getline(cin, form.DateRequired);
        cin.ignore();

        cout << "                                                                   What Blood Type do you require - Eg. A+, O+, B+ or Plasma? ";
        getline(cin, form.BloodType);
        cin.ignore();

        cout << "                                                                   Number of Bags required (1 bag = 470ml per bag): ";
        getline(cin, form.NumBags);
        cin.ignore();

        system("CLS");

        cout << "\n";
        cout << "                                                                   Thank you. Your request has been submitted" << endl;
        SubmitReqForm(form);
        break;
    case 4:
       
        cout << "View Your Request";
        cout << "\n\n";

        cout << "Enter your username: ";
        getline(cin, VRusername);

        ViewRequestByUsername("Requests.txt", VRusername);
        break;
    case 5:
        cout << "                                                          Logged out as a Recipient.\n";
        return true;
    default:
        cout << "                                                          Incorrect choice. Try again.\n";
        break;
    }
}

bool donorMenu() {

    int donorChoice;

    cout << "                                                                         Donor Menu: \n";
    cout << "                                                                         _______________\n";
    cout << "\n";
    cout << "                                                                 1. View Profile\n";
    cout << "                                                                 2. Modify Profile\n";
    cout << "                                                                 3. Book Appointment\n";
    cout << "                                                                 4. Logout\n";
    cout << " \n";
    cout << "                                                                 Enter your choice:";
    cin >> donorChoice;

    string DonorUsername;
    ViewProfile profile = FindProfileByUsername(DonorUsername);

    int userChoice2;

    //for booking appt

    std::vector<Appointment> BAappointments;
    std::string BAusername;
    std::string BAeligibilityForm;
    std::string BAdate;
    std::string BAtime;
    std::string BAdonationType;
    std::string BAbloodType;
    std::string BAstatus = "Pending";
    Appointment appointment;

    switch (donorChoice) {
    case 1: //view profile
        
        cout << setw(85) << right << "Enter your username: ";
        cin >> DonorUsername;

        system("cls");

        cout << setw(90) << right << "Welcome to your Donor Profile!" << "\n\n";
      
        if (!profile.DonorUsername.empty()) {
            DisplayProfile(profile);
        }
        else {
            cout << "Profile not found." << endl;
        }
        break;

    case 2://modify profile
        do {
            ModifyMenu();
            cin >> userChoice2;

            switch (userChoice2) {
            case 1:
                UpdateProfile();
                break;
            case 2:
                DeleteProfile();
                break;
            default:
                cout << "Incorrect choice." << endl;
                break;
            }
            cout << endl;
        } while (userChoice2 != 1 && userChoice2 != 2);

        break;

    case 3://book appointment
        system("cls");

        cout << setw(80) << right << "Appointment Booking Form";
        cout << "\n\n";

        cout << setw(88) << right << "Enter your username                  : ";
        cin >> BAusername;

        cout << "\r" << setw(88) << right << "Submitted eligibility form (yes/no)  : ";
        cin >> BAeligibilityForm;

        if (BAeligibilityForm != "yes") {
            displayError("you are not eligible to donate.");
            return 0;
        }

        cout << "\r" << setw(88) << right << "Preferred date (dd/mm/yy)            : ";
        cin >> BAdate;

        cout << "\r" << setw(88) << right << "Preferred time (between 10am to 6pm) : ";
        cin >> BAtime;

        while (!isAppointmentAvailable(BAappointments, BAdate, BAtime)) {
            cout << "\n";
            cout << "\t\t\t\t------------------------------------------------------------------------------";
            cout << "\n";
            displayError("an appointment has already been booked for your preferred date and time.");
            cout << "\t\t\t\t------------------------------------------------------------------------------";
            cout << "\n\n";
            cout << "\r" << setw(88) << right << "Choose another date (dd/mm/yy)       : ";
            cin >> BAdate;
            cout << "\r" << setw(88) << right << "Choose another time (between 10am to 6pm) : ";
            cin >> BAtime;
        }

        cout << "\r" << setw(88) << right << "Will you donate blood or plasma?     : ";
        cin >> BAdonationType;

        if (BAdonationType == "blood") {
            cout << "\r" << setw(88) << right << "Please enter your blood type         : ";
            cin >> BAbloodType;
        }

        appointment = { BAusername, BAeligibilityForm, BAdate, BAtime, BAdonationType, BAbloodType, BAstatus };
        addAppointment(BAappointments, appointment);
        saveAppointmentsToFile("pending_appointments.txt", BAappointments);

        displayConfirmationMessage();
     
        break;

    case 4:
        cout << "                                                          Logged out as a Donor.\n";
        return true;
    default:
        cout << "                                                          Incorrect choice. Try again.\n";
        break;
    }
}

void donorAdminMenu() {
    vector<viewAppointment> pendingAppointments;
    vector<viewAppointment> completedAppointments;
    string pendingFilename = "pending_appointments.txt";
    string completedFilename = "completed_appointments.txt";
    string donationInventoryFilename = "donation_inventory.txt";

    loadAppointmentsFromFile(pendingFilename, pendingAppointments);
    loadAppointmentsFromFile(completedFilename, completedAppointments);


    int choice = 0;
    while (choice != 5) {
        cout << setw(80) << right << "Admin Menu:\n";
        cout << setw(90) << right << "1. Display Pending Appointments\n";
        cout << setw(93) << right << "2. Delete Appointment from Pending\n";
        cout << setw(92) << right << "3. Display Completed Appointments\n";
        cout << setw(88) << right << "4. Display Donation Inventory\n";
        cout << setw(88) << right << "5. View Donors' Profile\n";
        cout << setw(88) << right << "6. Modify Donors' Profile\n";
        cout << setw(67) << right << "7. Logout\n\n";
        cout << setw(84) << right << "Enter your choice: ";

        cin >> choice;
        const streamsize maxStreamSize = 1000000;
        cin.ignore(maxStreamSize, '\n');

        cout << "\n";

        system("cls");

        string DonorUsername;
        ViewProfile profile = FindProfileByUsername(DonorUsername);
        int userChoice2;

        switch (choice) {
        case 1:
            displayAppointments(pendingAppointments);
            cout << setw(63) << "\n";
            system("pause");
            break;
        case 2: {
            displayAppointments(pendingAppointments);
            cout << "Enter the index of the appointment to delete: ";
            int index;
            cin >> index;
            deleteAppointment(index, pendingAppointments, pendingFilename, completedFilename);
            recordDonationInventory(completedAppointments, donationInventoryFilename);
            cout << setw(63) << "\n";
            system("pause");
            break;
        }
        case 3:
            displayCompletedAppointments(completedAppointments);
            cout << setw(63) << "\n";
            system("pause");


            break;
        case 4:
            displayDonationTypeInventory(completedAppointments);
            cout << setw(63) << "\n";
            system("pause");

            break;
        case 5:
            cout << setw(85) << right << "Enter donor's username: ";
            cin >> DonorUsername;

            system("cls");

            cout << setw(90) << right << "Donor Profile" << "\n\n";

            if (!profile.DonorUsername.empty()) {
                DisplayProfile(profile);
            }
            else {
                cout << "Profile not found." << endl;
            }
            break;

            break;
        case 6:
            do {
                ModifyMenu();
                cin >> userChoice2;

                switch (userChoice2) {
                case 1:
                    UpdateProfile();
                    break;
                case 2:
                    DeleteProfile();
                    break;
                default:
                    cout << "Incorrect choice." << endl;
                    break;
                }
                cout << endl;
            } while (userChoice2 != 1 && userChoice2 != 2);

            break;
        case 7:
            cout << setw(80) << right << "Exiting program...\n";

            break;
           
        default:
            cout << setw(100) << right << "Invalid choice. Please enter a valid option.\n";
            break;
        }

        cout << "\n\n";
    }

}

void AboutCompany()
{
    cout << "                                                                              About the company:\n";
    cout << "\n";
    cout << "                                                                           1. View Upcoming Events\n";
    cout << "                                                                           2. View Past Events\n";

    int choice;
    cin >> choice;
    system("CLS");

    switch (choice)
    {
    case 1:
        cout << "                         ____________________________________________________________________________________________________________________\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |***********************************************NEW ZEALAND BLOOD BANK***********************************************|\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "\n";
        cout << "                                                                     **** UPCOMING EVENTS ****\n";
        cout << "                         ____________________________________________________________________________________________________________________\n";
        cout << "                        |                   New Zealand celebrates National Blood Donor Week 12 June 2023 to 17 June 2023                    |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "                        |June 2023                                                                                                        |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |This week, New Zealand Blood Service (NZBS) marks the start of its second annual National Blood Donor Week by       |\n";
        cout << "                        |calling for 40000 more New Zealanders to * Find their Why * and become lifesavers. National Blood Donor Week is a   |\n";
        cout << "                        |way for NZBS to acknowledge the generosity of the New Zealand donor community, and to encourage others to join the  |\n";
        cout << "                        |donor registry.                                                                                                     |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |We currently have 117,000 amazing donors who help save the lives of 30,000 people every year.                       |\n";
        cout << "                        |But with a growing and ageing population, and more blood and plasma being needed for patients – New Zealand is      |\n";
        cout << "                        |facing higher demands than ever for blood and blood products,” says Asuka Burge, NZBS National Marketing &          |\n";
        cout << "                        |Communications Manager. The number of people on the donor registry has only grown by 9,000 donors in the past five  |\n";
        cout << "                        |years. That’s why we are always looking to recruit new donors to replace donors who for many reasons can no longer  |\n";
        cout << "                        |donate.                                                                                                             |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |However, we have reached a tipping point. If we can’t encourage more people to join the donor registry,             |\n";
        cout << "                        |we may no longer continue to be self-reliant for blood and plasma products in Aotearoa. Every 18 minutes in New     |\n";
        cout << "                        |Zealand, someone requires a lifesaving transfusion of blood or plasma. Currently, less than four percent of         |\n";
        cout << "                        |the eligible population are donating. NZBS needs 40,000 new donors in the next 12 months to ensure it can continue  |\n";
        cout << "                        |to be self - reliant and meet demand. People can find out if they are eligible to donate by visiting                |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |People can find out if they are eligible to donate by visiting https://www.nzblood.co.nz/, or calling 0800 448 325. |\n";
        cout << "                        |If they’re likely to be eligible, they can book an appointment at their nearest donor centre or mobile drive by     |\n";
        cout << "                        |downloading the New Zealand Blood Service Donor App. We’re extremely grateful to our dedicated community of         |\n";
        cout << "                        |voluntary donors who help ensure that blood and products are always available for whomever may need them, says Ms   |\n";
        cout << "                        |Burge. If you’ve ever considered donating, there is no better time to find your ‘why’ and have a go than this       |\n";
        cout << "                        |National Blood Donor Week. It is only with New Zealanders’ recognition and support for self - reliance that we can  |\n";
        cout << "                        |continue to protect our blood supply for years to come.                                                             |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "\n";
        cout << "\n";
        cout << "                         ____________________________________________________________________________________________________________________\n";
        cout << "                        |                                 Celebrating 25 years of New Zealand Blood Service                                  |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "                        |May 2023                                                                                                            |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |July 1 will mark a milestone birthday for New Zealand Blood Service as we celebrate turning 25!                     |\n";
        cout << "                        |NZBS was established in 1998 to create a single, integrated blood service for all of New Zealand.Our job then, like |\n";
        cout << "                        |today, was to ensure the safe and sufficient supply of blood and blood products – a job we couldn’t do without you, |\n";
        cout << "                        |our donors. During the past 25 years, more than 600,000 donors have stepped up to help improve and save the lives of|\n";
        cout << "                        |more than half a million people.Your contributions have been staggering - we have received more than:               |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |3.1 million blood donations                                                                                         |\n";
        cout << "                        |865,000 plasma donations, and                                                                                       |\n";
        cout << "                        |98,000 platelet donations                                                                                           |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |We have also sent more than 1.3 million kilograms of plasma to Australia, where it’s transformed into 11 different  |\n";
        cout << "                        |products that are returned to New Zealand for use by people here.And we’ve grown – we are now home to Organ Donation|\n";
        cout << "                        |New Zealand, New Zealand’s National Heart Valve Bank, and the New Zealand Bone Marrow Donor Registry.               |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Much has changed over the past 25 years; New Zealand’s population has grown from 3.8 million to five million; new   |\n";
        cout << "                        |diseases, tests, technologies, and treatments have been introduced; we’ve navigated challenges such as the          |\n";
        cout << "                        |Christchurch earthquakes and COVID-19. What hasn’t changed, is the consistent and growing need for blood and plasma,|\n";
        cout << "                        |the selfless generosity of our donors, the heartfelt gratitude of recipients, and the commitment of our staff.      |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |This July, the best birthday gift we could receive is your donation – we look forward to seeing you!                |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        break;

    case 2:
        cout << "                         ____________________________________________________________________________________________________________________\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |***********************************************NEW ZEALAND BLOOD BANK***********************************************|\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "\n";
        cout << "                                                                     **** PAST EVENTS ****\n";
        cout << "                         ____________________________________________________________________________________________________________________\n";
        cout << "                        |                                  Celebrations as new Waikato Blood Bank opens                                      |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "                        |November 2022                                                                                                       |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |The new Waikato Blood Bank has this morning been officially blessed and opened on the Waiora Waikato Hospital       |\n";
        cout << "                        |campus. New Zealand Blood Service (NZBS) will lease and operate the purpose-built facility, which was constructed by|\n";
        cout << "                        |Te Whatu Ora Health New Zealand in a joint arrangement with NZBS.                                                   |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Te Whatu Ora Waikato’s Interim District Co-Director Chris Lowry says the $2 million blood bank is the first new     |\n";
        cout << "                        |building to be opened on the campus in more than a decade.                                                          |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Having blood and blood products readily to hand is essential for the timely care of our patients. As a tertiary     |\n";
        cout << "                        |centre and trauma hospital, it’s an essential service we cannot do without.                                         |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Each week the Waikato Blood Bank issues around 180 units of red blood cells and 35 units of platelets as well as    |\n";
        cout << "                        |testing around 100 blood samples to match hospital patients with compatible blood products.                         |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Often, it’s not until you or someone close to you needs blood to survive that you think about how these products    |\n";
        cout << "                        |make their way to you. A lot happens between when our donors generously donate and when a patient receives the end  |\n";
        cout << "                        |product - blood banks are a vital link in that lifesaving chain.                                                    |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |The New Zealand Blood Service Waikato Blood Bank team will vacate their old facility of 15 years and begin operating|\n";
        cout << "                        |from their new one in around a week.                                                                                |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |The Waikato Blood Bank services Waikato Hospital, Thames Hospital, Te Kuiti Hospital, Tokoroa Hospital and three    |\n";
        cout << "                        |private hospitals.                                                                                                  |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "\n";
        cout << "\n";
        cout << "                         ____________________________________________________________________________________________________________________ \n";
        cout << "                        |                     Sky Tower lights up gold to highlight the skyrocketing need for plasma donors                  |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "                        |September 2022                                                                                                      |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |The Sky Tower, New Zealand’s largest needle, is being lit up gold on Monday September 5 to highlight the sky-high   |\n";
        cout << "                        |need for plasma and plasma donors.                                                                                  |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |The golden needle marks the start of New Zealand Blood Service’s (NZBS) new campaign dedicated to shining a light on|\n";
        cout << "                        |the increasing need of plasma and the importance it plays in helping people manage ongoing health conditions.       |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |In a major shift in demand, NZBS now requires more plasma donations than blood donations, with more than 7000 new   |\n";
        cout << "                        |plasma donors needed across Aotearoa to help collect 130,000 plasma donations in the next 12 months.                |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |And right now, it is tracking more than 5000 donations behind where it needs to be.                                 |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Asuka Burge, NZBS National Marketing and Communications Manager, says the demand is growing every year with the     |\n";
        cout << "                        |coming year’s target jumping up by 12.9%.                                                                           |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |That is being driven by the increasing need for immunoglobulin products, also known as Ig, such as Intragam P and   |\n";
        cout << "                        |Evogam. These products are used for a variety of treatments for people with low levels of antibodies, either through|\n";
        cout << "                        |illness such as infections, or cancers of the white blood cells and bone marrow, as well as some autoimmune         |\n";
        cout << "                        |disorders.                                                                                                          |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Many patients who use Ig products require lifetime treatment on a regular basis, some as frequently as once a week. |\n";
        cout << "                        |These people can’t just skip treatment, so we need Kiwis to not skip giving.                                        |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |To become a plasma donor, you need to meet donor eligibility criteria – including being over 50kg, aged 16-70       |\n";
        cout << "                        |and be over 150cm tall. You can find out if you’re eligible to donate by visiting                                   |\n";
        cout << "                        |https://www.nzblood.co.nz/give-plasma/.                                                                             |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |To help manage the increasing need for plasma, NZBS has taken measures to help make it easier for Kiwis to donate   |\n";
        cout << "                        |through introducing more late night and Saturday plasma sessions at some of its sites.                              |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |Plasma donation is currently available at donor centres in Auckland (North Shore, Epsom and Manukau), Hamilton,     |\n";
        cout << "                        |Tauranga, Palmerston North, Wellington, Christchurch and Dunedin.                                                   |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |There are also mobile plasma drives held across Auckland, a regular mobile plasma drive in Avalon in Wellington     |\n";
        cout << "                        |and a new plasma donation centre in Tuam Street in Christchurch.                                                    |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        break;

    default:
        cout << "Incorrect choice!\n";
    }
}

void LatestNews()
{
    cout << "                         ____________________________________________________________________________________________________________________\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |***********************************************NEW ZEALAND BLOOD BANK***********************************************|\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "\n";
    cout << "                                                                        **** LATEST NEWS ****                                                 \n";
    cout << "                         ____________________________________________________________________________________________________________________ \n";
    cout << "                        |                           Vyron: ‘Because of plasma donors, I have my whole life ahead of me                       |\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "                        |May 2023                                                                                                            |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Vyron needed 150 plasma transfusions over the course of nine days after he was diagnosed with an extremely rare,    |\n";
    cout << "                        |life-threatening and progressive autoimmune disease (aHUS) that attacked his one remaining kidney.                  |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Finding out that plasma could help with this disease gave me the hope I needed to fight for my life, he says.       |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |I now have a new perspective and can continue on with my life. I want to help as many people as I can on their      |\n";
    cout << "                        |health and wellness journey, and raise awareness about donating blood and plasma.                                   |\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "\n";
    cout << "\n";
    cout << "                         ____________________________________________________________________________________________________________________ \n";
    cout << "                        |                                      Mobile Blood Drive returns to Queenstown                                      |\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "                        |April 2023                                                                                                          |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |A big reason why we don’t often visit the Queenstown Lakes District to collect is because it poses some logistical  |\n";
    cout << "                        |and financial challenges for us in terms of flying donated blood back to Christchurch each day for processing in a  |\n";
    cout << "                        |timely manner once it has been collected.                                                                           |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Despite this, the Southern team listened to the feedback they’d received from donors and were able to work around   |\n";
    cout << "                        |that by collecting earlier in the day.                                                                              |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |The mobile drive took place at St Margaret's Church in Frankton over three days aiming to collect 200 donations     |\n";
    cout << "                        |while in the area. We actively promoted the mobile blood drive in the Queenstown Lakes District four weeks in       |\n";
    cout << "                        |advance to ensure we had the best shot at filling appointments – posters, press ads and community FB posts were used|\n";
    cout << "                        |to help spread the word. Kris Perkins, a local mum, and marketer whose four year old son had recently been the      |\n";
    cout << "                        |recipient of blood, provided important on the ground support – connecting us to business and community groups. We   |\n";
    cout << "                        |also had a lot of media interest from local newspapers about what we were doing – this coverage helped us educate   |\n";
    cout << "                        |people about what it had been so long since we last visited and promote the importance of getting involved.         |\n";
    cout << "                        |The Queenstown Lakes District community turned out in force to ensure we hit our collection targets during the three|\n";
    cout << "                        |days we were there.                                                                                                 |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |We collected 217 donations saving up to 650 lives. A great result!                                                  |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Linda Burt, our Southern Donor Relations Coordinator told us “Queenstown was very chilly but despite that, the      |\n";
    cout << "                        |mobile went well. It was VERY well received by the residents of not only Queenstown but surrounding areas like      |\n";
    cout << "                        |Wanaka. A mix of people showed up to donate. There were a lot of walkin’s plus lapsed and new donors provided       |\n";
    cout << "                        |support which was fantastic. People were enquiring when we’re coming back as they’re really hoping to see us again  |\n";
    cout << "                        |soon. We’ll give some thought to that taking into consideration the logistical challenges we face collecting in     |\n";
    cout << "                        |this region.                                                                                                        |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Though teamwork, perseverance and thinking differently about how to tackle a big challenge like this just goes to   |\n";
    cout << "                        |show what’s possible when you put your mind to it.                                                                  |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Thanks to everyone in Queenstown Lakes District involved in helping us.                                             |\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";

}

void EligibilityCriteria()
{
    cout << "                         ____________________________________________________________________________________________________________________\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |***********************************************NEW ZEALAND BLOOD BANK***********************************************|\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "\n";
    cout << "                                                                    **** ELIGIBILITY CRITERIA ****                                            \n";
    cout << "                         ____________________________________________________________________________________________________________________ \n";
    cout << "                        |Age:                                                                                                                |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |New blood or plasma donors can make their first donation any time after their 16th birthday and before their 71st   |\n";
    cout << "                        |birthday. Existing * donors can donate until their 75th birthday and may continue to donate until their 81st        |\n";
    cout << "                        |birthday, subject to authorisation from a NZBS Medical Officer. Lapsed** donors who have passed their 71st birthday |\n";
    cout << "                        |may be eligible to donate, subject to authorisation by a NZBS Medical Officer.                                      |\n";
    cout << "                        |* Existing donors – have donated blood within the last 2 years.                                                     |\n";
    cout << "                        |* *Lapsed donors - are those who have donated before more than 2 years ago.                                         |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Weight:                                                                                                             |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |You must weigh 50 kg or more and to donate plasma you must also be at least 150 cm tall. Donors under 25 years must |\n";
    cout << "                        |meet additional height and weight criteria.                                                                         |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Health:                                                                                                             |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |You must be in good health at the time you donate. You cannot donate if you have a cold, flu, sore throat, cold     |\n";
    cout << "                        |sore, stomach bug or any other infection.                                                                           |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |COVID-19:                                                                                                           |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |If you’ve had COVID-19, you’ll need to wait seven days after you are free of symptoms or after the date of your last|\n";
    cout << "                        |positive test (if you have no symptoms) before you can donate blood or plasma.                                      |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Tattoos and Piercings:                                                                                              |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |If you‘ve recently had a tattoo (including cosmetic tattoos, such as microblading), cosmetic injectables or a body  |\n";
    cout << "                        |piercing, you must wait 3 months from the date of the procedure before you can donate                               |\n";
    cout << "                        |Note: If the cosmetic injectable or body piercing was performed by a registered health professional(i.e.pharmacist, |\n";
    cout << "                        |GP) and any inflammation has settled completely, you can donate after 12 hours.                                     |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Travel:                                                                                                             |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |You must not have lived in the United Kingdom, France or the Republic of Ireland between 1980 and 1996 for a        |\n";
    cout << "                        |cumulative 6 months or more. Find out why here.                                                                     |\n";
    cout << "                        |Travel to areas where mosquito-borne infections are endemic, e.g. malaria, dengue and Zika virus infections, may    |\n";
    cout << "                        |result in a temporary deferral but this will depend on a number of factors, please check the Donating after         |\n";
    cout << "                        |Travelling tool to find out when you can donate.                                                                    |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Behaviour Criteria:                                                                                                 |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |*Following oral or anal sex with or without a condom with another man (if you are male).                            |\n";
    cout << "                        |*After engaging in sex work (prostitution) or accepting payment in exchange for sex.                                |\n";
    cout << "                        |*After leaving a country in which you have lived and which is considered to be high risk of HIV infection (includes |\n";
    cout << "                        |sub Saharan Africa and parts of Asia). Check out our Donating After Travelling tool for a full list of these        |\n";
    cout << "                        |countries                                                                                                           |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Pregnancy:                                                                                                          |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |Following pregnancy, you will not be eligible to donate blood or plasma for as many months as your pregnancy was    |\n";
    cout << "                        |long. In most cases, this is 9 months.                                                                              |\n";
    cout << "                        |For criteria relating to Miscarriage or Termination, please see our Detailed Eligibility Criteria page.             |\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
}

void ContactInformation()
{
    cout << "                         ____________________________________________________________________________________________________________________\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |***********************************************NEW ZEALAND BLOOD BANK***********************************************|\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |                                           **** CONTACT INFORMATION ****                                            |\n";
    cout << "                        |                                                                                                                    |\n";
    cout << "                        |                                         *** Telephone Number: 0800 448 325                                         |\n";
    cout << "                        |                                         *** Facebook Handle : New Zealand Blood Service                            |\n";
    cout << "                        |                                         *** You Tube        : Save Lives Give Blood                                |\n";
    cout << "                        |                                         *** Instagram Handle: NZ Blood Service                                     |\n";
    cout << "                        |                                         *** Linked-In Handle: New Zealand Blood Service                            |\n";
    cout << "                        |____________________________________________________________________________________________________________________|\n";
    cout << "\n";
}

void registerNewDonor()
{
    newDonor donor;

    // Register a new donor
    getNewDonorDetails(donor);

    std::cout << "\n";
    std::cout << std::setw(93) << std::right << "Registration complete, please check your inbox for a confirmation email. ";

    // Clear the screen
    std::system("pause");
    std::system("CLS");

}

void registerNewRecipient()
{
    newRecipient recipient;

    // Register a new recipient
    getNewRecipientDetails(recipient);

    std::cout << "\n";
    std::cout << std::setw(93) << std::right << "Registration complete, please check your inbox for a confirmation email. ";

    // Clear the screen
    std::system("pause");
    std::system("CLS");

}

/*bool loginAsDonor(string& nDusername, string& nDpassword) {
    /*string username, password;
    cout << "\n";
    cout << "                                                                                   Donor Login\n";
    cout << "                                                                                   ___________\n";
    cout << "\n";
    cout << "                                                                        Donor Username:";
    cin >> username;
    cout << "                                                                        Donor Password:";
    cin >> password;
    system("CLS");

    ifstream file("DonorsUserPass.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            cout << "                                                                          Logged in as a Donor\n";
            return true;
        }
    }

    cout << "                                                                               Invalid username or password. Login failed.\n";
    return false;
}

    std::cout << std::setw(80) << std::right << "Login\n";
    std::cout << std::setw(80) << std::right << "Username: ";
    std::getline(std::cin, nDusername);
    std::cout << std::setw(80) << std::right << "Password: ";
    std::getline(std::cin, nDpassword);

  
}*/

bool loginAsDonorAdmin() {


    string username, password;
    cout << "\n";
    cout << "                                                                            Donor Administrator Login\n";
    cout << "                                                                            _________________________\n";
    cout << "\n";
    cout << "                                                                       Donor Administrator Username: ";
    cout << "\n";
    cin >> username;
    cout << "                                                                       Donor Administrator Password: ";
    cin >> password;
    system("CLS");

    ifstream file("DAUserPass.txt");
    string storedUserDAUserPassname, storedDAUPassword;

    while (file >> storedUserDAUserPassname >> storedDAUPassword) {
        if (username == storedUserDAUserPassname && password == storedDAUPassword) {
            cout << "                                                                 Logged in as a Donor Administrator.\n";
            return true;
        }
    }

    cout << "                                                                               Invalid username or password. Login failed.\n";
    return false;
}

/*bool loginAsRecipient() {
    string username, password;
    cout << "\n";
    cout << "                                                                            Recipient Login\n";
    cout << "                                                                            _______________\n";
    cout << "\n";
    cout << "                                                                   Recipient Username: ";
    cout << "\n";
    cin >> username;
    cout << "                                                                   Recipient Password: ";
    cin >> password;
    system("CLS");

    ifstream file("RecipientUserPass.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            cout << "\n";
            cout << "                                                                   Logged in as a Recipient.\n";
            cout << "\n";

            int choice;
            while (true) {
                cout << "                                                                         Recipient Menu: \n";
                cout << "                                                                         _______________\n";
                cout << "\n";
                cout << "                                                                 1. View Profile\n";
                cout << "                                                                 2. Modify Profile\n";
                cout << "                                                                 3. Submit Blood/Plasma Request\n";
                cout << "                                                                 4. View Request\n";
                cout << "                                                                 5. Logout\n";
                cout << " \n";
                cout << "                                                                 Enter your choice:";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << "view profile" << endl;
                    break;
                case 2:
                    cout << "modify profile" << endl;
                    break;
                case 3:
                    cout << "Submit request" << endl;
                    break;
                case 4:
                    cout << "View request" << endl;
                    break;
                case 5:
                    cout << "                                                          Logged out as a Recipient.\n";
                    return true;
                default:
                    cout << "                                                          Incorrect choice. Try again.\n";
                    break;
                }
            }
        }
    }

    cout << "                                                            Incorrect username or password. Login failed.\n";
    return false;
}*/

bool loginAsRecipientAdmin() {
    string username, password;
    cout << "\n";
    cout << "                                                                     Recipient Administrator Login\n";
    cout << "                                                                     _____________________________\n";
    cout << "\n";
    cout << "                                                         Recipient Administrator Username:";
    cout << "\n";
    cin >> username;
    cout << "                                                         Recipient Administrator Password:";
    cin >> password;
    system("CLS");

    ifstream file("RAUserPass.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            cout << "\n";
            cout << "                                                            Logged in as a Recipient Administrator.\n";
            cout << "\n";

            int choice;
            while (true) {
                cout << "                                                               Recipient Administrator Menu:\n";
                cout << "                                                               _____________________________\n";
                cout << "\n";
                cout << "                                                              1. View Profile\n";
                cout << "                                                              2. Modify Profile\n";
                cout << "                                                              3. Modify Request List\n";
                cout << "                                                              4. View Request\n";
                cout << "                                                              5. Logout\n";
                cout << " \n";
                cout << "                                                              Enter your choice:";
                cin >> choice;
                system("CLS");

                switch (choice) {
                case 1:
                    cout << "View profile\n" << endl;
                    break;
                case 2:
                    cout << "Modify profile\n" << endl;
                    break;
                case 3:
                    cout << "Modify request list\n" << endl;
                    break;
                case 4:
                    cout << "View request\n" << endl;
                    break;
                case 5:
                    cout << "                                                      Logged out as a Recipient Administrator.\n";
                    return true;
                default:
                    cout << "                                                           Incorrect choice. Try again.\n";
                    break;
                }
            }
        }
    }

    cout << "                                                                    Invalid username or password. Login failed.\n";
    return false;
}


int main()
{
    system("Color 4F");
    char choice;
    char details;
    string username, password;
    int recchoice;

    do
    {
        cout << "                         ____________________________________________________________________________________________________________________\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |***********************************************NEW ZEALAND BLOOD BANK***********************************************|\n";
        cout << "                        |                                                      Main Menu                                                     |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |                                        1. View information about New Zealand Blood Bank                            |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |                                        2. Register                                                                 |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |                                        3. Login                                                                    |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |                                         Press 'L' if you wish to Logout the system                                 |\n";
        cout << "                        |                                                                                                                    |\n";
        cout << "                        |                                         Enter your choice:                                                         |\n";
        cout << "                        |____________________________________________________________________________________________________________________|\n";
        cin >> choice;
        system("CLS");


        switch (choice)
        {
        case '1':
            cout << "\n                                                                  View Public Information\n";
            cout << "\n";
            cout << "                                                             1. About the company\n";
            cout << "                                                             2. Latest News and Updates\n";
            cout << "                                                             3. View Eligibility Criteria\n";
            cout << "                                                             4. Contact Information\n\n";
            cout << "\n";
            cout << "                                                                Enter your choice: ";

            int subChoice;
            cin >> subChoice;
            system("CLS");

            switch (subChoice)
            {
            case 1:
                AboutCompany();
                break;

            case 2:
                LatestNews();
                break;

            case 3:
                EligibilityCriteria();
                break;

            case 4:
                ContactInformation();
                break;

            default:
                cout << "                                                                      Incorrect choice!\n";
            }
            break;

        case '2':
            cout << "                                                                       New Registration:\n";
            cout << "\n";
            cout << "                                                                 1. New Donor\n";
            cout << "                                                                 2. New Recipient\n";
            cout << "\n";
            cout << "                                                                    Enter your choice: ";

            cin >> subChoice;
            system("CLS");

            switch (subChoice)
            {
            case 1:
                registerNewDonor();
                break;

            case 2:
                registerNewRecipient();
                break;

            default:
                cout << "                                                                      Incorrect choice!\n";
            }
            break;

        case '3':
            while (true) {
                cout << "\n";
                cout << "                                                                    Choose your relevant Login Option\n";
                cout << "                                                                    _________________________________\n";
                cout << "\n";
                cout << "                                                                              Login as a:\n";
                cout << "\n";
                cout << "                                                                 1. Donor\n";
                cout << "                                                                 2. Donor Administrator\n";
                cout << "                                                                 3. Recipient\n";
                cout << "                                                                 4. Recipient Administrator\n";
                cout << "                                                                 5. Logout\n";
                cout << "\n";
                cout << "                                                                 Enter your choice: ";
                cin >> recchoice;
                system("CLS");

                std::string nDusername, nDpassword;
                std::string Rusername, password;


                switch (recchoice) {
                case 1:
                    // Prompt for login
                   
                    std::cout << std::setw(80) << std::right << "Login\n";
                    std::cout << std::setw(80) << std::right << "Username: "; cin >> nDusername;

                    //std::getline(std::cin, nDusername);
                  
                    std::cout << std::setw(80) << std::right << "Password: ";  cin >> nDpassword;
                    //std::getline(std::cin, nDpassword);

                    if (donorLogin(nDusername, nDpassword)) {
                        std::cout << "\n";
                        std::cout << std::setw(88) << std::right << "Login successful!" << std::endl;
                        std::system("cls");
                        donorMenu();
                    }
                    else {
                        std::cout << "\n";
                        std::cout << std::setw(88) << std::right << "Invalid username or password." << std::endl;
                    }
              
                    break;
                case 2:
                    loginAsDonorAdmin();
                     donorAdminMenu();
                
                    break;
                case 3:

                    std::cout << std::setw(80) << std::right << "Login\n";
                    std::cout << std::setw(80) << std::right << "Username: "; cin >> Rusername;
                    //std::getline(std::cin, Rusername);
                    std::cout << std::setw(80) << std::right << "Password: "; cin >> password;
                    //std::getline(std::cin, password);

                    if (recipientLogin(Rusername, password)) {
                        std::cout << "\n";
                        std::cout << std::setw(88) << std::right << "Login successful!" << std::endl;
                        std::cout << "\n";
                        std::system("cls");

                        recipientMenu();

                    }
                    else {
                        std::cout << "\n";
                        std::cout << std::setw(88) << std::right << "Invalid username or password." << std::endl;
                        std::cout << "\n";
                        std::system("pause");
                    }
                        break;
                case 4:
                    if (loginAsRecipientAdmin())
                        //cout << "R\n" << endl;
                        break;
                case 5:
                    cout << "\n";
                    cout << "                                                             You have successfully logged out the system.\n" << endl;
                    return 0;
                default:
                    cout << "                                                                   Invalid choice. Please try again.\n" << endl;
                    break;
                }
            }


        case 'L':
            cout << "                                                            You have successfully logged out the system\n";
            cout << "\n";
            break;

        default:
            cout << "                                                                          Incorrect choice!\n";
        }

    } while (choice != 'l');

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
