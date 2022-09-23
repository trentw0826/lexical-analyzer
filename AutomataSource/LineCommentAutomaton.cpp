#include "AutomataHeaders/LineCommentAutomaton.h"

void LineCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void LineCommentAutomaton::S1(const std::string& input) {
    if(input[index] == '|' && index == 1){ //This is the start of a block comment, not a line comment
        Serr();
    }
    else if (input[index] != '\n' && !checkEOF(input)) {
        inputRead++;
        index++;
        S1(input);
    }
}