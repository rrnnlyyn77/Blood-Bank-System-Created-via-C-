// 1.103.2NZBlood-Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions_and_declarations.h"

#include <iostream>
#include <windows.h> 
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <regex>

using namespace std;

void systemMainMenu();

void AboutCompany()
{
    cout << "                                                                              About the company:\n";
    cout << "\n";
    cout << "                                                                           1. View Upcoming Events\n";
    cout << "                                                                           2. View Past Events\n";
    cout << "                                                                           3. Go back to Main Menu\n";

    int choice;
    cin >> choice;
    system("cls");
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
        cout << "                        |____________________________________________________________________________________________________________________|\n\n\n";
        AboutCompany();
        system("cls");
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
        cout << "                        |____________________________________________________________________________________________________________________|\n\n\n";
        AboutCompany();
        system("cls");
        break;
    case 3:
        system("cls");
        systemMainMenu();
    default:
        cout << "Incorrect choice!\n";
        system("cls");
        systemMainMenu();
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
    cout << "                        |____________________________________________________________________________________________________________________|\n\n\n";
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

void donorMenu() {

    int choice;
    while (true) {
        cout << "                                                                         Donor Menu: \n";
        cout << "                                                                         _______________\n";
        cout << "\n";
        cout << "                                                                 1. View Profile\n";
        cout << "                                                                 2. Modify Profile\n";
        cout << "                                                                 3. Check Eligibility\n";
        cout << "                                                                 4. Book a donation\n";
        cout << "                                                                 5. Logout\n";
        cout << " \n";
        cout << "                                                                 Enter your choice:";
        cin >> choice;

        healthStatsForm healthStats;
        switch (choice) {
        case 1:
            system("cls");
            ViewDonorProfile();
            cout << "\n";
            donorMenu();
            system("cls");
            break;
        case 2:
            system("cls");
            modifyDonorProfile();
            cout << "\n";
            donorMenu();
            system("cls");
            break;
        case 3:
            system("cls");
            getNDHealthStatus(healthStats);
            cout << "\n";
            donorMenu();
            system("cls");
            break;
        case 4:
            system("cls");
            bookAppointment();
            cout << "\n";
            donorMenu();
            system("cls");
            break;
        case 5:
            cout << "Logged out as a Donor.\n";
            system("cls");
            systemMainMenu();
            break;
        default:
            cout << "Incorrect choice. Try again.\n";
            break;
        }
    }
}

void recipientMenu() {
    int choice;
    while (true) {
        cout << "Recipient Menu: \n";
        cout << "_______________\n";
        cout << "\n";
        cout << "1. View Profile\n";
        cout << "2. Modify Profile\n";
        cout << "3. Submit Blood/Plasma Request\n";
        cout << "4. View Request\n";
        cout << "5. Logout\n";
        cout << " \n";
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            viewRecipientProfile();
            cout << "\n";
            recipientMenu();
            system("cls");
            break;
        case 2:
            system("cls");
            modifyRecipientProfile();
            cout << "\n";
            recipientMenu();
            system("cls");
            break;
        case 3:
            system("cls");
            requestBloodRecipientForm();
            cout << "\n";
            recipientMenu();
            system("cls");
            break;
        case 4:
            system("cls");
            viewRRequests();
            cout << "\n";
            recipientMenu();
            system("cls");
            break;
        case 5:
            cout << "                                                          Logged out as a Recipient.\n";
            system("cls");
            systemMainMenu();
            break;
        default:
            cout << "                                                          Incorrect choice. Try again.\n";
            systemMainMenu();
            break;
        }
    }
}

bool RAMainMenu() {
    int choice;
    while (true) {
        cout << "Recipient Administrator Menu:\n";
        cout << "_____________________________\n";
        cout << "\n";
        cout << "1. View Recipients' Profile\n";
        cout << "2. Modify Recipients' Profile\n";
        cout << "3. View Specific Request\n";
        cout << "4. Delete Specific Request\n";
        cout << "5. Process Requests\n";
        cout << "6. Logout\n";
        cout << " \n";
        cout << "Enter your choice:";
        cin >> choice;
        system("CLS");

        string RAVusername;
        string RAPusername;
        switch (choice) {
        case 1:
            system("cls");
            viewRecipientProfile();
            cout << "\n";
            RAMainMenu();
            system("cls");
            break;
        case 2:
            system("cls");
            modifyRecipientProfile();
            cout << "\n";
            RAMainMenu();
            system("cls");
            break;
        case 3:
            system("cls");
            cout << "Enter Recipient's Username: "; cin >> RAVusername;
            ViewRequestByUsername("Requests.txt", RAVusername);
            cout << "\n";
            RAMainMenu();
            system("cls");
            break;
        case 4:
            system("cls");
            cout << "Enter Recipient's username: "; cin >> RAVusername;
            DeleteRequestByUsername("Requests.txt", RAVusername);
            cout << "\n";
            RAMainMenu();
            system("cls");
            break;
        case 5:
            system("cls");
            cout << "Process Requests";
            cout << "\n\n";
            cout << "Enter recipient's username to view and process request: "; cin >> RAPusername;
            ViewRequestByUsername("Requests.txt", RAPusername);
            cout << endl;
            CheckStockAvailability("donation_inventory.txt");
            cout << "\n";
            RAMainMenu();
            system("cls");
            break;
        case 6:
            cout << "Logged out as a Recipient Administrator.\n";
            system("cls");
            systemMainMenu();
            break;
        default:
            cout << "Incorrect choice. Try again.\n";
            systemMainMenu();
            break;
        }
    }
}

bool DAMainMenu () {
    int choice;
    while (true) {
        cout << "Donor Administrator Menu:\n";
        cout << "_____________________________\n";
        cout << "\n";
        cout << "1. View a Donor Profile\n";
        cout << "2. Modify a Donor Profile\n";
        cout << "3. Book Appointment for Donor \n";
        cout << "4. View Pending Donation Appointments\n";
        cout << "5. Change Appointment Status\n";
        cout << "6. Display Completed Appointments\n";
        cout << "7. Display Donation Bank\n";
        cout << "8. Logout\n";
        cout << " \n";
        cout << "Enter your choice:";
        cin >> choice;
        system("CLS");

        vector<DAviewAppointment> pendingAppointments;
        vector<DAviewAppointment> completedAppointments;
        string pendingFilename = "pending_appointments.txt";
        string completedFilename = "completed_appointments.txt";
        string donationInventoryFilename = "donation_inventory.txt";

        loadAppointmentsFromFile(pendingFilename, pendingAppointments);
        loadAppointmentsFromFile(completedFilename, completedAppointments);

        switch (choice) {
        case 1:
            system("cls");
            ViewDonorProfile();
            cout << "\n";
            DAMainMenu();
            system("cls");
            break;
        case 2:
            system("cls");
            modifyDonorProfile();
            cout << "\n";
            DAMainMenu();
            system("cls");
            break;
        case 3:
            system("cls");
            bookAppointment();
            cout << "\n";
            DAMainMenu();
            system("cls");
            break;
        case 4:
            system("cls");
            displayAppointments(pendingAppointments);
            cout << setw(63) << "\n";
            system("pause");
            system("cls");
            DAMainMenu();
            system("cls");
            break;
        case 5:
            system("cls");
            displayAppointments(pendingAppointments);
            cout << setw(63) << "\nEnter the index of the appointment to mark complete (from index 0): ";
            int index;
            cin >> index;
            deleteAppointment(index, pendingAppointments, pendingFilename, completedFilename);
            recordDonationInventory(completedAppointments, donationInventoryFilename);
            cout << setw(63) << "\n";
            system("pause");
            system("cls");
            DAMainMenu();
            system("cls");
            break;
        case 6:
            system("cls");
            displayCompletedAppointments(completedAppointments);
            cout << setw(63) << "\n";
            system("pause");
            system("cls");
            DAMainMenu();
            system("cls");
            break;
        case 7: 
            system("cls");
            displayDonationTypeInventory(completedAppointments);
            cout << setw(63) << "\n";
            system("pause");
            system("cls");
            DAMainMenu();
            system("cls");
            break;
        case 8:
            cout << "                                                      Logged out as a Donor Administrator.\n";
            system("cls");
            systemMainMenu();
            break;
        default:
            cout << "                                                           Incorrect choice. Try again.\n";
            systemMainMenu();
            break;
        }
    }

}

bool loginAsDonor() {
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
    return false;*/
    // Prompt for login
    string username, password;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "Welcome to Donor Login\n";
        cout <<"-----------------------" << "\n";
        cout << "Username  : ";
        cin >> username;
        cout << "Password  : ";
        cin >> password;

        loggedIn = login(username, password);

        if (!loggedIn) {
            cout << "\n";
            cout << "Invalid username or password." << endl;
        }
    }

    system("cls");
    donorMenu();
    return 0;
}

bool loginAsDonorAdmin() {
    string username, password;
    cout << "\n";
    cout << "Donor Administrator Login\n";
    cout << "_________________________\n";
    cout << "\n";
    cout << "Donor Administrator Username: ";
    cout << "\n";
    cin >> username;
    cout << "Donor Administrator Password: ";
    cin >> password;
    system("CLS");

    ifstream file("DAUserPass.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            cout << "\n";
            cout << "                                                                 Logged in as a Donor Administrator.\n";
            cout << "\n";

            system("cls");
            DAMainMenu();
        }
    }

    cout << "                                                                               Invalid username or password. Login failed.\n";
    return false;
}

bool loginAsRecipient() {
    /*string username, password;
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
    return false;*/
    string username, password;
    bool loggedIn = false;

    while (!loggedIn) {
        cout << "Welcome to Recipient Login\n";
        cout << "----------------------------" << "\n\n";
        cout << "Username  : ";
        cin >> username;
        cout << "Password  : ";
        cin >> password;

        loggedIn = Rlogin(username, password);

        if (!loggedIn) {
            cout << "\n";
            cout << "Invalid username or password." << endl;
        }
    }

    system("cls");
    recipientMenu();
    return 0;

}

bool loginAsRecipientAdmin() {
    string username, password;
    cout << "\n";
    cout << "Recipient Administrator Login\n";
    cout << "_____________________________\n";
    cout << "\n";
    cout << "Recipient Administrator Username:";
    cout << "\n";
    cin >> username;
    cout << "Recipient Administrator Password:";
    cin >> password;
    system("CLS");

    ifstream file("RAUserPass.txt");
    string storedUsername, storedPassword;

    while (file >> storedUsername >> storedPassword) {
        if (username == storedUsername && password == storedPassword) {
            cout << "\n";
            cout << "                                                            Logged in as a Recipient Administrator.\n";
            cout << "\n";

            system("cls");
            RAMainMenu();
        }
    }

    cout << "                                                                    Invalid username or password. Login failed.\n";
    return false;
}

void systemMainMenu(){

    char choice;
    char details;
    int recchoice;

    do {
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


        switch (choice) {
        case '1':
            cout << "\nView Public Information\n";
            cout << "\n";
            cout << "1. About the company\n";
            cout << "2. Latest News and Updates\n";
            cout << "3. View Eligibility Criteria\n";
            cout << "4. Contact Information\n";
            cout << "5. Go back to Main Menu\n\n";
            cout << "Enter your choice: ";

            int subChoice;
            cin >> subChoice;
            system("CLS");

            switch (subChoice) {
            case 1:
                AboutCompany();
                break;

            case 2:
                LatestNews();
                cout << "\n\n";
                systemMainMenu();
                break;

            case 3:
                EligibilityCriteria();
                cout << "\n\n";
                systemMainMenu();
                break;

            case 4:
                ContactInformation();
                cout << "\n\n";
                systemMainMenu();
                break;

            default:
                cout << "Incorrect choice!\n";
                system("cls");
                systemMainMenu();
            }
            break;

        case '2':
            cout << "New Registration:\n";
            cout << "\n";
            cout << "1. New Donor\n";
            cout << "2. New Recipient\n";
            cout << "3. Go back to Main Menu\n";
            cout << "\n";
            cout << "Enter your choice: ";

            cin >> subChoice;
            system("CLS");

            switch (subChoice) {
            case 1:
                registerAndLogin();
                systemMainMenu();
                break;

            case 2:
                recipientRegistrationAndLogin();
                systemMainMenu();
                break;
            case 3:
                system("cls");
                systemMainMenu();
                break;
            default:
                cout << "Incorrect choice!\n";
            }
            break;

        case '3':
            while (true) {
                cout << "\n";
                cout << "Choose your relevant Login Option\n";
                cout << "_________________________________\n";
                cout << "\n";
                cout << "Login as a:\n";
                cout << "\n";
                cout << "1. Donor\n";
                cout << "2. Donor Administrator\n";
                cout << "3. Recipient\n";
                cout << "4. Recipient Administrator\n";
                cout << "5. Go back to Main Menu\n";
                cout << "\n";
                cout << "Enter your choice: ";
                cin >> recchoice;
                system("CLS");

                switch (recchoice) {
                case 1:
                    if (loginAsDonor())
                        cout << "R\n" << endl;
                    break;
                case 2:
                    if (loginAsDonorAdmin())
                        cout << "R\n" << endl;
                    break;
                case 3:
                    if (loginAsRecipient())
                        //cout << "R\n" << endl;
                        break;
                case 4:
                    if (loginAsRecipientAdmin())
                        //cout << "R\n" << endl;
                        break;
                case 5:
                    system("cls");
                    systemMainMenu();
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n" << endl;
                    break;
                }
            }

        case 'L':
            cout << "You have successfully logged out the system\n";
            cout << "\n";
            break;

        default:
            cout << "Incorrect choice!\n";
        }

    } while (choice != 'l');


}

int main()
{
    systemMainMenu();

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
