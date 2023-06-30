
#ifndef ELIGIBILITY_FORM_H
#define  ELIGIBILITY_FORM_H

#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <cstdlib>

using namespace std;

//health status details required (for new donors only)
struct healthStatsForm {
    int age;
    float weight, height;
    //others (yY/nN characters only)
    char covid19,
        tattoosAndpiercings,
        travel,
        pregnancy,
        drugs,
        medication,
        endoscopy,
        gender,
        sex,
        sickness,
        diarrhoea,
        antibiotics,
        travelOutNZ;

};

//HEALTH STATUS FORM
//to validate new donor age (must be >=16 or <=71 years old)
bool validateNewDonorAge(int& newDonorAge);
//to validate new donor weight (must be above 50kgs)
bool validateNewDonorWeight(float& newDonorWeight);
//to validate new donor height (must be at least 150cm tall)
bool validateNewDonorHeight(float& newDonorHeight);
//to gather new donor health status deteils
void getNDHealthStatus(healthStatsForm& Healthstatsform);

#endif // !ELIGIBILITY_FORM_H
