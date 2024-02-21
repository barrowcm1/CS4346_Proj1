#ifndef _FORWARD_RULES_
#define _FORWARD_RULES_

#include <iostream>
#include <queue>
#include "ForwardChain.h"
using namespace std;

class ForwardRules{
public:
    string diagnosis;

    queue<pair<string, string>>variable_initialized_queue;

    ForwardChain chain_forward = ForwardChain();

    void initialize_condition(int diagnosis_index) {
        
        for(auto diagnosis_condition_pair : chain_forward.diagnosis_condition) 
        {
            if(diagnosis_index == diagnosis_condition_pair.first)
            {
                vector<int> condition_index = diagnosis_condition_pair.second;
                // we are initializing the conditions or clause_variable based on diagnosis
                
                for(auto condition_number : condition_index) 
                {
                    chain_forward.variable_initialized_list[condition_number].second = chain_forward.ailment_condition[diagnosis_index][condition_number];    
                    variable_initialized_queue.push(chain_forward.variable_initialized_list[condition_number]);
                }       
            } 
        }
        // Calls a function that goes through the queue we just enqueued
        apply_forward_chain(variable_initialized_queue);
    }

    void apply_forward_chain(queue<pair<string, string>>variables_initialized_queue)
    {    
        while ( !variables_initialized_queue.empty())
        {
        pair<string, string> variable = variables_initialized_queue.front();
        variables_initialized_queue.pop();
            
        // Check the value of pair in the knowlege base conditions_treatment to suggest a solution
            
            for (auto ailment_condition_treat : chain_forward.ailment_condition_treatment)
            {
                vector<string> ailment_condition = ailment_condition_treat.first;
                
                if(variable.first == ailment_condition[0]) 
                {
                    string output_print = "\n\nThis might have been caused by " + variable.first;
                    string treatment_print = "\nPrevent " + variable.first + " by " + ailment_condition_treat.second;
                    
                    cout << output_print << endl;
                    cout << treatment_print << endl;
                }
            }
        }
    }
    
    int end_program() // Quits the program 
    {
        cout << "\n\nThank you for using this program!\n";
        exit(0);
    }

public:
    ForwardRules(string diagnosis)
    {
        this->diagnosis = diagnosis;
    };
    
    void initialize_forward_rule()
    {    
        int diagnosis_index = 0;
        for(int i = 0; i < chain_forward.diagnosis_list.size(); i++ )
        {
            if (chain_forward.diagnosis_list[i] == this->diagnosis)
            {
                diagnosis_index = i;
                break;
            }
        }   
        initialize_condition(diagnosis_index);
        end_program();
    }
};

#endif
