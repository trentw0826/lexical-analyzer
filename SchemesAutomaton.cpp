#include "SchemesAutomaton.h"

void SchemesAutomaton::S0(const std::string& input) {
    if (input[index] == 'S') {
//        std::cout << "SCHEMES detects an 'S'" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S1(const std::string& input) {
    if (input[index] == 'c') {
//        std::cout << "SCHEMES detects an 'c'" << std::endl;
        inputRead++;
        index++;
        S2(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S2(const std::string& input) {
    if (input[index] == 'h') {
//        std::cout << "SCHEMES detects an 'h'" << std::endl;
        inputRead++;
        index++;
        S3(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S3(const std::string& input) {
    if (input[index] == 'e') {
//        std::cout << "SCHEMES detects an 'e'" << std::endl;
        inputRead++;
        index++;
        S4(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S4(const std::string& input) {
    if (input[index] == 'm') {
        inputRead++;
        index++;
        S5(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S5(const std::string& input) {
    if (input[index] == 'e') {
        inputRead++;
        index++;
        S6(input);
    }
    else {
        Serr();
    }
}

void SchemesAutomaton::S6(const std::string& input) {
    if (input[index] == 's') {
//        std::cout << "...SCHEMES detects an 's'" << std::endl;
//        std::cout << "Schemes token should be validated" << std::endl;
        inputRead++;
    }
    else {
        Serr();
    }
}