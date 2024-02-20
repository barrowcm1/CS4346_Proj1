#include <vector>
#include <iostream>
#include <stack>
#include <map>
#include <unordered_map>
#include "Knowledge.h"
#include "ForwardRules.h"
using namespace std;

class BackwardRules{

    public:
        BackwardRules()
        {
        };

    private:
        string final_result = "";
        // Maximum number of rules used for the program is max 30
        vector<int>rule_number = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
                                  16, 17,18,19,20,21,22,23,24,25,26,27,28,29,30};
        
        vector<int> diagnosis_index = {0,0,0,1,1,5,5,2,2,5,1,1,1,2,2,2,5,5,2,0,0,2,2,1,0,0,2,0,2,0,3,3,3,3,2,0};

        // Combinations that will lead to solution of a(n) attack
        vector<vector<int>>troubleshoot_combinations = {
            {0,4,7}, {0,4,10}, {0,4,11}, {0,1,10}, {0,1,11}, //CyberAttack
            {0,4,12}, {0,7,13}, {0,7,14}, {0,7,15}, {0,7,16}, // Malware
            {0,7,8}, {0,7,9}, {0,7,10}, {0,6,7}, {0,6,8}, // DDoS
            {1,2,3}, {0,1,2}, {0,4,5}, {0,1,5}, {1,3}, // Phishing
            {0,5,6}, {0,4,8}, {0,4,18}, {0,5,8}, {0,5,18}, // MitM
            {0,2,4}, {0,2,5}, {1,2,4}, {1,5,8}, {1,8,18}  // Brute
        };

        // Function declarations
        map<int, vector<int>>rule_symptoms = initialize_troubleshoot_symptoms(rule_number, troubleshoot_combinations);
        vector<pair<int, string>>conclusion_list = initialize_conclusion_list(30);
        stack<pair<int, int>>conclusion_stack = initialize_stack();

        vector<pair<int, string>>visitied_conclusion_list;

        // This will initialize the troubleshoot symptoms map
        map<int, vector<int>>initialize_troubleshoot_symptoms(vector<int> rules, vector<vector<int>> symptoms) 
        {
            map<int, vector<int>> rule_symptoms;

            if(rules.size() != symptoms.size()) 
            {
                cout << "Rules and symptoms mismatch. Check the data again." << endl;
            }
            for(int i = 0; i < rules.size(); i++)
            {
                rule_symptoms[rules[i]] = symptoms[i];
            }
            return rule_symptoms;
        }

        // This will initialize the conclusion list
        vector<pair<int, string>>initialize_conclusion_list(int numRules)
        {
            vector<pair<int, string>> rules_conclusions;

            for(int i = 1; i <= numRules; i++)
            {
                pair<int, string> tempPair;
                tempPair = make_pair(i, "diagnosis");
                rules_conclusions.push_back(tempPair);
            }
            return rules_conclusions;
        }

        // Stack to keep track of what rule to go to next
        stack<pair<int, int>>initialize_stack()
        {
            stack<pair<int, int>>conclusion_stack;
            conclusion_stack.push(make_pair(1,0)); //
            return conclusion_stack;
        }

        Knowledge_base current_knowledge = Knowledge_base();
        // end of private mathods
        public:

            pair<int, int> check_conclusion_stack()
            {
                if(conclusion_stack.empty())
                {
                    conclusion_stack.push(make_pair(1,0));
                }
                return conclusion_stack.top();
            }

            void start_iteration() 
            {
                string user_input;
                int input_value;

                pair<int, int> rule_to_process = check_conclusion_stack();

                int variable_index = rule_to_process.second;

                while((user_input != "Y") && (user_input != "N") && (user_input != "y") && (user_input != "n"))
                {
                    string status = current_knowledge.variables[variable_index];
                    printf("%s?  enter: Y/N\n", status.c_str());
                    cin >> user_input;
                }

                if(user_input == "y" or user_input == "Y")
                {
                    input_value = 1;
                    // converts a yes into a 1
                }
                else
                {
                    input_value = 0;
                    // converts a no into a 0
                }
                updateResponse(input_value, variable_index);
            }

            void updateResponse(int variable_value, int variable_position)
            // Updates the response given by start_iteration
            {
                current_knowledge.variable_initialized[current_knowledge.variables[variable_position]] = variable_value;

                pair<int, int> rule_to_process = check_conclusion_stack();

                int rule_num_to_process = rule_to_process.first;
                processResponse(rule_num_to_process);
            }
            
            void processResponse(int rule_num_to_process)
            {
                // Function will check the rules_symptoms map and determine if all symptoms are initialized.
                // If they are a diagnosis can be made and will end program, otherwise continue to initialize 
                // Variables until a decision can be made. Updates the stack 
                int next_rule = -1;
                vector<int>symptoms_for_rule = rule_symptoms[rule_num_to_process];

                for(int symptom : symptoms_for_rule)
                {
                    if(current_knowledge.variable_initialized[current_knowledge.variables[symptom]] == 0)
                    // If the value is 0, this means the result is false.
                    // Check the next set of rules and remove top from the stack
                    {
                        visitied_conclusion_list.push_back({rule_num_to_process, "result"});
                        conclusion_stack.pop();

                        next_rule = (rule_num_to_process + 1);

                        if(next_rule > rule_number[rule_number.size() - 1])
                        {
                            // We did not find a result at the end.
                            cout << "Diagnosis was not possible at this time. Please try again" << endl;
                        }
                        vector<int>next_set_of_symptoms = rule_symptoms[next_rule];

                        conclusion_stack.push({next_rule, next_set_of_symptoms[0]});
                        processResponse(next_rule);
                    }
                    else if(current_knowledge.variable_initialized[current_knowledge.variables[symptom]] == -1)
                    // If the value is -1, this means that the rule has not been fuly processed
                    // This will continue to proceed until all variables are initialized to reach conclusion
                    {
                        next_rule = rule_num_to_process;
                        conclusion_stack.pop();
                        conclusion_stack.push({next_rule, symptom});
                        start_iteration();
                    }
                }
                if(next_rule == -1)
                {
                    cout << "You are experiencing the following symptoms:" << endl;

                    for(auto each_symptom : rule_symptoms[rule_num_to_process])
                    {
                        string symptom_description = current_knowledge.variables[each_symptom];
                        printf("%s\n", symptom_description.c_str());
                    }
                    final_result = current_knowledge.conclusions[diagnosis_index[(rule_num_to_process / 1) - 1]];

                    cout << "\n\nYou might be suffering from a " << final_result << ". Please perform appropriate troubleshooting tips to confirm and treat for the condition.\n\n";
                    endProgram();
                }
            }

            // This will terminate the program once the result has been given
            void endProgram()
            {
                ForwardRules troubleshoot = ForwardRules(getDiagnosis());
                
                if(this-> getDiagnosis() == "")
                {   
                    // Will end the program prematurely if the troubleshoot can not be found
                    troubleshoot.end_program();
                }
                else
                {
                    troubleshoot.initialize_forward_rule();
                }
            }


            // this will be called by the ForwardChain to recommned the proper troubleshoot advice
            string getDiagnosis()
            {
                return this->final_result;
            }

};
