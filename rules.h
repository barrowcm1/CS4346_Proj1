#ifdef RULES_H
#define RULES_H
#include <string>
#include <vector>

using namespace std;

// Define different attack types
class AttackType {
    PHISHING,
    MALWARE,
    DDOS,
    CYBER_ATTACK,
    MAN_IN_THE_MIDDLE,
    BRUTE_FORCE
};

// Define symptoms; combines attack type and symptoms into one entity
struct AttackSymptoms {
    AttackType type;
    vector<string> symptoms;
};

/* !!!!! Still need to include a function to identify attack based on symptoms
ex.) AttackType identifyAttack(.......); etc... */

// Function to reccomend possible preventions
void recommendedPreventions(AttackType attackType);

#endif
