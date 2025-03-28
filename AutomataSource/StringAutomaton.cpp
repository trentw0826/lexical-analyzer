#include "AutomataHeaders/StringAutomaton.h"

void StringAutomaton::S0(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void StringAutomaton::S1(const std::string& input) {
    if(checkEOF(input)){
        this->type = TokenType::UNDEFINEDSTR;
    }
    else if (input[index] != '\'') {
        checkNewLine(input[index]);
        inputRead++;
        index++;
        S1(input);
    }
    else if (input[index] == '\''){
        inputRead++;
        index++;
        S2(input);
    }
}

void StringAutomaton::S2(const std::string& input) {
    if (input[index] == '\'') {
        inputRead++;
        index++;
        S1(input);
    }
}