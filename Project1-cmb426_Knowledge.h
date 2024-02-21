#include <vector>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Knowledge_base{
    public:

        // The possible attacks that can occur in the program
        vector<string>conclusions = {"Cyber Attack", "Malware attack", "DDoS Attack", "Phishing Attack", "Man-in-the-Middle Attack", "Brute Force Attack"};

        // Variables that contains troubleshooting questions
        vector<string>variables = {"Computer Slow", "E-mail From Suspicious Address", "Credential Request", "Urgent Action Demands",
        "Compromised Email", "Internet Redirects/Pop-ups", "Modification of Network Data", "ARP Spoofing or MAC Address Impersonation", "Suspicious Traffic", "Flood of Traffic", 
        "Inability to Retrieve Sensor Data", "Repeated Failed Login Attempts", "Repeated Error Messages", "Computer Freezing", "Data Manipulation", "System Vulenrability",
        "Suspicious E-mail Links", "Malicious Software Installation", "Information Leakage", "Inappropriate ADS", "Demanding Ransom"};

        // Combinations that will lead to a solution of a(n) attack
        vector<vector<int>>troubleshoot_combinations = {
            {0,6,14}, {6,14,15}, {0,4,11}, {6,18,20}, {0,18,20}, //CyberAttack
            {0,3,17}, {0,5,17}, {12,17,19}, {0,17,19}, {5,17,19}, // Malware
            {0,8,9}, {0,8,10}, {8,9,10}, {9,10,13}, {0,8,13}, // DDoS
            {0,1,3}, {0,1,2}, {1,2,3}, {1,4,16}, {3,4,16}, // Phishing
            {0,5,7}, {0,7,8}, {5,7,8}, {0,8}, {5,8}, // MitM
            {0,9,11}, {0,11,13}, {9,11,13}, {0,11}, {9,11}  // Brute
        };


        // Clauses assignment
        vector<int> cyber_clause = {0,6,14,15,18,20};
        vector<int> malware_clause = {0,3,5,12,17,19};
        vector<int> ddos_clause = {0,8,9,10,13}; 
        vector<int> phishing_clause = {0,1,2,3,4,16};
        vector<int> man_in_the_middle_clause = {0,5,7,8};
        vector<int> brute_force_clause = {0,9,11,13};

        vector<vector<int>> clause_index =  {cyber_clause, malware_clause, ddos_clause, phishing_clause, man_in_the_middle_clause, brute_force_clause};
        

        // Function declarations
        map<string, int> variable_initialized = initialized_variable_list(variables);
        vector<int> clause_variable_list = initialized_clause_list(20, clause_index);

        // Initializing the variable list
        map<string, int> initialized_variable_list(std::vector<std::string> variable_list) 
        {
            map<string, int> initialized;

            for(string variable : variable_list)
            {
                pair<string, int> key_value;
                key_value = std::make_pair(variable, -1);
                initialized.insert(key_value);
            }
            return initialized;
        }

        // Initializing the clause list
        vector<int> initialized_clause_list(int numRules, vector<vector<int>>clause_index) 
        {
            vector<int>clause_variable_list(numRules * clause_index.size());

            for(int i = 0; i < clause_index.size(); i++)
            {
                int begin_at = i * numRules;
                for(auto variable_index : clause_index[i])
                {
                    clause_variable_list[begin_at + variable_index] = 1;
                }
            }
            return clause_variable_list;
        }
};
