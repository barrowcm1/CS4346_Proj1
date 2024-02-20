#include <vector>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>

class Knowledge_engine{
    public:

        // The possible attacks that can occur in the program
        std::vector<std::string>conclusions = {"Cyber Attack", "Malware attack", "Phishing", "Cyber Attack", "Denial of Service Attack", "Brute Force"};

        // Variables that contains troubleshooting questions
        std::vector<std::string>variables = {"Computer slow", "Suspucious Email Requests", "Unsolicited Requests", "Urgent Action Demands",
        "Compromised Email", "Redirected Internet", "IP Address Modified", "Unable to Login", "Suspicious Traffic", "Flood of Traffic", 
        "inability to Retrieve Sensor Data", "Computer Won't Sshutdown", "Repeated Error Messages", "Computer Freezing", "Crashes", "Diminishing Storage",
        "Strange Emails", "Redirecting Internet Searches", "Browser Redirect", "Inappropriate ADS", "Demanding Ransom",};


        // Combinations that will lwad to solution of a(n) attack
        std::vector<std::vector<int>>troubleshoot_combinations = {
            {0,4,7}, {0,4,10}, {0,4,11}, {0,1,10}, {0,1,11}, //CyberAttack
            {0,4,12}, {0,7,13}, {0,7,14}, {0,7,15}, {0,7,16}, // Malware
            {0,7,8}, {0,7,9}, {0,7,10}, {0,6,7}, {0,6,8}, // DDoS
            {1,2,3}, {0,1,2}, {0,4,5}, {0,1,5}, {1,3}, // Phishing
            {0,5,6}, {0,4,8}, {0,4,18}, {0,5,8}, {0,5,18}, // MitM
            {0,2,4}, {0,2,5}, {1,2,4}, {1,5,8}, {1,8,18}  // Brute
        };


        // Clauses assignment
        std::vector<int> cyber_clause = {0,1,4,7,10,11,18,19,20};
        std::vector<int> malware_clause = {0,7,12,13,14,15,16};
        std::vector<int> phishing_clause = {0,1,2,3,4,5,16,20};
        std::vector<int> ddos_clause = {0,6,7,8,9,10};
        std::vector<int> man_in_the_middle_clause = {0,4,5,6,7,8,18};
        std::vector<int> brute_force_clause = {0,1,2,4,5,8,18,19};

        std::vector<std::vector<int>> clause_index =  {cyber_clause, malware_clause, phishing_clause, ddos_clause, 
                                                       man_in_the_middle_clause, brute_force_clause};
        
        std::map<std::string, int> variable_initialized = variable_initialized_list(variables);
        std::vector<int> clause_variable_list = initialized_clause_list(20, clause_index);

        std::map<std::string, int> variable_initialized(std::vector<std::string> variable_list)



};