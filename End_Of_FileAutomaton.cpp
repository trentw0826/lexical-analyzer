#include "End_Of_FileAutomaton.h"

void End_Of_FileAutomaton::S0(const std::string& input) {
    if (input.empty()) {
        inputRead = 1;
    }
    else {
        Serr();
    }
}