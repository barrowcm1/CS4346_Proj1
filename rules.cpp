#include "rules.h"
#include <vector>
#include <iostream>
#include <string>

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
        cout << "It is recommended that you block popups and ads, change any passwords you may have \n";
        cout << "given to the malicious sender, and report any further attempts at phishing to abuse@txstate.edu \n";
        break;

        case AttackType::MALWARE:
        cout << "It is recommended that you scan and clean your computer with an antivirus software \n";
        cout << "or seek help from a Computer Technician. \n";
        break;

        case AttackType::DDOS:
        cout <<"It is recommended that you patch youre server or implement network monitoring and \n";
        cout << "filtering with an authentication firewall. \n";
        break;

        case AttackType::CYBER_ATTACK:
        cout << "It is recommended that you contain the cyber breach by disabling remote access and \n";
        cout << "implementing better authentication features. \n";
        break;

        case AttackType::MAN_IN_THE_MIDDLE:
        cout << "It is recommended that you get a VPN and set up a strong WEP/WAP encryption. \n";
        break;

        case AttackType::BRUTE_FORCE:
        cout << "It is recommended that you change all your passwords and have protective measures \n";
        cout << "implemented that will lock your account after a certain number of failed login attempts. \n";
        break;

        default:
        cout <<"No preventive solutions are recommended. \n";
    }
}

