#include "eligibility_form.h"


//HEALTH STATUS FORM
//to validate new donor age (must be >=16 or <=71 years old)
bool validateNewDonorAge(int& newDonorAge)
{
    return (newDonorAge >= 16 && newDonorAge <= 71);
}
//to validate new donor weight (must be above 50kgs)
bool validateNewDonorWeight(float& newDonorWeight)
{
    return (newDonorWeight > 50);
}
//to validate new donor height (must be at least 150cm tall)
bool validateNewDonorHeight(float& newDonorHeight)
{
    return (newDonorHeight >= 150);
}

//to gather new donor health status deteils
void getNDHealthStatus(healthStatsForm& Healthstatsform)
{
    bool eligible = true;

    cout << "Health Status Form (for new donors only)" << endl;
    cout << "\n\n";

    cout << "How old are you?: "; cin >> Healthstatsform.age;
    if (!validateNewDonorAge(Healthstatsform.age)) {
        eligible = false;
    }

    cout << "Weight in kilograms (kgs): "; cin >> Healthstatsform.weight;
    if (!validateNewDonorWeight(Healthstatsform.weight)) {
        eligible = false;
    }

    cout << "Height in centimeteres (cm): "; cin >> Healthstatsform.height;
    if (!validateNewDonorHeight(Healthstatsform.height)) {
        eligible = false;
    }

    cout << "Gender (M/F): "; cin >> Healthstatsform.gender;

    if (Healthstatsform.gender == ('M' || 'm')) {

        cout << "\n\nTravel Eligibility Information";
        cout << "\n\nYou must not have lived in the United Kingdom, France or the Republic of Ireland between 1980 and 1996 for a cumulative 6 months or more." << endl;
        cout << "\n";
        cout << "Do you meet the criteria above? (Y/N) : ";
        cin >> Healthstatsform.travel;
        if (Healthstatsform.travel == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you ever injected drugs not prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.drugs;
        if (Healthstatsform.drugs == ('N' || 'n')) {
            eligible = false;
        }

        cout << "\n\nPregnancy Eligibility Information";
        cout << "\n\nFollowing pregnancy, you will not be eligible to donate blood or plasma for as many months as your pregnancy was long. In most cases, this is 9 months." << endl;
        cout << "\n";
        cout << "Have you been pregnant or given birth in the last 9 months? (Y/N) : ";
        cin >> Healthstatsform.pregnancy;
        if (Healthstatsform.pregnancy == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you taken iron medication prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.medication;
        if (Healthstatsform.medication == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you had an endoscopy in the last 4 months? (Y/N) : ";
        cin >> Healthstatsform.endoscopy;
        if (Healthstatsform.endoscopy == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you had a tattoo or piercing in the last 3 months? (Y/N) : ";
        cin >> Healthstatsform.tattoosAndpiercings;
        if (Healthstatsform.tattoosAndpiercings == ('N' || 'n')) {
            eligible = false;
        }

        cout << "MALES: Have you had anal or oral sex with another man, or have you used PEP/PrEP in the last 3 months? (Y/N) : ";
        cin >> Healthstatsform.sex;
        if (Healthstatsform.sex == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you had a cough, cold, sore throat or influenza in last 28 days? (Y/N) : ";
        cin >> Healthstatsform.sickness;
        if (Healthstatsform.sickness == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you, or anyone in your household, had diarrhoea or vomiting symptoms in the last 28 days? (Y/N) : ";
        cin >> Healthstatsform.diarrhoea;
        if (Healthstatsform.diarrhoea == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you taken antibiotics in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.antibiotics;
        if (Healthstatsform.antibiotics == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you travelled outside of New Zealand in the last 12 months? (Y/N) : ";
        cin >> Healthstatsform.travelOutNZ;
        if (Healthstatsform.travelOutNZ == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you tested positive for COVID-19 in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.covid19;
        if (Healthstatsform.covid19 == ('N' || 'n')) {
            eligible = false;
        }
    }
    else {

        cout << "\n\nTravel Eligibility Information";
        cout << "\n\nYou must not have lived in the United Kingdom, France or the Republic of Ireland between 1980 and 1996 for a cumulative 6 months or more." << endl;
        cout << "\n";
        cout << "Do you meet the criteria above? (Y/N) : ";
        cin >> Healthstatsform.travel;
        if (Healthstatsform.travel == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you ever injected drugs not prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.drugs;
        if (Healthstatsform.drugs == ('N' || 'n')) {
            eligible = false;
        }

        cout << "\n\nPregnancy Eligibility Information";
        cout << "\n\nFollowing pregnancy, you will not be eligible to donate blood or plasma for as many months as your pregnancy was long. In most cases, this is 9 months." << endl;
        cout << "\n";
        cout << "Have you been pregnant or given birth in the last 9 months? (Y/N) : ";
        cin >> Healthstatsform.pregnancy;
        if (Healthstatsform.pregnancy == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you taken iron medication prescribed by a doctor? (Y/N) : ";
        cin >> Healthstatsform.medication;
        if (Healthstatsform.medication == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you had an endoscopy in the last 4 months? (Y/N) : ";
        cin >> Healthstatsform.endoscopy;
        if (Healthstatsform.endoscopy == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you had a tattoo or piercing in the last 3 months? (Y/N) : ";
        cin >> Healthstatsform.tattoosAndpiercings;
        if (Healthstatsform.tattoosAndpiercings == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you had a cough, cold, sore throat or influenza in last 28 days? (Y/N) : ";
        cin >> Healthstatsform.sickness;
        if (Healthstatsform.sickness == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you, or anyone in your household, had diarrhoea or vomiting symptoms in the last 28 days? (Y/N) : ";
        cin >> Healthstatsform.diarrhoea;
        if (Healthstatsform.diarrhoea == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you taken antibiotics in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.antibiotics;
        if (Healthstatsform.antibiotics == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you travelled outside of New Zealand in the last 12 months? (Y/N) : ";
        cin >> Healthstatsform.travelOutNZ;
        if (Healthstatsform.travelOutNZ == ('N' || 'n')) {
            eligible = false;
        }

        cout << "Have you tested positive for COVID-19 in the last seven days? (Y/N) : ";
        cin >> Healthstatsform.covid19;
        if (Healthstatsform.covid19 == ('N' || 'n')) {
            eligible = false;
        }
    }

    if (eligible) {
        cout << "\n\nCongratulations! \nBased on your answers on the eligibility quiz, you are eligible to donate.\nPlease proceed to book appointment." << endl;
    }
    else {
        cout << "\n\nSorry, but based on your answers on the eligibility quiz, you are eligible to donate,\nto confirm your eligibilty, please visit us in person. \nOtherwise, you are not eligible to donate.." << endl;
    }


}