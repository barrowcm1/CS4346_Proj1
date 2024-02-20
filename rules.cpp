#include "rules.h"

using namespace std;

// Symptoms list for each attack type
const vector<AttackSymptoms> attackSymptoms = {
    {AttackType::PHISHING, {
        "Reports of users falling victim to deceptive messages or emails",
        "Users have reported receiving suspicious emails requesting sensitive info",
        "User has provided sensitive information after clicking on a suspicious link",
        "User has encountered unexpected redirects to login pages/forms asking for credentials"
    }}
    // so on.... so forth

};

/* function to identify the attack by comparing the vector created in either
    forward or backwardchaining.cpp to one of the vectors above
    ex.) AttackType identifyAttack( ....) {
        .........
    }
        return attackType; */

// Recommend preventative measures
void recommendedPreventions(AttackType attackType) {
    switch (attackType) {
        case AttackType::PHISHING:
        cout << "blah blah blah";
        break;
        //and so on......
    }
}

