#include <iostream>
#include "BackwardRules.h"
using namespace std;

int main() {
    cout << "Hello welcome to the Network Diagnosis Test!" << endl;
    cout << "Please answer the following statements with a 'y' for yes, or a 'n' for no.\n\n";

    BackwardRules network_troubleshoot = BackwardRules();

    network_troubleshoot.start_iteration();
}
