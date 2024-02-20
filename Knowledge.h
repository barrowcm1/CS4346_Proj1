#include <vector>
#include <stack>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

class Knowledge_engine{
    public:

        // The possible attacks that can occur in the program
        vector<string>conclusions = {"Cyber Attack", "Malware attack", "Phishing Attack", "Man-in-the-Middle Attack", "Denial of Service Attack", "Brute Force Attack"};

        // Variables that contains troubleshooting questions
        vector<string>variables = {"Computer Slow", "Suspucious Email Requests", "Unsolicited Requests", "Urgent Action Demands",
        "Compromised Email", "Redirected Internet", "IP Address Modified", "Unable to Login", "Suspicious Traffic", "Flood of Traffic", 
        "Inability to Retrieve Sensor Data", "Computer Won't Shutdown", "Repeated Error Messages", "Computer Freezing", "Crashes", "Diminishing Storage",
        "Strange Emails", "Redirecting Internet Searches", "Browser Redirect", "Inappropriate ADS", "Demanding Ransom"};


        // Combinations that will lead to a solution of a(n) attack
        vector<vector<int>>troubleshoot_combinations = {
            {0,4,7}, {0,4,10}, {0,4,11}, {0,1,10}, {0,1,11}, //CyberAttack
            {0,4,12}, {0,7,13}, {0,7,14}, {0,7,15}, {0,7,16}, // Malware
            {0,7,8}, {0,7,9}, {0,7,10}, {0,6,7}, {0,6,8}, // DDoS
            {1,2,3}, {0,1,2}, {0,4,5}, {0,1,5}, {1,3}, // Phishing
            {0,5,6}, {0,4,8}, {0,4,18}, {0,5,8}, {0,5,18}, // MitM
            {0,2,4}, {0,2,5}, {1,2,4}, {1,5,8}, {1,8,18}  // Brute
        };


        // Clauses assignment
        vector<int> cyber_clause = {0,1,4,7,10,11,18,19,20};
        vector<int> malware_clause = {0,7,12,13,14,15,16};
        vector<int> phishing_clause = {0,1,2,3,4,5,16,20};
        vector<int> ddos_clause = {0,6,7,8,9,10};
        vector<int> man_in_the_middle_clause = {0,4,5,6,7,8,18};
        vector<int> brute_force_clause = {0,1,2,4,5,8,18,19};

        vector<vector<int>> clause_index =  {cyber_clause, malware_clause, phishing_clause, ddos_clause, 
                                                       man_in_the_middle_clause, brute_force_clause};
        

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
