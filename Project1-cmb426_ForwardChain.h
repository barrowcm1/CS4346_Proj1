#ifndef _FORWARD_CHAIN_
#define _FORWARD_CHAIN_
#include <vector>
#include <iostream>
using namespace std;

class ForwardChain{

    public:

        vector<string>clause_variable_list = {"Information Leakage", "Random Demands", "Repeated Login Attempts",
                                              "Password Dictionary Attacks", "Unexpected Crash", "Evidence of Data Theft", "Modified IP Address",
                                              "Redirected Internet Website", "Suspcious Traffic", "Flooded Traffic", "Unsolicited Attachments", "Emails From Unknown Senders"

        };

        vector<string>treatment_list = {"Contain the Cyber Breach", "Disable Remote Access",
                                        "Change all passwords", "Lock an Account After a Certain Number of Times",
                                        "Scan and Clean Computer", "Seek Professional Help", "Get a VPN", 
                                        "Set up a Strong WEP?WAP Encryption", "Patch the Server", "Put Authentication Logger Firewall",
                                        "Block Popups and ADS", "Report Phishing Attempts"


        };

        vector<string> diagnosis_list = {"Cyber Attack", "Malware Attack", "DDoS Attack", "Phishing Attack", "Man-in-the-Middle Attack", "Brute Force Attack"};    

        vector<pair<string, string>>variable_initialized_list = variable_initializer(clause_variable_list);

        vector<pair<string, string>>variable_initializer(vector<string> variable_list) {
            vector<pair<string, string>>temp_var_initializer;

            for(string variable : variable_list)
            {
                pair<string, string> temp_pair = make_pair(variable, "");
                temp_var_initializer.push_back(temp_pair);
            }
            return temp_var_initializer;
        };

        vector<pair<int, vector<int>>>diagnosis_condition = {{0,{0,1}}, {1,{4,5}}, {2,{8,9}}, {3,{10,11}}, {4,{6,7}}, {5,{2,3}}};

        vector<vector<string>> ailment_condition = { {"INFO", "RANDOM"}, {"LOGIN", "REDUCED"}, {"CRASH", "THEFT"}, {"MODIFIED", "REDIRECTED"}, {"FLOODED", "TRAFFIC"}, {"ATTACH", "UNKNOWN"} };

         vector<pair<vector<string>, string>> ailment_condition_treatment = {
        {{clause_variable_list[0], "INFO"}, "Containing the Cyber Breach"}, {{clause_variable_list[1], "RANDOM"}, "Disabling Remote Access"}, 
        {{clause_variable_list[2], "LOGIN"}, "Change all passwords"}, {{clause_variable_list[3], "REDUCED"}, "Locking an Account After a Certain Number of Times"}, 
        {{clause_variable_list[4], "CRASH"}, "Scanning and Cleaning the Computer"}, {{clause_variable_list[5], "THEFT"}, "Seeking Professional Help"}, 
        {{clause_variable_list[6], "MODIFIED"}, "Getting a VPN"}, {{ clause_variable_list[7], "REDIRECTED"}, "Setting up a Strong WEP?WAP Encryption"}, 
        {{clause_variable_list[8], "FLOODED"}, "Patching the Server"}, {{clause_variable_list[9], "TRAFFIC"}, "Putting up an Authentication Logger Firewall"},
        {{clause_variable_list[10], "ATTACH"}, "Blocking Popups and ADS"}, {{clause_variable_list[11], "UNKNOWN"}, "Reporting Phishing Attempts"} };


};

#endif
