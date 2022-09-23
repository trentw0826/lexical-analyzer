#include "LineCommentAutomaton.h"

void LineCommentAutomaton::S0(const std::string& input) {
    if (input[index] == '#') {
        std::cout << "LINECOMMENT.S0 has detected the start of a comment" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}

void LineCommentAutomaton::S1(const std::string& input) {
    if (input[index] != '\n' && input[index] != 0) {
        std::cout << "LINECOMMENT.S1 has detected another comment character" << std::endl;
        inputRead++;
        index++;
        S1(input);
    }
    else {
        std::cout << "LINECOMMENT.S1 has detected the end of a valid comment" << std::endl;
    }
}