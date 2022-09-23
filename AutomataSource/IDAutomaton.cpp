#include "AutomataHeaders/IDAutomaton.h"

void IDAutomaton::S0(const std::string& input) {
    if (isalpha(input[index])) {
//        std::cout << "ID.S0 detected \'" << input[index] << "\' to be a letter" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else {
//        std::cout << "ID.S0 did not detect \'" << input[index] << "\' to be a letter" << std::endl;
        Serr();
    }
}

void IDAutomaton::S1(const std::string& input) {
    if (isalpha(input[index]) || isdigit(input[index])) {
//        std::cout << "ID.S1 detected \'" << input[index] << "\' to be a letter/digit" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else {
//        std::cout << "ID.S1 did not detect \'" << input[index] << "\' to be a letter/digit" << std::endl;
//        Serr();
    }
}